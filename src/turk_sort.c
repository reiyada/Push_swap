/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:34:26 by ryada             #+#    #+#             */
/*   Updated: 2025/02/05 13:45:41 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b,
						t_node *cheapest, t_node *target)
{
	if (cheapest->mid && target->mid)
	{
		while (cheapest->index != 0 && target->index != 0)
			rr(stack_a, stack_b);
	}
	else if (!cheapest->mid && !target->mid)
	{
		while (cheapest->index != 0 && target->index != 0)
			rrr(stack_a, stack_b);
	}
}

void	ft_before_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*cheapest_in_a;
	t_node	*target_in_b;

	ft_find_cheapest(stack_a, stack_b);
	cheapest_in_a = (*stack_a)->cheapest;
	target_in_b = cheapest_in_a->target;
	if (cheapest_in_a->index == 0 && target_in_b->index == 0)
		return ;
	ft_rotate_both(stack_a, stack_b, cheapest_in_a, target_in_b);
	while (cheapest_in_a->index != 0)
	{
		if (cheapest_in_a->mid)
			ra(stack_a, stack_b, false);
		else
			rra(stack_a, stack_b, false);
	}
	while (target_in_b->index != 0)
	{
		if (target_in_b->mid)
			rb(stack_b, stack_a, false);
		else
			rrb(stack_b, stack_a, false);
	}
}

void	ft_sort_large_stack(t_stack **stack_a, t_stack **stack_b)
{
	while (((*stack_b)->size < 2) && (*stack_a)->size > 3)
		pb(stack_b, stack_a);
	while ((*stack_a)->size > 3)
	{
		ft_before_pb(stack_a, stack_b);
		pb(stack_b, stack_a);
	}
	ft_tiny_sort(stack_a, stack_b);
	while ((*stack_b)->size > 0)
	{
		if ((*stack_b)->top->target->mid)
		{
			while ((*stack_a)->top != (*stack_b)->top->target)
				ra(stack_a, stack_b, false);
		}
		else
		{
			while ((*stack_a)->top != (*stack_b)->top->target)
				rra(stack_a, stack_b, false);
		}
		pa(stack_a, stack_b);
	}
	if (!ft_is_sorted(*stack_a))
		ft_align_stack_a(stack_a, stack_b);
}

void	ft_align_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a) || !(*stack_a)->smallest || (*stack_a)->size <= 1)
		return ;
	if ((*stack_a)->smallest->mid)
	{
		while ((*stack_a)->top != (*stack_a)->smallest)
			ra(stack_a, stack_b, false);
	}
	else
	{
		while ((*stack_a)->top != (*stack_a)->smallest)
			rra(stack_a, stack_b, false);
	}
}

void	ft_turk(t_stack **stack_a, t_stack **stack_b, int argc, char **argv)
{
	ft_fill_stack(*stack_a, argc, argv);
	if (ft_is_sorted(*stack_a))
		return ;
	if ((*stack_a)->size > 3)
		ft_sort_large_stack(stack_a, stack_b);
	else
		ft_tiny_sort(stack_a, stack_b);
}
