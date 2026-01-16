/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 02:30:03 by mabar             #+#    #+#             */
/*   Updated: 2026/01/08 17:31:37 by mabar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strncmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	execute_instruction(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(line, "rrr\n"))
		rrr(a, b);
	else if (!ft_strncmp(line, "rra\n"))
		rra(a);
	else if (!ft_strncmp(line, "rrb\n"))
		rrb(b);
	else if (!ft_strncmp(line, "rr\n"))
		rr(a, b);
	else if (!ft_strncmp(line, "ra\n"))
		ra(a);
	else if (!ft_strncmp(line, "rb\n"))
		rb(b);
	else if (!ft_strncmp(line, "sa\n"))
		sa(a);
	else if (!ft_strncmp(line, "sb\n"))
		sb(b);
	else if (!ft_strncmp(line, "ss\n"))
		ss(a, b);
	else if (!ft_strncmp(line, "pa\n"))
		pa(a, b);
	else if (!ft_strncmp(line, "pb\n"))
		pb(a, b);
	else
		return (write(2, "Error\n", 6));
	return (0);
}

static void	free_all(char *line, t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	free(line);
}

static void	main_helper(t_stack **a, t_stack **b, char ***argv0)
{
	char	*line;
	int		i;

	i = 1;
	while (i)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if (execute_instruction(line, *a, *b) != 0)
		{
			free_all(line, *a, *b);
			return ;
		}
		free(line);
	}
	if (stacksorted(*a) && (*b)->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (*argv0)
		free_memory_main(*argv0);
	free_all(line, *a, *b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**argv0;

	if (argc < 2)
		return (1);
	a = NULL;
	b = NULL;
	argv0 = NULL;
	argv0 = flatten(argc, argv);
	if (!argv0 || *argv0 == NULL)
	{
		free_memory_main(argv0);
		return (2);
	}
	initialise_stack(&a, &b, argv);
	if (!a)
	{
		free_stack(a);
		free_stack(b);
		if (argv0)
			free_memory_main(argv0);
		return (2);
	}
	main_helper(&a, &b, &argv0);
}
