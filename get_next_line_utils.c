/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabar <mabar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:34:09 by mabar             #+#    #+#             */
/*   Updated: 2025/11/23 11:11:56 by mabar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen_next(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlen_ln(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*a;
	const unsigned char	*b;
	size_t				r;

	a = (unsigned char *)dest;
	b = (const unsigned char *)src;
	r = 0;
	while (r < n)
	{
		a[r] = b[r];
		r++;
	}
	return (dest);
}

char	*ft_strdup(char *s)
{
	size_t	i;
	size_t	j;
	char	*a;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	a = malloc((i + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	while (j < i)
	{
		a[j] = s[j];
		j++;
	}
	a[j] = '\0';
	return (a);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		len1;
	int		len2;

	if (!s1)
		return (ft_strdup(s2));
	len1 = ft_strlen_next(s1);
	len2 = ft_strlen_next(s2);
	new = malloc(len1 + len2 + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, len1);
	ft_memcpy(new + len1, s2, len2);
	new[len1 + len2] = '\0';
	free(s1);
	return (new);
}