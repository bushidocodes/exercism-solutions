#pragma once

#include <stdint.h>

#define MAX_CALLBACKS 100
#define MAX_TRIGGERS 100

enum cell_state { PENDING, COMPLETE, UNINITALIZED };

typedef void (*callback)(void *arg, int new_value);
typedef int callback_id;

struct cell {
	uint16_t callbacks_count;
	callback callbacks[MAX_CALLBACKS];    // Static to keep things simple
	void *callbacks_args[MAX_CALLBACKS];  // Static to keep things simple
	int value;
	enum cell_state state;
	uint16_t triggers_count;
	struct trigger *triggers[10];  // Fixed outdegree to simplify things
};

typedef enum trigger_varients {
	COMPUTE_1,
	COMPUTE_2,
	COMPUTE_VOID,
} trigger_variant_t;

typedef int (*compute1_t)(int);
typedef int (*compute2_t)(int, int);

struct trigger {
	trigger_variant_t variant;
	compute1_t compute_1;
	compute2_t compute_2;
	struct cell *input_a;
	struct cell *input_b;
	struct cell *output;
};

struct reactor {
	uint16_t triggers_count;
	struct trigger triggers[MAX_TRIGGERS];  // Static to keep things simple
	uint16_t cells_capacity;
	uint16_t cells_count;
	struct cell cells[];
};

struct reactor *create_reactor();
// destroy_reactor should free all cells created under that reactor.
void destroy_reactor(struct reactor *);

struct cell *create_input_cell(struct reactor *, int initial_value);

struct cell *create_compute1_cell(struct reactor *, struct cell *, compute1_t);
struct cell *create_compute2_cell(struct reactor *, struct cell *,
                                  struct cell *, compute2_t);

int get_cell_value(struct cell *);
void set_cell_value(struct cell *, int new_value);

// The callback should be called with the same void * given in add_callback.
callback_id add_callback(struct cell *, void *arg, callback);
void remove_callback(struct cell *, callback_id);
