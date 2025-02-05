/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:16:40 by ryada             #+#    #+#             */
/*   Updated: 2025/02/05 13:45:54 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	ft_process(argc, argv, &stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}

void	ft_process(int argc, char **argv, t_stack **stack_a, t_stack **stack_b)
{
	char	**tab;

	if (argc == 2)
		tab = ft_split(argv[1], ' ');
	else
		tab = argv;
	if (!ft_error(argc, tab))
	{
		ft_putstr_fd("Error\n", 2);
		if (argc == 2)
			ft_free_tab(tab);
		exit(1);
	}
	ft_set_stacks(stack_a, stack_b);
	ft_turk(stack_a, stack_b, argc, tab);
	if (argc == 2)
		ft_free_tab(tab);
}

void	ft_set_stacks(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = malloc(sizeof(t_stack));
	*stack_b = malloc(sizeof(t_stack));
	if (!(*stack_a) || !(*stack_b))
	{
		free(*stack_a);
		free(*stack_b);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	ft_ini_stack(*stack_a);
	ft_ini_stack(*stack_b);
}
