#include "push_swap.h"

static t_node *maxnode_calc(t_stack *b)
{
    t_node *tmp;
    t_node *maxnode;

    tmp = b->top;
    maxnode = tmp;
    while(tmp != NULL)
    {
        if(maxnode->index < tmp->index)
            maxnode = tmp;
        tmp = tmp->next;
    }
    return (maxnode);
}
static void rotateb(t_stack *b, t_node *max)
{
    t_node *tmp;
    int topdistance;
    int bottomdistance;

    tmp = b->top;
    topdistance = 0;

    while (tmp)
    {
        if (tmp == max)
            break;
        tmp = tmp->next;
        topdistance++;
    }

    bottomdistance = b->size - topdistance;

    if (topdistance <= bottomdistance)
    {
        while (topdistance-- > 0)
            rb(b);
    }
    else
    {
        while (bottomdistance-- > 0)
            rrb(b);
    }
}
void pullalggo(t_stack *a, t_stack *b)
{
    t_node *maxnode;

    while (b->size > 0)
    {
        maxnode = maxnode_calc(b);
        if (b->top->next && b->top->next->index == maxnode->index)
        {
            sb(b);
            pa(a, b);
            continue;
        }
        rotateb(b, maxnode);
        pa(a, b);
    }
}
