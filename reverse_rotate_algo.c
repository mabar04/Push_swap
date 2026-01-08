/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_algo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 02:30:05 by mabar             #+#    #+#             */
/*   Updated: 2026/01/08 17:31:39 by mabar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_algo(t_stack *a)
{
	t_node	*bottomnode;

	if (!a || a->size < 2)
		return ;
	bottomnode = a->bottom;
	a->bottom = a->bottom->previous;
	a->bottom->next = NULL;
	bottomnode->next = a->top;
	a->top->previous = bottomnode;
	a->top = bottomnode;
	bottomnode->previous = NULL;
}

void	rra(t_stack *a)
{
	reverse_rotate_algo(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *a)
{
	reverse_rotate_algo(a);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate_algo(a);
	reverse_rotate_algo(b);
	write(1, "rrr\n", 4);
}
