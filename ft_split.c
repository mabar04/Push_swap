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

static int	countwords(const char *str, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (str[i] == c)
		{
			in_word = 0;
		}
		i++;
	}
	return (count);
}

static char	*ft_strdupv2(const char *s, int *k, char c)
{
	int		i;
	int		j;
	int		f;
	char	*a;

	i = 0;
	j = 0;
	f = *k;
	while (s[f] == c)
		f++;
	while (s[f + i] != c && s[f + i] != '\0')
		i++;
	a = malloc((i + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	while (j < i)
		a[j++] = s[f++];
	a[j] = '\0';
	*k = f;
	return (a);
}

static void	free_memory(char **s, int i)
{
	while (i > 0)
		free(s[--i]);
	free(s);
}

char	**ft_split(const char *s, char c)
{
	int		words;
	char	**a;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	words = countwords(s, c);
	a = (char **)malloc(sizeof(char *) * (words + 1));
	if (a == NULL)
		return (NULL);
	while (i < words)
	{
		a[i] = ft_strdupv2(s, &k, c);
		if (a[i] == NULL)
		{
			free_memory(a, i);
			return (NULL);
		}
		i++;
	}
	a[i] = NULL;
	return (a);
}
