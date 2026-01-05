/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabar <mabar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:34:09 by mabar             #+#    #+#             */
/*   Updated: 2025/12/10 13:02:50 by mabar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_newline(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

static char	*read_to_stash(int fd, char *stash)
{
	char	*buffer;
	int		bytes;
	char	*tmp;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stash), NULL);
	while (!has_newline(stash))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), free(stash), NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		tmp = ft_strjoin(stash, buffer);
		if (!tmp)
			return (free(buffer), free(stash), NULL);
		stash = tmp;
	}
	free(buffer);
	return (stash);
}

static char	*extract_line(char *stash)
{
	int		len;
	char	*line;

	if (!stash || stash[0] == '\0')
		return (NULL);
	len = ft_strlen_ln(stash);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, stash, len);
	line[len] = '\0';
	return (line);
}

static char	*clean_stash(char *stash)
{
	int		line_len;
	int		total;
	char	*newstash;

	line_len = ft_strlen_ln(stash);
	total = ft_strlen_next(stash);
	if (line_len >= total)
	{
		free(stash);
		return (NULL);
	}
	newstash = ft_strdup(stash + line_len);
	free(stash);
	return (newstash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
		return (free(stash), NULL);
	stash = clean_stash(stash);
	return (line);
}