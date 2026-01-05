#include "push_swap.h"
static int still_in_chunk(t_stack *a, int chunkmin, int chunkmax)
{
    t_node *tmp = a->top;
    while (tmp)
    {
        if (tmp->index >= chunkmin && tmp->index <= chunkmax)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

// Find the cheapest node in current chunk
static t_node *find_cheapest(t_stack *a, int chunkmin, int chunkmax)
{
    t_node *tmp = a->top;
    t_node *best = NULL;
    int pos = 0;
    int best_cost = a->size + 1;
    int size = a->size;

    while (tmp)
    {
        if (tmp->index >= chunkmin && tmp->index <= chunkmax)
        {
            int cost = (pos <= size - pos) ? pos : size - pos;
            if (cost < best_cost)
            {
                best_cost = cost;
                best = tmp;
                best->cost = cost;
            }
        }
        tmp = tmp->next;
        pos++;
    }
    return best;
}

// Rotate A to bring the chosen node to top
static void rotate_to_node(t_stack *a, t_node *node)
{
    int pos = 0;
    t_node *tmp = a->top;

    if (a->top == node)
        return;
    while (tmp && tmp != node)
    {
        tmp = tmp->next;
        pos++;
    }
    if (pos <= a->size / 2)
        while (pos-- > 0)
            ra(a);
    else
    {
        pos = a->size - pos;
        while (pos-- > 0)
            rra(a);
    }
}

/* ---------------------- CHUNK PUSH ---------------------- */

void chunkalgo(t_stack *a, t_stack *b)
{
    int chunkmin = 0;
    int chunkmax;
    int chunksize;
    t_node *cheap;

    chunksize = 100;
    chunkmax = chunksize - 1;
    while (a->size > 3)
    {
        while (still_in_chunk(a, chunkmin, chunkmax) && a->size > 3)
        {
            cheap = find_cheapest(a, chunkmin, chunkmax);
            rotate_to_node(a, cheap);
            pb(a, b);
            int median = (chunkmin + chunkmax) / 2;
            if (b->top->index <= median && b->size > 1 && b->top->index != chunkmin)
                rb(b);
        }
        chunkmin += chunksize;
        chunkmax += chunksize;
    }
}


