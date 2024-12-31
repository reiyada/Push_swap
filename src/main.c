/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rei <rei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:16:40 by ryada             #+#    #+#             */
/*   Updated: 2024/12/31 13:02:21 by rei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main (int argc, char **argv)
{
    t_stack *stack;
    if (ft_error(argc, argv) == 0)
    {
        ft_printf("Error\n");
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
