
#include "push_swap.h"

t_stack *createstack()
{
    t_stack *a;
    
    a = (t_stack *)malloc(sizeof(t_stack));
    if(a == NULL)
        return (NULL);
    a->top = NULL;
    a->bottom = NULL;
    a->size = 0;
    return (a);
}

void freestack(t_stack *a,t_stack *b)
{
    
}