/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:31:37 by mabar             #+#    #+#             */
/*   Updated: 2026/01/08 17:31:37 by mabar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	still_in_chunk(t_stack *a, int chunkmin, int chunkmax)
{
	t_node	*tmp;

	tmp = a->top;
	while (tmp)
	{
		if (tmp->index >= chunkmin && tmp->index <= chunkmax)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static	void	find_helper(t_node *tmp, t_stack *a, t_node *best)
{
	int		pos;
	int		best_cost;
	int		cost;

	pos = 0;
	best_cost = a->size + 1;
	while (tmp)
	{
		if (tmp->index >= 0 && tmp->index <= a->size)
		{
			if (pos <= a->size - pos)
				cost = pos;
			else
				cost = a->size - pos;
			if (cost < best_cost)
			{
				best_cost = cost;
				best = tmp;
				best->cost = cost;
			}
		}
		tmp = tmp->next;
		pos++;
	}
}

static t_node	*find_cheapest(t_stack *a)
{
	t_node	*tmp;
	t_node	*best;

	tmp = a->top;
	best = NULL;
	find_helper(tmp, a, best);
	return (best);
}

static void	rotate_to_node(t_stack *a, t_node *node)
{
	int		pos;
	t_node	*tmp;

	pos = 0;
	tmp = a->top;
	if (a->top == node)
		return ;
	while (tmp && tmp != node)
	{
		tmp = tmp->next;
		pos++;
	}
	if (pos <= a->size / 2)
		while (pos-- > 0)
			ra(a);
	else
	{
		pos = a->size - pos;
		while (pos-- > 0)
			rra(a);
	}
}

void	chunkalgo(t_stack *a, t_stack *b)
{
	int		chunkmin;
	int		chunkmax;
	int		chunksize;
	t_node	*cheap;
	int		median;

	chunkmin = 0;
	chunksize = a->size;
	chunkmax = chunksize - 1;
	while (a->size > 3)
	{
		while (still_in_chunk(a, chunkmin, chunkmax) && a->size > 3)
		{
			cheap = find_cheapest(a);
			rotate_to_node(a, cheap);
			pb(a, b);
			median = (chunkmin + chunkmax) / 2;
			if (b->top->index <= median && b->size > 1
				&& b->top->index != chunkmin)
				rb(b);
		}
		chunkmin += chunksize;
		chunkmax += chunksize;
	}
}
