/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:38:37 by ryada             #+#    #+#             */
/*   Updated: 2025/02/05 13:40:28 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_ini_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	new_node->value = value;
	new_node->next = NULL;
	new_node->target = NULL;
	new_node->cost = 0;
	new_node->index = 0;
	return (new_node);
}

void	ft_set_next(t_stack *stack, t_node *node, int to_top)
{
	if (to_top || !stack->top)
		node->next = stack->top;
	else if (stack->bottom)
		stack->bottom->next = node;
}

void	ft_push_node(t_stack *stack_a, int value, int to_top)
{
	t_node	*new_node;

	new_node = ft_ini_node(value);
	if (!new_node)
		return (ft_putstr_fd("Error\n", 2));
	ft_set_next(stack_a, new_node, to_top);
	ft_set_top_bottom(stack_a, new_node);
	ft_set_index(stack_a);
	ft_set_mid(stack_a);
	stack_a->size++;
}
