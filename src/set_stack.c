/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:07:35 by ryada             #+#    #+#             */
/*   Updated: 2025/02/05 13:39:59 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ini_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	stack->biggest = NULL;
	stack->smallest = NULL;
	stack->cheapest = NULL;
}

void	ft_set_top_bottom(t_stack *stack, t_node *node)
{
	if (!stack->top)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		stack->bottom->next = node;
		stack->bottom = node;
	}
}

void	ft_set_index(t_stack *stack)
{
	t_node	*current;
	int		i;

	i = 0;
	current = stack->top;
	while (current)
	{
		current->index = i;
		i++;
		current = current->next;
	}
}

void	ft_set_mid(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->index + 1 <= (stack->size / 2))
			current->mid = true;
		else
			current->mid = false;
		current = current->next;
	}
}

void	ft_fill_stack(t_stack *stack_a, int argc, char **argv)
{
	int	i;
	int	size;
	int	value;

	if (argc == 2)
	{
		i = 0;
		size = ft_countstr(argv);
	}
	else
	{
		i = 1;
		size = argc;
	}
	while (i < size)
	{
		value = ft_atoi(argv[i]);
		ft_push_node(stack_a, value, 0);
		i++;
	}
	ft_update_stack(stack_a);
}
