#include "circular_buffer.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

circular_buffer_t *new_circular_buffer(size_t capacity)
{
    circular_buffer_t *result = calloc(1, sizeof(circular_buffer_t));
    result->capacity = capacity;
    result->data = calloc(capacity, sizeof(buffer_value_t));
    result->is_full = false;
    return result;
}

CB_RC read(circular_buffer_t *buffer, buffer_value_t *read_value)
{
    if (buffer->start == buffer->end && !buffer->is_full)
    {
        errno = ENODATA;
        return CB_FAILURE;
    }

    *read_value = buffer->data[buffer->start];
    buffer->start = (buffer->start + 1) % buffer->capacity;
    if (buffer->is_full == true)
        buffer->is_full = false;
    return CB_SUCCESS;
}

CB_RC write(circular_buffer_t *buffer, buffer_value_t write_value)
{
    if (buffer->start == buffer->end && buffer->is_full)
    {
        errno = ENOBUFS;
        return CB_FAILURE;
    }

    buffer->data[buffer->end] = write_value;
    buffer->end = (buffer->end + 1) % buffer->capacity;
    if (buffer->end == buffer->start)
        buffer->is_full = true;
    return CB_SUCCESS;
}

CB_RC overwrite(circular_buffer_t *buffer, buffer_value_t write_value)
{
    // overwrite oldest value if full
    if (buffer->start == buffer->end && buffer->is_full)
    {
        buffer->data[buffer->end] = write_value;
        buffer->end = (buffer->end + 1) % buffer->capacity;
        buffer->start = (buffer->start + 1) % buffer->capacity;
        return CB_SUCCESS;
    }

    return write(buffer, write_value);
}

void clear_buffer(circular_buffer_t *buffer)
{
    memset(buffer->data, 0, sizeof(buffer_value_t) * buffer->capacity);
    buffer->is_full = false;
    buffer->start = 0;
    buffer->end = 0;
}

void delete_buffer(circular_buffer_t *buffer)
{
    free(buffer->data);
    free(buffer);
}