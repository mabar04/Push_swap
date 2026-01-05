#include "push_swap.h"

void free_stack(t_stack *stack)
{
    t_node *tmp;
    t_node *next;

    if (!stack)
        return;

    tmp = stack->top;
    while (tmp)
    {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(stack);
}
void	free_memory_main(char **s)
{
    int i;

    i = 0;
    while(s[i])
    {
        i++;
    }
    while (i > 0)
		free(s[--i]);
	free(s);
}
