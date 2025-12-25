
#include "push_swap.h"

void sa_algo(t_stack *a)
{
     t_node *first;
    t_node *second;

    if(!a || a ->size < 2)
        return;
    first = a->top;
    second = first->next;
    first->next = second->next;
    if(second->next)
        second->next->previous = first;
    else
        a->bottom = first;
    first->previous = second;
    second->previous = NULL;
    second->next = first;
    a->top = second;
}
void sa(t_stack *a)
{
    sa_algo(a);
    return (write(1,"sa\n",3));
}

void sb(t_stack *b)
{
    sa_algo(b);
    return (write(1,"sb\n",3));
}

void ss(t_stack *a,t_stack *b)
{
    sa_algo(a);
    sa_algo(b);
    return (write(1,"ss\n",3));
}
