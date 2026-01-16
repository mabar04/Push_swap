/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 02:30:04 by mabar             #+#    #+#             */
/*   Updated: 2026/01/08 17:31:37 by mabar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	is_space(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

int	word_count(char *s)
{
	int	i;
	int	c;
	int	in;

	i = 0;
	in = 0;
	c = 0;
	while (s[i])
	{
		if (!is_space(s[i]) && !in)
		{
			in = 1;
			c++;
		}
		else if (is_space(s[i]))
			in = 0;
		i++;
	}
	return (c);
}

char	**fill_flat(int ac, char **av, char **res)
{
	char	**tmp;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	while (i < ac)
	{
		tmp = split_one(av[i++]);
		j = 0;
		while (tmp[j])
			res[k++] = tmp[j++];
		free(tmp);
	}
	res[k] = NULL;
	return (res);
}

char	**flatten(int ac, char **av)
{
	char	**res;

	res = malloc(sizeof(char *) * (total_words(ac, av) + 1));
	if (!res)
		return (NULL);
	return (fill_flat(ac, av, res));
}
