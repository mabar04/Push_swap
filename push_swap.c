/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 02:30:05 by mabar             #+#    #+#             */
/*   Updated: 2026/01/08 17:31:39 by mabar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (stacksorted(a))
		return ;
	if ((a)->size == 2)
	{
		sort_2(a);
		return ;
	}
	if ((a)->size == 3)
	{
		sort_3(a);
		return ;
	}
	if ((a)->size <= 5)
	{
		sort_5(a, b);
		return ;
	}
	else
	{
		sortalgo(a, b);
		return ;
	}
}
