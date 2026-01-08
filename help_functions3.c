/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:31:38 by mabar             #+#    #+#             */
/*   Updated: 2026/01/08 17:31:38 by mabar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *i, t_stack *a, int *T)
{
	int	k;
	int	j;

	while ((*i) < a->size - 1)
	{
		j = (*i) + 1;
		while (j < a->size)
		{
			if (T[(*i)] > T[(j)])
			{
				k = T[(*i)];
				T[(*i)] = T[j];
				T[j] = k;
			}
			j++;
		}
		(*i)++;
	}
}

void	indexing_helpp(t_node *tmp, t_stack *a, int *s)
{
	int	i;

	while (tmp)
	{
		i = 0;
		while (i < a->size)
		{
			if (s[i] == tmp->data)
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}
