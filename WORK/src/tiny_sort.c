/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rei <rei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:57:47 by ryada             #+#    #+#             */
/*   Updated: 2025/01/27 00:07:41 by rei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void ft_tiny_sort(t_stack **stack_a, t_stack **stack_b)
// {
//     if (!stack_a || !(*stack_a) || (*stack_a)->size < 2)
//     {
//         printf("Tiny sort: Invalid stack or too small to sort.\n");
//         return;
//     }

//     // Ensure top and next nodes exist
//     if (!(*stack_a)->top || !(*stack_a)->top->next)
//     {
//         printf("Tiny sort: Missing nodes for sorting.\n");
//         return;
//     }

//     // Sort the three elements
//     if ((*stack_a)->top->value > (*stack_a)->top->next->value &&
//         (*stack_a)->top->value > (*stack_a)->bottom->value)
//     {
//         printf("Performing ra\n");
//         ra(stack_a, stack_b, false);
//     }
//     else if ((*stack_a)->top->next->value > (*stack_a)->bottom->value &&
//              (*stack_a)->bottom->value < (*stack_a)->top->value)
//     {
//         printf("Performing rra\n");
//         rra(stack_a, stack_b, false);
//         ft_display_stack(*stack_a, *stack_b);
//     }
//     if ((*stack_a)->top->value > (*stack_a)->top->next->value)
//     {
//         printf("Performing sa\n");
//         sa(stack_a, stack_b, false);
//     }

//     printf("Tiny sort end:\n");
//     ft_display_stack(*stack_a, *stack_b);
// }


// void ft_tiny_sort(t_stack **stack_a, t_stack **stack_b)
// {
//     // Case: [3, 2, 1]
//     if ((*stack_a)->top->value > (*stack_a)->top->next->value &&
//         (*stack_a)->top->value > (*stack_a)->bottom->value)
//     {
//         ra(stack_a, stack_b, false);
//         if ((*stack_a)->top->value > (*stack_a)->top->next->value)
//             sa(stack_a, stack_b, false);
//     }
//     // Case: [2, 3, 1]
//     else if ((*stack_a)->top->next->value > (*stack_a)->bottom->value &&
//             (*stack_a)->bottom->value < (*stack_a)->top->value)
//     {
//         rra(stack_a, stack_b, false);
//         if ((*stack_a)->top->value > (*stack_a)->top->next->value)
//             sa(stack_a, stack_b, false);
//     }
//     // Case: [2, 1, 3]
//     else if ((*stack_a)->top->value > (*stack_a)->top->next->value)
//     {
//         sa(stack_a, stack_b, false);
//     }
// }

void ft_tiny_sort(t_stack **stack_a, t_stack **stack_b)
{
    if ((*stack_a)->top == (*stack_a)->biggest)
        ra(stack_a, stack_b, false);
    else if ((*stack_a)->top->next == (*stack_a)->biggest)
        rra(stack_a, stack_b, false);
    if ((*stack_a)->top->value > (*stack_a)->top->next->value)
        sa(stack_a, stack_b, false);
}




