
#include "push_swap.h"

void push_swap(t_stack *a,t_stack *b)
{
    if(stacksorted(a))
        return;
    if((a)->size == 2)
    {
        sort_2(a);
        return;
    }    
    if((a)->size == 3)
    {
        sort_3(a);
        return;
    }    
    if((a)->size <= 5)
    {
        sort_5(a,b);
        return;
    }   
    else
    {
        sortalgo(a,b);
        return;
    }
}

