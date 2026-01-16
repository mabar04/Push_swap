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

char	*word_dup(char *s, int a, int b)
{
	char	*w;
	int		i;

	w = malloc((b - a + 1));
	if (!w)
		return (NULL);
	i = 0;
	while (a < b)
		w[i++] = s[a++];
	w[i] = '\0';
	return (w);
}

char	**split_one(char *s)
{
	char	**out;
	int		i;
	int		k;
	int		st;

	out = malloc(sizeof(char *) * (word_count(s) + 1));
	if (!out)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && is_space(s[i]))
			i++;
		st = i;
		while (s[i] && !is_space(s[i]))
			i++;
		if (i > st)
			out[k++] = word_dup(s, st, i);
	}
	out[k] = NULL;
	return (out);
}

int	total_words(int ac, char **av)
{
	int	i;
	int	total;

	i = 1;
	total = 0;
	while (i < ac)
		total += word_count(av[i++]);
	return (total);
}
