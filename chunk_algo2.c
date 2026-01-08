/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_algo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 02:30:03 by mabar             #+#    #+#             */
/*   Updated: 2026/01/08 17:31:37 by mabar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_smallest_bigger(t_stack *a, int index)
{
	t_node	*tmp;
	t_node	*target;
	int		smallest;

	smallest = INT_MAX;
	target = NULL;
	tmp = a->top;
	while (tmp)
	{
		if (tmp->index > index && tmp->index < smallest)
		{
			smallest = tmp->index;
			target = tmp;
		}
		tmp = tmp->next;
	}
	return (target);
}

void	target_position(t_stack *a, t_stack *b)
{
	t_node	*tmpa;
	t_node	*tmpb;
	t_node	*target;

	tmpb = b->top;
	while (tmpb)
	{
		target = find_smallest_bigger(a, tmpb->index);
		if (target == NULL)
		{
			tmpa = a->top;
			target = tmpa;
			while (tmpa)
			{
				if (tmpa->index < target->index)
					target = tmpa;
				tmpa = tmpa->next;
			}
		}
		tmpb->target = target;
		tmpb = tmpb->next;
	}
}

t_node	*cheapest_calc(t_stack *b)
{
	t_node	*tmp;
	t_node	*cheap;
	int		cheap_cost;

	tmp = b->top;
	cheap = b->top;
	cheap_cost = cheap->total_cost;
	while (tmp)
	{
		if (cheap_cost > tmp->total_cost)
		{
			cheap_cost = tmp->total_cost;
			cheap = tmp;
		}
		tmp = tmp->next;
	}
	return (cheap);
}

void	pull_phase(t_stack *a, t_stack *b)
{
	t_node	*cheapest;

	while (b->size > 0)
	{
		target_position(a, b);
		calculate_costs(a, b);
		cheapest = cheapest_calc(b);
		execute_moves_combined(a, b, cheapest);
		pa(a, b);
	}
	final_rotate(a);
}
