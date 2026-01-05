#include "push_swap.h"

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
        if( argv0[0] == NULL)
            return (write(2,"Error\n",6));
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
        free_memory_main(argv0);
}
