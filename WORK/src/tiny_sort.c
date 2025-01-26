/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rei <rei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:57:47 by ryada             #+#    #+#             */
/*   Updated: 2025/01/25 23:09:33 by rei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_tiny_sort(t_stack *stack_a, t_stack*stack_b)
{
    if (stack_a->top == stack_a->biggest)
        ra(stack_a, stack_b, false);
    else if (stack_a->top->next == stack_a->biggest)
        rra(stack_a, stack_b, false);
    if (stack_a->top->value > stack_a->top->next->value)
        sa(stack_a, stack_b, false);
}


