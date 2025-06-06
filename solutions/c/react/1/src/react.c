#include "react.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static void fire_trigger(struct trigger *t);

struct reactor *create_reactor()
{
    const int capacity = 100;
    struct reactor *result = malloc(sizeof(struct reactor) + sizeof(struct cell) * capacity);
    result->cells_capacity = capacity;
    result->cells_count = 0;
    result->triggers_count = 0;
    return result;
}

void destroy_reactor(struct reactor *r)
{
    free(r);
}

struct cell *create_input_cell(struct reactor *r, int initial_value)
{
    if (r->cells_count == r->cells_capacity)
    {
        r->cells_capacity *= 2;
        r = realloc(r, sizeof(struct reactor) + sizeof(struct cell) * r->cells_capacity);
    }

    struct cell *c = &r->cells[r->cells_count++];
    *c = (struct cell){
        .state = COMPLETE,
        .value = initial_value,
        .triggers_count = 0,
        .callbacks_count = 0,
    };

    return c;
}

int get_cell_value(struct cell *c)
{
    return c->value;
}

static void set_as_pending(struct cell *c)
{
    switch (c->state)
    {
    case UNINITALIZED:
        // Uninitialized state takes precedence
        return;
    case COMPLETE:
        c->state = PENDING;
        // Intentional fallthrough
    case PENDING:
        // Set all downstream cells as PENDING
        for (int i = 0; i < c->triggers_count; i++)
            set_as_pending(c->triggers[i]->output);
    }
}

void set_cell_value(struct cell *c, int new_value)
{

    switch (c->state)
    {
    case UNINITALIZED:
    {
        // Complete this cell
        c->value = new_value;
        c->state = COMPLETE;

        // Fire triggers
        for (int i = 0; i < c->triggers_count; i++)
            fire_trigger(c->triggers[i]);

        return;
    }
    case PENDING:
    case COMPLETE:
    {
        // Check to make sure the new value is actually a change
        int original_value = get_cell_value(c);
        if (new_value == original_value)
        {
            c->state = COMPLETE;
            return;
        }

        // Set cell and all downstream cells as PENDING
        set_as_pending(c);

        // Complete this cell
        c->value = new_value;
        c->state = COMPLETE;

        // Fire callbacks on update
        for (int i = 0; i < c->callbacks_count; i++)
        {
            callback cb = c->callbacks[i];
            void *args = c->callbacks_args[i];
            if (cb != NULL && args != NULL)
                cb(args, new_value);
        }

        // Fire triggers
        for (int i = 0; i < c->triggers_count; i++)
            fire_trigger(c->triggers[i]);

        return;
    }
    }
}

static void fire_trigger(struct trigger *t)
{
    switch (t->variant)
    {
    case COMPUTE_1:
    {
        if (t->input_a->state == UNINITALIZED || t->input_a->state == PENDING)
            return;

        int new_value = t->compute_1(get_cell_value(t->input_a));

        if (t->output->state == UNINITALIZED)
            set_cell_value(t->output, new_value);

        int original_value = get_cell_value(t->output);
        if (new_value != original_value)
            set_cell_value(t->output, new_value);

        return;
    }
    case COMPUTE_2:
    {
        // If any of the input cells are PENDING, NOOP to avoid excessive invocations
        if (t->input_a->state == UNINITALIZED ||
            t->input_b->state == UNINITALIZED ||
            t->input_a->state == PENDING ||
            t->input_b->state == PENDING)
            return;

        int new_value = t->compute_2(get_cell_value(t->input_a), get_cell_value(t->input_b));

        switch (t->output->state)
        {
        case UNINITALIZED:
        { // If the output cell hasn't yet been initialized, set value
            set_cell_value(t->output, new_value);
            return;
        }
        case PENDING:
        { // If an update, only actually update if there is a change
            int original_value = get_cell_value(t->output);
            if (new_value != original_value)
                set_cell_value(t->output, new_value);
            return;
        }
        case COMPLETE: // Unexpected varients
        default:
        {
            assert(0);
        }
        }
    }
    default: // Unexpected varients
        assert(0);
    }
}

struct cell *create_compute1_cell(struct reactor *r, struct cell *input_cell, compute1_t f)
{
    // Add cell in pending state
    struct cell *output_cell = &r->cells[r->cells_count++];
    *output_cell = (struct cell){
        .state = UNINITALIZED,
        .triggers_count = 0};

    // Add Trigger
    struct trigger *t = &r->triggers[r->triggers_count++];
    *t = (struct trigger){
        .variant = COMPUTE_1,
        .input_a = input_cell,
        .input_b = NULL,
        .output = output_cell,
        .compute_1 = f,
        .compute_2 = NULL};

    // Register Trigger with the input cells
    input_cell->triggers[input_cell->triggers_count++] = t;

    // Execute Trigger
    fire_trigger(t);

    return output_cell;
}

struct cell *create_compute2_cell(struct reactor *r, struct cell *input_cell_a, struct cell *input_cell_b, compute2_t f)
{
    assert(r != NULL);
    assert(input_cell_a != NULL);
    assert(input_cell_b != NULL);
    assert(f != NULL);

    // Add cell in pending state
    struct cell *output_cell = &r->cells[r->cells_count++];
    *output_cell = (struct cell){
        .state = UNINITALIZED,
        .triggers_count = 0};

    // Add Trigger
    struct trigger *t = &r->triggers[r->triggers_count++];
    *t = (struct trigger){
        .variant = COMPUTE_2,
        .input_a = input_cell_a,
        .input_b = input_cell_b,
        .output = output_cell,
        .compute_1 = NULL,
        .compute_2 = f};

    // Register Trigger with the input cells
    input_cell_a->triggers[input_cell_a->triggers_count++] = t;
    input_cell_b->triggers[input_cell_b->triggers_count++] = t;

    // Execute Trigger
    fire_trigger(t);

    return output_cell;
}

callback_id add_callback(struct cell *c, void *args, callback cb)
{
    callback_id id = c->callbacks_count;
    // printf("Setting id: %d on cell %p\n", id, (void *)c);
    c->callbacks[id] = cb;
    c->callbacks_args[id] = args;
    c->callbacks_count++;
    return id;
}

// We just zero out the cb, leaving a hole in the cb array
// This would have to be improved to be reused
void remove_callback(struct cell *c, callback_id id)
{
    c->callbacks[id] = NULL;
    c->callbacks_args[id] = NULL;
}