/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_algo4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 02:30:03 by mabar             #+#    #+#             */
/*   Updated: 2026/01/08 17:31:37 by mabar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_moves_helper1(t_stack *a, t_stack *b, t_node *cheapest)
{
	while (cheapest->a_cost != 0 && cheapest->b_cost != 0
		&& ((cheapest->a_cost > 0 && cheapest->b_cost > 0)
			|| (cheapest->a_cost < 0 && cheapest->b_cost < 0)))
	{
		if (cheapest->a_cost > 0)
		{
			rr(a, b);
			cheapest->a_cost--;
			cheapest->b_cost--;
		}
		else
		{
			rrr(a, b);
			cheapest->a_cost++;
			cheapest->b_cost++;
		}
	}
}

static void	execute_moves_helper2(t_stack *a, t_node *cheapest)
{
	while (cheapest->a_cost != 0)
	{
		if (cheapest->a_cost > 0)
		{
			ra(a);
			cheapest->a_cost--;
		}
		else
		{
			rra(a);
			cheapest->a_cost++;
		}
	}
}

void	execute_moves_combined(t_stack *a, t_stack *b, t_node *cheapest)
{
	execute_moves_helper1(a, b, cheapest);
	execute_moves_helper2(a, cheapest);
	while (cheapest->b_cost != 0)
	{
		if (cheapest->b_cost > 0)
		{
			rb(b);
			cheapest->b_cost--;
		}
		else
		{
			rrb(b);
			cheapest->b_cost++;
		}
	}
}

static void	final_rotate_helper(t_stack **a, int *pos)
{
	if ((*pos) <= (*a)->size / 2)
	{
		while ((*pos) > 0)
		{
			ra(*a);
			(*pos)--;
		}
	}
	else
	{
		(*pos) = (*a)->size - (*pos);
		while ((*pos) > 0)
		{
			rra(*a);
			(*pos)--;
		}
	}
}

void	final_rotate(t_stack *a)
{
	t_node	*tmp;
	int		pos;

	pos = 0;
	tmp = a->top;
	while (tmp->index != 0)
	{
		tmp = tmp->next;
		pos++;
	}
	final_rotate_helper(&a, &pos);
}
