#include "push_swap.h"

void sort_2(t_stack *a)
{
    if(a->top->data > a->bottom->data)
        sa(a);
}
void sort_3(t_stack *a)
{
  int A;
  int B;
  int C;

  A = a->top->index;
  B = a->top->next->index;
  C = a->bottom->index;
  
if(A == 0 && B == 2 && C == 1)
{
  sa(a);
  ra(a);
}
else if(A == 1 && B == 0 && C == 2)
  sa(a);
else if(A == 1 && B == 2 && C ==0)
  rra(a);
else if(A == 2 && B == 0 && C == 1)
  ra(a);
else if(A == 2 && B == 1 && C == 0)
{
  sa(a);
  rra(a);
}
}

void sort_5(t_stack *a,t_stack *b)
{
  while (a->size > 3)
  {
    if(a->top->index == 0 || a->top->index == 1)
      pb(a,b);
    else
      ra(a);
  }
  sort_3(a);
  sort_2(b);
  pa(a,b);
  pa(a,b);
  if(a->top->index == 1 && a->top->next->index == 0)
    sa(a);
  return;
}
void sortalgo(t_stack *a,t_stack *b)
{

}
