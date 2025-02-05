/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:21:30 by ryada             #+#    #+#             */
/*   Updated: 2025/02/05 14:05:06 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../ft_printf/includes/ft_printf.h"
# include "../libft/libft.h"

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*target;
	int				value;
	int				cost;
	int				index;
	bool			mid;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	t_node	*biggest;
	t_node	*smallest;
	t_node	*cheapest;
	int		size;
}	t_stack;

//error.c
int		ft_check_argc(int argc);
int		ft_check_digit(int argc, char **argv);
int		ft_check_range(int argc, char **argv);
int		ft_check_dup(int argc, char **argv);
int		ft_error(int argc, char **argv);

//main.c
void	ft_process(int argc, char **argv, t_stack **stack_a, t_stack **stack_b);
void	ft_set_stacks(t_stack **stack_a, t_stack **stack_b);

//rule_p.c
void	ft_push(t_stack **stack_to, t_stack **stack_from);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);

//rule_r.c
void	ft_top_to_bottom(t_stack **stack_move);
void	ra(t_stack **stack_a, t_stack **stack_b, bool print);
void	rb(t_stack **stack_b, t_stack **stack_a, bool print);
void	rr(t_stack **stack_a, t_stack **stack_b);

//rule_rr.c
void	ft_bottom_to_top(t_stack **stack_move);
void	rra(t_stack **stack_a, t_stack **stack_b, bool print);
void	rrb(t_stack **stack_b, t_stack **stack_a, bool print);
void	rrr(t_stack **stack_a, t_stack **stack_b);

//rule_s.c
void	ft_swap(t_stack **stack_swap, t_stack **stack_stay);
void	sa(t_stack **stack_a, t_stack **stack_b, bool print);
void	sb(t_stack **stack_b, t_stack **stack_a, bool print);
void	ss(t_stack **stack_a, t_stack **stack_b);

//set_node.c
t_node	*ft_ini_node(int value);
void	ft_set_next(t_stack *stack, t_node *node, int to_top);
void	ft_push_node(t_stack *stack_a, int value, int to_top);

//set_stack.c
void	ft_ini_stack(t_stack *stack);
void	ft_set_top_bottom(t_stack *stack, t_node *node);
void	ft_set_index(t_stack *stack);
void	ft_set_mid(t_stack *stack);
void	ft_fill_stack(t_stack *stack_a, int argc, char **argv);

//tiny_sort.c
void	ft_tiny_sort(t_stack **stack_a, t_stack **stack_b);

//turk_sort.c
void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b,
			t_node *cheapest, t_node *target);
void	ft_before_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_large_stack(t_stack **stack_a, t_stack **stack_b);
void	ft_align_stack_a(t_stack **stack_a, t_stack **stack_b);
void	ft_turk(t_stack **stack_a, t_stack **stack_b, int argc, char **argv);

//turk_util.c
void	ft_count_cost_a(t_stack **stack_a);
int		ft_count_cost_b(t_node **current_a, t_stack **stack_b);
void	ft_calculate_total_cost(t_stack **stack_a, t_stack **stack_b);
void	ft_find_cheapest(t_stack **stack_a, t_stack **stack_b);

//update_node.c
void	ft_update_target_a(t_stack **stack_a, t_stack **stack_b);
void	ft_update_target_b(t_stack **stack_a, t_stack **stack_b);
void	ft_update_index(t_stack **stack);
void	ft_update_mid(t_stack **stack);
void	ft_update_node(t_stack **stack_a, t_stack **stack_b);

//update_stack.c
void	ft_update_top_bottom(t_stack *stack);
void	ft_update_biggest_smallest(t_stack *stack);
void	ft_update_size(t_stack *stack);
void	ft_update_cheapest(t_stack *stack_a);
void	ft_update_stack(t_stack *stack);

//util.c
int		ft_countstr(char **tab);
void	ft_free_tab(char **tab);
void	ft_free_stack(t_stack **stack);
int		ft_is_sorted(t_stack *stack_a);

#endif
