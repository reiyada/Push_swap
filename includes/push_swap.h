/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:21:30 by ryada             #+#    #+#             */
/*   Updated: 2025/01/02 15:59:29 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../ft_printf/includes/ft_printf.h"
#include "../libft/libft.h"

typedef struct s_node
{
    struct s_node *next;
    int value;
}   t_node;

typedef struct s_stack
{
    t_node *top;
    t_node *bottom;
    int size;
}   t_stack;

void ft_push(t_stack *stack, int value, int to_top);
void ft_fill_stack(t_stack *stack, int argc, char **argv);
void ft_display_stack(t_stack *stack);
void ft_free_stack(t_stack *stack);


int ft_check_argc(int argc);
int ft_check_digit(char **argv);
int ft_check_range(char **argv);
int ft_check_dup(char **argv);
int ft_error(int argc, char **argv);


#endif