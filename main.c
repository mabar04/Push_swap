/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 02:30:04 by mabar             #+#    #+#             */
/*   Updated: 2026/01/08 17:31:38 by mabar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	main_helper(t_stack *a, t_stack *b, char **argv0)
{
	if (!a)
		return ;
	indexingstack(a);
	push_swap(a, b);
	free_stack(a);
	free_stack(b);
	if (argv0)
		free_memory_main(argv0);
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
	if (argc == 2)
	{
		argv0 = ft_split(argv[1], ' ');
		if (!argv0)
			return (1);
		if (argv0[0] == NULL)
			return (write(2, "Error\n", 6));
		initialise_stack(&a, &b, argv0);
	}
	else
	{
		argv++;
		initialise_stack(&a, &b, argv);
	}
	main_helper(a, b, argv0);
}
