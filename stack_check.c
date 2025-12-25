
#include "push_swap.h"

int checknumbers(char **argv)
{
    size_t i;
    size_t j;

    i = 1;
    while (argv[i])
    {  
        j = 0;
        while (argv[i][j])
        {
            if((argv[i][j] == '-' || argv[i][j] == '+') && j == 0)
            {
                if (argv[i][j + 1] == '\0')
                    return (0);
                j++;
                continue;
            }
            if(argv[i][j] < '0' || argv[i][j] > '9')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
int checkuniq(char **argv)
{
    size_t i;
    size_t j;

    i = 1;
    while(argv[i])
    {
        j = i + 1;
        while (argv[j])
        {
            if(ft_atoi(argv[i]) == ft_atoi(argv[j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
int checkint(char **argv)
{
    size_t i;
    size_t j;

    i = 1;
    while(argv[i])
    {
        if (isint(argv[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}
int stacksorted(t_stack *a)
{
    t_node *tmp;

    tmp = a->top;
    while (tmp->next != NULL)
    {
        if(tmp->data > tmp ->next->data)
            return (0);
        tmp= tmp->next;
    }
    return (1);
}
