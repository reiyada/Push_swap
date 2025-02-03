/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:57:47 by ryada             #+#    #+#             */
/*   Updated: 2025/02/03 14:44:03 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_tiny_sort(t_stack **stack_a, t_stack **stack_b)
{
    if ((*stack_a)->top == (*stack_a)->biggest)
        ra(stack_a, stack_b, false);
    else if ((*stack_a)->top->next == (*stack_a)->biggest)
        rra(stack_a, stack_b, false);
    if ((*stack_a)->top->value > (*stack_a)->top->next->value)
        sa(stack_a, stack_b, false);
}




