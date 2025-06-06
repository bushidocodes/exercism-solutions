#include "binary_search_tree.h"
#include <assert.h>
#include <stdlib.h>

static int buffer_capacity = 1000;
static int buffer_length = 0;
static int *buffer;

static node_t *node_init(int value)
{
    node_t *node = malloc(sizeof(node_t));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static node_t *add_child(node_t *parent, int value)
{
    if (parent == NULL)
        parent = node_init(value);
    else if (value <= parent->data)
        parent->left = add_child(parent->left, value);
    else
        parent->right = add_child(parent->right, value);

    return parent;
}

node_t *build_tree(int *tree_data, size_t tree_data_len)
{
    node_t *root = add_child(NULL, tree_data[0]);

    for (size_t i = 1; i < tree_data_len; i++)
        add_child(root, tree_data[i]);

    return root;
}
void free_tree(node_t *tree)
{
    if (tree == NULL)
        return;

    // free children
    if (tree->left != NULL)
        free_tree(tree->left);
    if (tree->right != NULL)
        free_tree(tree->right);

    // free self
    free(tree);
}

// Not threadsafe as written
static int sort(node_t *tree)
{
    int rc;

    if (tree == NULL)
        return 0;

    if (tree->left != NULL)
    {
        rc = sort(tree->left);
        if (rc == -1)
            return -1;
    }

    if (buffer_length + 1 == buffer_capacity)
        return -1;

    buffer[buffer_length++] = tree->data;

    if (tree->right != NULL)
    {
        rc = sort(tree->right);
        if (rc == -1)
            return -1;
    }

    return 0;
}

int *sorted_data(node_t *tree)
{
    // Reset Global State
    buffer_length = 0;
    buffer = calloc(buffer_capacity, sizeof(int));

    int rc = sort(tree);
    // There is no public API for the buffer being exceeded, so just crash!
    assert(rc != -1);
    return buffer;
}
