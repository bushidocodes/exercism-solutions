#include "linked_list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Private Headers
struct list_node *new_node(ll_data_t item_data);

// constructs a new list of items
struct list_node *new_node(ll_data_t item_data) {
	struct list_node *new_node;
	if ((new_node = malloc(sizeof(struct list_node))) == NULL) return NULL;
	new_node->data = item_data;
	new_node->previous = NULL;
	new_node->next = NULL;
	return new_node;
}

// constructs a new list of items
struct list *list_create(void) {
	return calloc(1, sizeof(struct list));
}

// counts the items on a list
size_t list_count(const struct list *list) {
	assert(list != NULL);

	size_t count = 0;
	if (list->first != NULL) {
		// count++;
		for (struct list_node *cursor = list->first; cursor != NULL;
		     cursor = cursor->next) {
			count++;
		}
	}

	return count;
}

// inserts item at back of list
void list_push(struct list *list, ll_data_t item_data) {
	assert(list != NULL);

	struct list_node *node = new_node(item_data);
	assert(node != NULL);
	node->data = item_data;

	if (list->first == NULL) {
		list->first = node;
		list->last = node;
	} else {
		list->last->next = node;
		node->previous = list->last;
		list->last = node;
	}
}

// removes item from back of list
ll_data_t list_pop(struct list *list) {
	assert(list != NULL);

	struct list_node *node_to_delete = list->last;
	ll_data_t output = node_to_delete->data;

	if (list->first == node_to_delete) list->first = NULL;
	list->last = node_to_delete->previous;
	if (list->last) list->last->next = NULL;

	free(node_to_delete);

	return output;
}

// removes item from front of list
ll_data_t list_shift(struct list *list) {
	assert(list != NULL);

	struct list_node *node_to_delete = list->first;
	ll_data_t output = node_to_delete->data;

	if (list->last == node_to_delete) list->last = NULL;
	list->first = node_to_delete->next;
	if (list->first) list->first->previous = NULL;

	free(node_to_delete);

	return output;
}

// inserts item at front of list
void list_unshift(struct list *list, ll_data_t item_data) {
	assert(list != NULL);

	struct list_node *node = new_node(item_data);
	assert(node != NULL);

	node->data = item_data;

	if (list->first == NULL) {
		list->first = node;
		list->last = node;
	} else {
		list->first->previous = node;
		node->next = list->first;
		list->first = node;
	}
}

// deletes a node that holds the matching data
void list_delete(struct list *list, ll_data_t data) {
	assert(list != NULL);

	for (struct list_node *cursor = list->first; cursor != NULL;
	     cursor = cursor->next) {
		if (cursor->data == data) {
			if (cursor == list->first) list->first = list->first->next;
			if (cursor == list->last) list->last = list->last->previous;
			if (cursor->previous != NULL) cursor->previous->next = cursor->next;
			if (cursor->next != NULL) cursor->next->previous = cursor->previous;
			free(cursor);

			return;
		}
	}
}

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void list_destroy(struct list *list) {
	assert(list != NULL);

	if (list->last != NULL) {
		struct list_node *n = list->last;
		while (n->previous != NULL) {
			n = n->previous;
			free(n->next);
		}
		free(n);
	}

	free(list);
}