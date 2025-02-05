/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:56:58 by ryada             #+#    #+#             */
/*   Updated: 2025/02/05 13:46:44 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_bottom_to_top(t_stack **stack_move)
{
	t_node	*prev;
	t_node	*last;

	prev = NULL;
	if (!stack_move || !(*stack_move) || (*stack_move)->size < 2)
		return ;
	last = (*stack_move)->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (!prev || !last)
		return ;
	prev->next = NULL;
	last->next = (*stack_move)->top;
	(*stack_move)->top = last;
	(*stack_move)->bottom = prev;
}

void	rra(t_stack **stack_a, t_stack **stack_b, bool print)
{
	ft_bottom_to_top(stack_a);
	ft_update_stack(*stack_a);
	ft_update_node(stack_a, stack_b);
	if (print == false)
		ft_printf("rra\n");
}

void	rrb(t_stack **stack_b, t_stack **stack_a, bool print)
{
	ft_bottom_to_top(stack_b);
	ft_update_node(stack_b, stack_a);
	ft_update_stack(*stack_b);
	if (print == false)
		ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a, stack_b, true);
	rrb(stack_b, stack_a, true);
	ft_printf("rrr\n");
}
