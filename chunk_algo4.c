#include "push_swap.h"


void execute_moves_combined(t_stack *a, t_stack *b, t_node *cheapest)
{
    while (cheapest->a_cost != 0 && cheapest->b_cost != 0 &&
          ((cheapest->a_cost > 0 && cheapest->b_cost > 0) ||
           (cheapest->a_cost < 0 && cheapest->b_cost < 0)))
    {
        if (cheapest->a_cost > 0)
        {
            rr(a, b);
            cheapest->a_cost--;
            cheapest->b_cost--;
        }
        else
        {
            rrr(a, b); 
            cheapest->a_cost++;
            cheapest->b_cost++;
        }
    }
    while (cheapest->a_cost != 0)
    {
        if (cheapest->a_cost > 0)
        {
            ra(a);
            cheapest->a_cost--;
        }
        else
        {
            rra(a);
            cheapest->a_cost++;
        }
    }
    while (cheapest->b_cost != 0)
    {
        if (cheapest->b_cost > 0)
        {
            rb(b);
            cheapest->b_cost--;
        }
        else
        {
            rrb(b);
            cheapest->b_cost++;
        }
    }
}

void final_rotate(t_stack *a)
{
    t_node *tmp;
    int pos;

    pos = 0;
    tmp = a->top;
    while(tmp->index != 0)
    {
        tmp = tmp->next;
        pos++;
    }
    if(pos <= a->size / 2)
    {
        while (pos > 0)
        {
            ra(a);
            pos--;
        }
    }
    else
    {
        pos = a->size - pos;
        while (pos > 0)
        {
            rra(a);
            pos--;
        }
    }
}