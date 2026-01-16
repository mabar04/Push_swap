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
	{
		free_stack(a);
		free_stack(b);
		if (argv0)
			free_memory_main(argv0);
		return ;
	}
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
	argv0 = flatten(argc, argv);
	if (!argv0 || *argv0 == NULL)
	{
		free_memory_main(argv0);
		return (2);
	}
	initialise_stack(&a, &b, argv0);
	main_helper(a, b, argv0);
}
