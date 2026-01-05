#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

/* Check all input */
static int handleallchecks(char **argv)
{
    if (!checknumbers(argv) || !checkint(argv) || !checkuniq(argv))
    {
        write(2, "Error\n", 6);
        return 0;
    }
    return 1;
}

/* Initialise stack A and B */
void initialise_stack(t_stack **a, t_stack **b, char **argv)
{
    size_t i;
    t_node *new;

    if (!handleallchecks(argv))
        return;
    i = 0;
    *a = createstack();
    *b = createstack();
    if (!*a || !*b)
        return;
    while (argv[i])
    {
        new = createnode(ft_atoi(argv[i]));
        if (!new)
        {
            free_stack(*a);
            free_stack(*b);
            return;
        }
        if ((*a)->size == 0)
            (*a)->top = (*a)->bottom = new;
        else
        {
            (*a)->bottom->next = new;
            new->previous = (*a)->bottom;
            (*a)->bottom = new;
        }
        (*a)->size++;
        i++;
    }
}

/* Helper to index stack safely */
static void indexing_help(t_node *tmp, int *T, t_stack *a)
{
    int i, j, k;

    /* Copy stack data into array */
    i = 0;
    while (tmp)
    {
        T[i++] = tmp->data;
        tmp = tmp->next;
    }

    /* Simple bubble sort */
    for (i = 0; i < a->size - 1; i++)
    {
        for (j = i + 1; j < a->size; j++)
        {
            if (T[i] > T[j])
            {
                k = T[i];
                T[i] = T[j];
                T[j] = k;
            }
        }
    }
}

/* Index the stack nodes */
void indexingstack(t_stack *a)
{
    t_node *tmp;
    int *T;
    int i;

    if (!a || a->size == 0)
        return;
    T = malloc(sizeof(int) * a->size);
    if (!T)
        return;

    indexing_help(a->top, T, a);
    tmp = a->top;
    while (tmp)
    {
        for (i = 0; i < a->size; i++)
        {
            if (T[i] == tmp->data)
            {
                tmp->index = i;
                break;
            }
        }
        tmp = tmp->next;
    }
    free(T);
}
