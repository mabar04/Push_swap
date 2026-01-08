/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_logic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 02:30:05 by mabar             #+#    #+#             */
/*   Updated: 2026/01/08 17:31:39 by mabar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *a)
{
	if (a->top->data > a->bottom->data)
		sa(a);
}

void	sort_3(t_stack *a)
{
	int	aa;
	int	bb;
	int	cc;

	aa = a->top->index;
	bb = a->top->next->index;
	cc = a->bottom->index;
	if (aa > bb && bb < cc && aa < cc)
		sa(a);
	else if (aa > bb && bb > cc)
	{
		sa(a);
		rra(a);
	}
	else if (aa > bb && bb < cc && aa > cc)
		ra(a);
	else if (aa < bb && bb > cc && aa < cc)
	{
		sa(a);
		ra(a);
	}
	else if (aa < bb && bb > cc && aa > cc)
		rra(a);
}

void	sort_5(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		if (a->top->index == 0 || a->top->index == 1)
			pb(a, b);
		else
			ra(a);
	}
	sort_3(a);
	pa(a, b);
	pa(a, b);
	if (a->top->index == 1 && a->top->next->index == 0)
		sa(a);
	return ;
}

void	sortalgo(t_stack *a, t_stack *b)
{
	chunkalgo(a, b);
	sort_3(a);
	pull_phase(a, b);
}
