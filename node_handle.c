#include "push_swap.h"



t_node *createnode(int data)
{
    t_node *node;

    node = (t_node *) malloc (sizeof(t_node));
    if (node == NULL)
        return NULL;
    node->data = data;
    node->next = NULL;
    node->previous = NULL;
    return (node);
}