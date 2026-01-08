/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_algo3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 02:30:03 by mabar             #+#    #+#             */
/*   Updated: 2026/01/08 17:31:37 by mabar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cost_b(t_stack *b)
{
	t_node	*tmp;
	int		pos;

	tmp = b->top;
	pos = 0;
	while (tmp)
	{
		if (pos <= b->size / 2)
			tmp->b_cost = pos;
		else
			tmp->b_cost = pos - b->size;
		tmp = tmp->next;
		pos++;
	}
}

static void	cost_a(t_stack *a, t_stack *b)
{
	t_node	*tmpa;
	t_node	*tmpb;
	int		pos;

	tmpb = b->top;
	while (tmpb)
	{
		tmpa = a->top;
		pos = 0;
		while (tmpa)
		{
			if (tmpa == tmpb->target)
			{
				if (pos <= a->size / 2)
					tmpb->a_cost = pos;
				else
					tmpb->a_cost = pos - a->size;
				break ;
			}
			tmpa = tmpa->next;
			pos++;
		}
		tmpb = tmpb->next;
	}
}

static int	abs_mine(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

static void	total_cost(t_stack *b)
{
	t_node	*tmp;

	tmp = b->top;
	while (tmp)
	{
		tmp->total_cost = abs_mine(tmp->a_cost) + abs_mine(tmp->b_cost);
		tmp = tmp->next;
	}
}

void	calculate_costs(t_stack *a, t_stack *b)
{
	cost_a(a, b);
	cost_b(b);
	total_cost(b);
}
