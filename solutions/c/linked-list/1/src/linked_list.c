#include "linked_list.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Private Headers
struct list_node *new_node(ll_data_t item_data);

// constructs a new list of items
struct list_node *new_node(ll_data_t item_data)
{
    struct list_node *new_node;
    if ((new_node = malloc(sizeof(struct list_node))) == NULL)
        return NULL;
    new_node->data = item_data;
    new_node->previous = NULL;
    new_node->next = NULL;
    return new_node;
}

// constructs a new list of items
struct list_item **new_list(void)
{
    struct list_item **new = malloc(sizeof(void *));
    *new = malloc(sizeof(struct list_item));
    (*new)->first = NULL;
    (*new)->last = NULL;
    return new;
}

// checks if the list is empty
bool is_list_empty(struct list_item **list)
{
    return list == NULL || *list == NULL || (*list)->first == NULL;
}

// inserts item at back of list
bool push(struct list_item **list, ll_data_t item_data)
{
    if (list == NULL || *list == NULL)
        return false;

    struct list_node *node;
    if ((node = new_node(item_data)) == NULL)
        return false;

    if ((*list)->first == NULL)
    {
        (*list)->first = node;
        (*list)->last = node;
    }
    else
    {
        (*list)->last->next = node;
        node->previous = (*list)->last;
        (*list)->last = node;
    }
    return true;
}

// removes item from back of list
ll_data_t pop(struct list_item **list)
{
    // per spec, ignoring error handling
    if (list == NULL || *list == NULL)
        return -1;

    struct list_node *node_to_delete = (*list)->last;
    ll_data_t output = node_to_delete->data;
    if ((*list)->first == node_to_delete)
        (*list)->first = NULL;
    (*list)->last = node_to_delete->previous;
    free(node_to_delete);
    return output;
}

// removes item from front of list
ll_data_t shift(struct list_item **list)
{
    if (list == NULL || *list == NULL)
        return -1;

    struct list_node *node_to_delete = (*list)->first;
    ll_data_t output = node_to_delete->data;
    if ((*list)->last == node_to_delete)
        (*list)->last = NULL;
    (*list)->first = node_to_delete->next;
    free(node_to_delete);
    return output;
}

// inserts item at front of list
bool unshift(struct list_item **list, ll_data_t item_data)
{
    if (list == NULL || *list == NULL)
        return false;

    struct list_node *node;
    if ((node = new_node(item_data)) == NULL)
        return false;

    if ((*list)->first == NULL)
    {
        (*list)->first = node;
        (*list)->last = node;
    }
    else
    {
        (*list)->first->previous = node;
        node->next = (*list)->first;
        (*list)->first = node;
    }
    return true;
}

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(struct list_item **list)
{
    if (list == NULL || *list == NULL)
        return;

    if ((*list)->last != NULL)
    {
        struct list_node *n = (*list)->last;
        while (n->previous != NULL)
        {
            n = n->previous;
            free(n->next);
        }
        free(n);
    }
    free(*list);
    free(list);
}