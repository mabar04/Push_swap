/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 02:30:11 by mabar             #+#    #+#             */
/*   Updated: 2026/01/08 17:31:52 by mabar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	int				index;
	int				cost;
	int				a_cost;
	int				b_cost;
	int				total_cost;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*previous;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;

}					t_stack;

int					main(int argc, char **argv0);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
void				initialise_stack(t_stack **a, t_stack **b, char **argv);
char				**flatten(int ac, char **av);
int					isint(const char *s);
int					ft_atoi(const char *nptr);
void				push_swap(t_stack *a, t_stack *b);
t_stack				*createstack(void);
int					stacksorted(t_stack *a);
int					checknumbers(char **argv);
int					checkuniq(char **argv);
int					checkint(char **argv);
int					stacksorted(t_stack *a);
t_node				*createnode(int data);
void				sort_2(t_stack *a);
void				sort_3(t_stack *a);
void				sort_5(t_stack *a, t_stack *b);
void				sortalgo(t_stack *a, t_stack *b);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *a);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *a);
void				rrr(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				indexingstack(t_stack *a);
void				free_memory_main(char **s);
void				chunkalgo(t_stack *a, t_stack *b);
void				pull_phase(t_stack *a, t_stack *b);
void				free_stack(t_stack *stack);
void				calculate_costs(t_stack *a, t_stack *b);
void				execute_moves_combined(t_stack *a, t_stack *b,
						t_node *cheapest);
void				final_rotate(t_stack *a);
void				sort_array(int *i, t_stack *a, int *T);
void				indexing_helpp(t_node *tmp, t_stack *a, int *s);
char				*word_dup(char *s, int a, int b);
char				**split_one(char *s);
int					total_words(int ac, char **av);
int					word_count(char *s);
int					is_space(char c);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

char				*ft_strdup(char *s1);
size_t				ft_strlen_next(char *s);
size_t				ft_strlen_ln(char *s);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strjoin(char *s1, char *s2);
char				*get_next_line(int fd);
#endif
