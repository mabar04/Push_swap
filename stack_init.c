#include "push_swap.h"

static int handleallchecks(char **argv)
{
    if(!checknumbers(argv))
        return (0);
    if(!checkint(argv))
        return (0);
    if(!checkuniq(argv))
        return (0);
    return (1);
}
void initialise_stack(t_stack **a,t_stack **b,char **argv)
{
    size_t i;
    t_node *new;

    i = 1;
    if (!handleallchecks(argv))    
    {   
        ft_printf("Error\n");
        return;
    }
    *a = createstack();
    *b= createstack();
    while(argv[i])
    {
        new = createnode(ft_atoi(argv[i]));
        if(!new)
            return ;
        if((*a)->size == 0)
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
    return;
}
void indexingstack(t_stack **a)
{
    t_node *tmp;
    int *T;
    int i;
    int j;
    int k;

    i = 0;
    tmp = (*a)->top;
    T = malloc(sizeof(int) * (*a)->size);
    while (tmp != NULL)
    {
        T[i] = tmp->data;
        i++;
        tmp = tmp->next;
    }
    i = 0;
    while (i < (*a)->size)
    {
        j = i + 1;
        while (j < (*a)->size)
        {
            if(T[i] > T[j])
            {
                k = T[i];
                T[i] = T[j];
                T[j] = k;
            }
            j++;
        }
        i++;
    }
    tmp = (*a)->top;
    while(tmp != NULL)
    {
        i = 0;
        while (i < (*a)->size)
        {
            if(T[i] == tmp->data)
            {
                tmp->index = i;
                break;
            }
            i++;
        }
        tmp = tmp->next;
    }
    free(T);
}
