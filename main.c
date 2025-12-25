
#include "push_swap.h"

int main(int argc,char **argv0)
{
    t_stack a;
    t_stack b;
    char **argv;

    a = NULL;
    b = NULL;
    if (argc < 2)
        return (1);
    if (argc > 2)
        initialise_stack(&a,&b,argv0);
    if (argc == 2)
    {
        argv = ft_split(argv0,' ');
        initialise_stack(&a,&b,argv);
    }
    if (a == NULL)
        return (2);
    push_swap(&a,&b);
}
