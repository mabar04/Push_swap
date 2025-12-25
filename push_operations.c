#include "push_swapp.h"

void push_algo(t_stack *a,t_stack *b)
{
    t_node *tmp;

    if(!b || b->size == 0)
        return;
    tmp = b->top;
    b->top = b->top->next;
    b->top->previous = NULL;
    
}