#include "push_swap.h"

void sort_3(t_stack *a)
{
    if(a->top > a->top->next)
        sa(a);
    if(a->top > a->bottom)
        rra(a);
    return;
}