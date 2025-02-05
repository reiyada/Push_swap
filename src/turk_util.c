/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:42:38 by ryada             #+#    #+#             */
/*   Updated: 2025/02/05 13:47:17 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_count_cost_a(t_stack **stack_a)
{
	t_node	*current;

	if (!stack_a || (*stack_a)->size <= 1)
		return ;
	current = (*stack_a)->top;
	while (current)
	{
		if (current->mid)
			current->cost = current->index;
		else
			current->cost = (*stack_a)->size - current->index;
		current = current->next;
	}
}

int	ft_count_cost_b(t_node **current_a, t_stack **stack_b)
{
	t_node	*target_node;

	if (!stack_b || (*stack_b)->size == 0 || !(*current_a)->target)
		return (0);
	target_node = (*current_a)->target;
	if (target_node->mid)
		return (target_node->index);
	else
		return ((*stack_b)->size - target_node->index);
}

void	ft_calculate_total_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*current_a;
	int		cost_a;
	int		cost_b;

	if (!stack_a || !stack_b)
		return ;
	ft_count_cost_a(stack_a);
	current_a = (*stack_a)->top;
	while (current_a)
	{
		cost_a = current_a->cost;
		cost_b = ft_count_cost_b(&current_a, stack_b);
		if ((current_a->mid && current_a->target->mid)
			|| (!(current_a->mid) && !(current_a->target->mid)))
		{
			if (cost_a > cost_b)
				current_a->cost = cost_a;
			else
				current_a->cost = cost_b;
		}
		else
			current_a->cost = cost_a + cost_b;
		current_a = current_a->next;
	}
}

void	ft_find_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*cheapest;
	t_node	*current;

	ft_calculate_total_cost(stack_a, stack_b);
	current = (*stack_a)->top;
	cheapest = current;
	while (current)
	{
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->next;
	}
	(*stack_a)->cheapest = cheapest;
}
