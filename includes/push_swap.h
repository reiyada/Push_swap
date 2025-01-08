/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:21:30 by ryada             #+#    #+#             */
/*   Updated: 2025/01/08 14:02:07 by ryada            ###   ########.fr       */
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
void ft_fill_stack(t_stack *stack_a, int argc, char **argv);
void ft_display_stack(t_stack *stack_a, t_stack *stack_b);
void ft_free_stack(t_stack *stack);
void ft_free_tab(char **tab);
void ft_push_stack(t_stack *stack_a, t_stack *stack_b, int argc, char **argv);
void sa(t_stack *stack_a);
void sb(t_stack *stack_b);
void ss(t_stack *stack_a, t_stack *stack_b);
void pa(t_stack *stack_a, t_stack *stack_b);
void pb(t_stack *stack_b, t_stack *stack_a);
void ra(t_stack *stack_a);
void rb(t_stack *stack_b);
void rr(t_stack *stack_a, t_stack *stack_b);
void rra(t_stack *stack_a);
void rrb(t_stack *stack_b);
void rrr(t_stack *stack_a, t_stack *stack_b);
void ft_set_stack(t_stack *stack_a, t_stack *stack_b);
void ft_sort_array(int *array, int size);
void ft_move_to_stackb(t_stack *stack_a, t_stack *stack_b, int count);

int ft_check_argc(int argc);
int ft_check_digit(char **argv);
int ft_check_range(char **argv);
int ft_check_dup(int argc, char **argv);
int ft_error(int argc, char **argv);
int ft_find_pivot(t_stack *stack_a, int size);
int ft_countstr(char **tab);


t_stack *ft_sort_2(t_stack *stack_a);
t_stack *ft_sort_3(t_stack *stack_a);
t_stack *ft_sort_4_5(t_stack *stack_a, t_stack *stack_b, int argc, char **argv);

#endif