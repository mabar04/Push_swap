
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_node
{
    int data;
    int index;
    struct s_node *next;
    struct s_node *previous;
} t_node;

typedef struct s_stack
{
    t_node *top;
    t_node *bottom;
    size_t size; 

}t_stack;

int	ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *str);
void initialise_stack(t_stack *stack,char **argv);
char	**ft_split(const char *s, char c);
int isint(const char *s);
int	ft_atoi(const char *nptr);
void push_swap(t_stack *a,t_stack *b);
t_stack *createstack();
int stacksorted(t_stack *a);
#endif