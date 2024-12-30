/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:16:40 by ryada             #+#    #+#             */
/*   Updated: 2024/12/30 17:20:23 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main (int argc, char **argv)
{
    t_stack *stack;
    if (ft_check_argc(argc) == 0)
    {
        ft_printf("Put more than 2 arguments!");
        return (1);
    }
    if (ft_check_digit(argv) == 0)
    {
        ft_printf("Put only digits as arguments!");
        return (1);
    }
    if (ft_check_range(argv) == 0)
    {
        ft_printf("Digit is too big or too small!");
        return (1);
    }
    stack = malloc(sizeof(t_stack));
    if(!stack)
    {
        ft_printf("Failed to allocate stack!");
        return (1);
    }
    stack->top = NULL;
    stack->size = 0;
    ft_fill_stack(stack, argc, argv);
    ft_display_stack(stack);
    ft_free_stack(stack);
}
