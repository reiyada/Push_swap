/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:43:19 by ryada             #+#    #+#             */
/*   Updated: 2024/12/30 17:20:24 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_push(t_stack *stack, int value)
{
    t_node *new_node;
    new_node = malloc(sizeof(t_node));
    if (!new_node)
    {
        ft_printf("Failed to allocate node!");
        return;
    }
    new_node->value = value;
    new_node->next = NULL;
    if (!stack->top)
    {
        stack->top = new_node;
        stack->bottom = new_node;
    }
    else
    {
        stack->bottom->next = new_node;
        stack->bottom = new_node;
    }
    stack->size++;
}

void ft_fill_stack(t_stack *stack, int argc, char **argv)
{
    int i;
    int value;
    i = 1;
    while (i < argc)
    {
        value = ft_atoi(argv[i]);
        ft_push(stack, value);
        i++;
    }
}

void ft_display_stack(t_stack *stack)
{
    int i;
    i = 1;
    t_node *current;
    ft_printf("Number of elements:%d\n", stack->size);
    ft_printf("Elements:\n");
    current = stack->top;
    while(current)
    {
        ft_printf("[%d]%d\n",i, current->value);
        current = current ->next;
        i++;
    }
}

void ft_free_stack(t_stack *stack)
{
    t_node *current;
    t_node *temp;
    current  = stack->top;
    while (current)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
}