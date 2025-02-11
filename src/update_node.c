/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:27:00 by ryada             #+#    #+#             */
/*   Updated: 2025/02/11 08:19:53 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_update_target_a(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*current_a;
	t_node	*current_b;
	t_node	*best_target;

	current_a = (*stack_a)->top;
	while (current_a)
	{
		if (current_a->value < (*stack_b)->smallest->value
			|| current_a->value > (*stack_b)->biggest->value)
			best_target = (*stack_b)->biggest;
		else
		{
			current_b = (*stack_b)->top;
			best_target = (*stack_b)->smallest;
			while (current_b)
			{
				if (current_a->value > current_b->value
					&& best_target->value < current_b->value)
					best_target = current_b;
				current_b = current_b->next;
			}
		}
		current_a->target = best_target;
		current_a = current_a->next;
	}
}

void	ft_update_target_b(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*current_b;
	t_node	*current_a;
	t_node	*best_target;

	if (!stack_a || !stack_b || (*stack_a)->size == 0 || (*stack_b)->size == 0)
		return ;
	current_b = (*stack_b)->top;
	while (current_b)
	{
		best_target = NULL;
		current_a = (*stack_a)->top;
		while (current_a)
		{
			if (current_a->value > current_b->value)
			{
				if (!best_target || current_a->value < best_target->value)
					best_target = current_a;
			}
			current_a = current_a->next;
		}
		if (!best_target)
			best_target = (*stack_a)->smallest;
		current_b->target = best_target;
		current_b = current_b->next;
	}
}

void	ft_update_index(t_stack **stack)
{
	t_node	*current;
	int		i;

	i = 0;
	current = (*stack)->top;
	while (current)
	{
		current->index = i;
		i++;
		current = current->next;
	}
}

void	ft_update_mid(t_stack **stack)
{
	t_node	*current;

	current = (*stack)->top;
	while (current)
	{
		if (current->index + 1 <= (*stack)->size / 2)
			current->mid = true;
		else
			current->mid = false;
		current = current->next;
	}
}

void	ft_update_node(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)-> size >= 3 && (*stack_b) && (*stack_b)->size > 0)
	{
		ft_update_target_a(stack_a, stack_b);
		ft_update_target_b(stack_a, stack_b);
	}
	ft_update_index(stack_a);
	ft_update_index(stack_b);
	ft_update_mid(stack_a);
	ft_update_mid(stack_b);
}
