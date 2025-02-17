/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:43:20 by ryada             #+#    #+#             */
/*   Updated: 2025/02/05 13:33:31 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_update_top_bottom(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
	{
		stack->bottom = NULL;
		return ;
	}
	current = stack->top;
	while (current->next)
		current = current->next;
	stack->bottom = current;
}

void	ft_update_biggest_smallest(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	stack->biggest = current;
	stack->smallest = current;
	while (current)
	{
		if (current->value > stack->biggest->value)
			stack->biggest = current;
		if (current->value < stack->smallest->value)
			stack->smallest = current;
		current = current->next;
	}
}

void	ft_update_size(t_stack *stack)
{
	int		size;
	t_node	*current;

	size = 0;
	current = stack->top;
	while (current)
	{
		size++;
		current = current->next;
	}
	stack->size = size;
}

void	ft_update_cheapest(t_stack *stack_a)
{
	t_node	*cheapest;
	t_node	*current;

	if (!stack_a)
		return ;
	current = stack_a->top;
	cheapest = current;
	while (current)
	{
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->next;
	}
	stack_a->cheapest = cheapest;
}

void	ft_update_stack(t_stack *stack)
{
	ft_update_top_bottom(stack);
	ft_update_biggest_smallest(stack);
	ft_update_size(stack);
	ft_update_cheapest(stack);
}
