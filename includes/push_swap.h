/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rei <rei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:21:30 by ryada             #+#    #+#             */
/*   Updated: 2025/01/23 19:59:59 by rei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../ft_printf/includes/ft_printf.h"
#include "../libft/libft.h"

typedef struct s_node
{
    struct s_node *next;
    struct s_node *target;
    int value;
    int cost;
    int index;
}   t_node;

typedef struct s_stack
{
    t_node *top;
    t_node *bottom;
    t_node *biggest;
    t_node *smallest;
    t_node *cheapest;
    int size;
}   t_stack;


void ft_push(t_stack *stack, int value, int to_top);
void ft_fill_stack(t_stack *stack_a, int argc, char **argv);
void ft_display_stack(t_stack *stack_a, t_stack *stack_b);
void ft_free_stack(t_stack *stack);
void ft_free_tab(char **tab);
void ft_push_swap_turk(t_stack *stack_a, t_stack *stack_b, int argc, char **argv);
void sa(t_stack *stack_a, bool print);
void sb(t_stack *stack_b, bool print);
void ss(t_stack *stack_a, t_stack *stack_b);
void pa(t_stack *stack_a, t_stack *stack_b);
void pb(t_stack *stack_b, t_stack *stack_a);
void ft_top_to_bottom(t_stack *stack);
void ra(t_stack *stack_a, bool print);
void rb(t_stack *stack_b, bool print);
void rr(t_stack *stack_a, t_stack *stack_b);
void rra(t_stack *stack_a, bool print);
void rrb(t_stack *stack_b, bool print);
void rrr(t_stack *stack_a, t_stack *stack_b);
void ft_set_stack(t_stack *stack_a, t_stack *stack_b);
void ft_sort_array(int *array, int size);
void ft_move_to_stackb(t_stack *stack_a, t_stack *stack_b, int count);
void ft_count_cost_a(t_stack *stack_a);
void ft_assign_index(t_stack *stack);
void ft_calculate_total_cost(t_stack *stack_a, t_stack *stack_b);
void ft_assign_biggest_smallest(t_stack *stack_b);
void ft_find_cheapest(t_stack *stack_a);
void ft_find_target_node(t_stack *stack_a, t_stack *stack_b);
void ft_target_to_top(t_stack *stack_b, t_node *target);
void ft_sort_stack_b(t_stack *stack_b);
void ft_sort_stack_a(t_stack *stack_a, t_stack *stack_b);
void ft_cheapest_to_top(t_stack *stack_a);
void ft_rotate_to_sorted(t_stack *stack_a);

void ft_set_top_bottom(t_stack *stack_a);
int ft_check_argc(int argc);
int ft_check_digit(int argc, char **argv);
int ft_check_range(char **argv);
int ft_check_dup(int argc, char **argv);
int ft_error(int argc, char **argv);
int ft_find_pivot(t_stack *stack_a, int size);
int ft_countstr(char **tab);
int ft_count_cost_b(t_node *current_a, t_stack *stack_b);
int ft_is_sorted(t_stack *stack_a);

t_stack *ft_sort_2(t_stack *stack_a);
t_stack *ft_sort_3(t_stack *stack_a);
t_stack *ft_sort_4_5(t_stack *stack_a, t_stack *stack_b);

void increment_operation_count(void);
int get_operation_count(void);
void reset_operation_count(void);

#endif