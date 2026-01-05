#include "push_swap.h"

void sort_2(t_stack *a)
{
    if(a->top->data > a->bottom->data)
        sa(a);
}
void sort_3(t_stack *a)
{
  int A = a->top->index;
  int B = a->top->next->index;
  int C = a->bottom->index;

  if (A > B && B < C && A < C)
      sa(a);
  else if (A > B && B > C)
  {
    sa(a); 
    rra(a);
  }
  else if (A > B && B < C && A > C)
    ra(a);
  else if (A < B && B > C && A < C)
  {
    sa(a); 
    ra(a);
  }
  else if (A < B && B > C && A > C)
    rra(a);
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
  pa(a,b);
  pa(a,b);
  if(a->top->index == 1 && a->top->next->index == 0)
    sa(a);
  return;
}


void sortalgo(t_stack *a,t_stack *b)
{
  chunkalgo(a,b);
  sort_3(a);
  pull_phase(a,b);
}
