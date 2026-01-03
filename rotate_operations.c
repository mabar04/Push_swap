#include "push_swap.h"

static void rotate_algo(t_stack *a)
{
    t_node *topnode;

    if(!a || a->size < 2)
        return;
    topnode = a->top;
    a->top = a->top->next;
    a->top->previous = NULL;
    topnode->previous = a->bottom;
    a->bottom->next = topnode;
    a->bottom = topnode;
    topnode->next = NULL;
}
void ra(t_stack *a)
{
    rotate_algo(a);
    write(1,"ra\n",3);
}
void rb(t_stack *a)
{
    rotate_algo(a);
    write(1,"rb\n",3);
}
void rr(t_stack *a,t_stack *b)
{
    rotate_algo(a);
    rotate_algo(b);
    write(1,"rr\n",3);
}