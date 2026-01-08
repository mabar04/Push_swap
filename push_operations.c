/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 02:30:04 by mabar             #+#    #+#             */
/*   Updated: 2026/01/08 17:31:39 by mabar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_helper(t_stack *a, t_stack *b, t_node *tmp)
{
	b->size--;
	tmp->previous = NULL;
	tmp->next = a->top;
	if (a->size == 0)
	{
		a->top = tmp;
		a->bottom = tmp;
	}
	else
	{
		a->top->previous = tmp;
		a->top = tmp;
	}
	a->size++;
}

static void	push_algo(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!a || !b || b->size == 0)
		return ;
	tmp = b->top;
	if (b->size == 1)
	{
		b->top = NULL;
		b->bottom = NULL;
	}
	else
	{
		b->top = b->top->next;
		b->top->previous = NULL;
	}
	push_helper(a, b, tmp);
}

void	pa(t_stack *a, t_stack *b)
{
	push_algo(a, b);
	write(1, "pa\n", 3);
	return ;
}

void	pb(t_stack *a, t_stack *b)
{
	push_algo(b, a);
	write(1, "pb\n", 3);
	return ;
}
