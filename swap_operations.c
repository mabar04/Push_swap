/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 02:30:05 by mabar             #+#    #+#             */
/*   Updated: 2026/01/08 17:31:40 by mabar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sa_algo(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->previous = first;
	else
		a->bottom = first;
	first->previous = second;
	second->previous = NULL;
	second->next = first;
	a->top = second;
}

void	sa(t_stack *a)
{
	sa_algo(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	sa_algo(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa_algo(a);
	sa_algo(b);
	write(1, "ss\n", 3);
}
