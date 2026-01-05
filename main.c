#include "push_swap.h"
#include <stdio.h>

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
static void	free_memory(char **s)
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
void print_stack_index(t_stack *a)
{
    t_node *tmp = a->top;
    while(tmp)
    {
        printf("%d\n", tmp->index);
        tmp = tmp->next;
    }
}
int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    char    **argv0;

    if (argc < 2)
        return (1);
    a = NULL;
    b = NULL;
    argv0 = NULL;
    if (argc == 2)
    {
        argv0 = ft_split(argv[1], ' ');
        if (!argv0)
            return (1);
        initialise_stack(&a, &b, argv0);
    }
    else
    {
        argv++;
        initialise_stack(&a, &b, argv);
    }
    if (!a)
        return (2);
    indexingstack(a);
    //print_stack_index(a);
    push_swap(a,b);
    free_stack(a);
    free_stack(b);
    if(argv0)
        free_memory(argv0);
}
