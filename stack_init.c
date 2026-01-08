/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 02:30:05 by mabar             #+#    #+#             */
/*   Updated: 2026/01/08 17:31:40 by mabar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static int	handleallchecks(char **argv)
{
	if (!checknumbers(argv) || !checkint(argv) || !checkuniq(argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

static void	initialise_help(t_stack **a, t_stack **b, char **argv)
{
	t_node	*new;
	size_t	i;

	i = 0;
	while (argv[i])
	{
		new = createnode(ft_atoi(argv[i]));
		if (!new)
			return (free_stack(*a), free_stack(*b));
		if ((*a)->size == 0)
		{
			(*a)->top = new;
			(*a)->bottom = new;
		}
		else
		{
			(*a)->bottom->next = new;
			new->previous = (*a)->bottom;
			(*a)->bottom = new;
		}
		(*a)->size++;
		i++;
	}
}

void	initialise_stack(t_stack **a, t_stack **b, char **argv)
{
	if (!handleallchecks(argv))
		return ;
	*a = createstack();
	*b = createstack();
	if (!*a || !*b)
		return ;
	initialise_help(a, b, argv);
}

static void	indexing_help(t_node *tmp, int *T, t_stack *a)
{
	int	i;

	i = 0;
	while (tmp)
	{
		T[i++] = tmp->data;
		tmp = tmp->next;
	}
	i = 0;
	sort_array(&i, a, T);
}

void	indexingstack(t_stack *a)
{
	t_node	*tmp;
	int		*s;

	if (!a || a->size == 0)
		return ;
	s = malloc(sizeof(int) * a->size);
	if (!s)
		return ;
	indexing_help(a->top, s, a);
	tmp = a->top;
	indexing_helpp(tmp, a, s);
	free(s);
}
