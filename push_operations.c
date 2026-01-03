#include "push_swap.h"

static void push_algo(t_stack *a,t_stack *b)
{
    t_node *tmp;

    if(!a || !b || b->size == 0)
        return;
    tmp = b->top;
    if(b->size == 1)
        b->top=b->bottom=NULL;
    else
    {
        b->top = b->top->next;
        b->top->previous = NULL;
    }
    b->size--;
    tmp->previous = NULL;
    tmp->next = a->top;
    if(a->size == 0)
        a->top = a->bottom = tmp;
    else
    {
        a->top->previous = tmp;
        a->top = tmp;
    }
    a->size++;
}
void pa(t_stack *a,t_stack *b)
{
    push_algo(a,b);
    write(1,"pa\n",3);
    return;
}
void pb(t_stack *a,t_stack *b)
{
    push_algo(b,a);
    write(1,"pb\n",3);
    return;
}
