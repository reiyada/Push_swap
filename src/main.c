/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:16:40 by ryada             #+#    #+#             */
/*   Updated: 2024/12/18 14:55:55 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long int	result;
	int					i;
	int					sign;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

void ft_push(t_stack *stack, int value)
{
    t_node *new_node;
    new_node = malloc(sizeof(t_node));
    if (!new_node)
    {
        perror("Failed to allocate node!");
        return;
    }
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
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
    printf("Number of elements:%d\n", stack->size);
    printf("Elements:\n");
    current = stack->top;
    while(current)
    {
        printf("[%d]%d\n",i, current->value);
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


int main (int argc, char **argv)
{
    t_stack *stack;
    if (argc < 2)
    {
        perror("Put arguments!");
        return (1);
    }
    stack = malloc(sizeof(t_stack));
    if(!stack)
    {
        perror("Failed to allocate stack!");
        return (1);
    }
    stack->top = NULL;
    stack->size = 0;
    ft_fill_stack(stack, argc, argv);
    ft_display_stack(stack);
    ft_free_stack(stack);
}
