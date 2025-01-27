/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rei <rei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:27:00 by ryada             #+#    #+#             */
/*   Updated: 2025/01/26 21:31:59 by rei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// typedef struct s_node
// {
//     struct s_node *next; DONE
//     struct s_node *target; DONE/ DONE
//     int value; NO NEED
//     int cost; 
//     int index;
// }   t_node;

void ft_update_target_a(t_stack *stack_a, t_stack *stack_b)
{
    t_node *current_a;
    t_node *current_b;
    t_node *best_target;

    if (!stack_a || !stack_b || stack_b->size == 0)
        return;
    current_a = stack_a->top;
    while (current_a)
    {
        if (current_a->value < stack_b->smallest->value)
            best_target = stack_b->smallest;
        else if (current_a->value > stack_b->biggest->value)
            best_target = stack_b->biggest;
        else
        {
            current_b = stack_b->top;
            while (current_b)
            {
                if (current_a->value > current_b->value &&
                    (!current_b->next || current_a->value < current_b->next->value))
                {
                    best_target = current_b;
                    break;
                }
                current_b = current_b->next;
            }
        }
        if (!best_target)
            best_target = stack_b->top;
        current_a->target = best_target;
        current_a = current_a->next;
    }
}

// void ft_update_target_a(t_stack **stack_a, t_stack **stack_b)
// {
//     t_node *current_a;
//     t_node *current_b;
//     t_node *best_target;

//     if (!stack_a || !stack_b || (*stack_b)->size == 0)
//         return;
//     current_a = (*stack_a)->top;
//     while (current_a)
//     {
//         if (current_a->value < (*stack_b)->smallest->value)
//             best_target = (*stack_b)->smallest;
//         else if (current_a->value > (*stack_b)->biggest->value)
//             best_target = (*stack_b)->biggest;
//         else
//         {
//             current_b = (*stack_b)->top;
//             while (current_b)
//             {
//                 if (current_a->value > current_b->value &&
//                     (!current_b->next || current_a->value < current_b->next->value))
//                 {
//                     best_target = current_b;
//                     break;
//                 }
//                 current_b = current_b->next;
//             }
//         }
//         if (!best_target)
//             best_target = (*stack_b)->top;
//         current_a->target = best_target;
//         current_a = current_a->next;
//     }
// }

// void ft_update_target_b(t_stack *stack_a, t_stack *stack_b)
// {
//     t_node *current_b;
//     t_node *current_a;
//     t_node *best_target;

//     if (!stack_a || !stack_b || stack_a->size == 0 || stack_b->size == 0)
//         return;

    
//     current_b = stack_b->top;
//     printf("stack B top %d\n", stack_b->top->value);
//     while (current_b)
//     {
//         best_target = NULL;
//         current_a = stack_a->top;

//         // Find the smallest node in stack_a that is larger than current_b->value
//         while (current_a)
//         {
//             if (current_a->value > current_b->value)
//             {
//                 if (!best_target || current_a->value < best_target->value)
//                     best_target = current_a;
//             }
//             current_a = current_a->next;
//         }

//         // Fallback to the smallest node in stack_a if no larger node exists
//         if (!best_target)
//             best_target = stack_a->smallest;

//         // Update target for current_b
//         current_b->target = best_target;
//         printf("Updated target for B[%d]: %d\n", current_b->value, best_target->value);

//         current_b = current_b->next;
//     }
// }


//GOOD ONE
void ft_update_target_b(t_stack *stack_a, t_stack *stack_b)
{
    t_node *current_b;
    t_node *current_a;
    t_node *best_target;

    if (!stack_a || !stack_b || stack_a->size == 0 || stack_b->size == 0)
        return;
    current_b = stack_b->top;
    while (current_b)
    {
        best_target = NULL;
        current_a = stack_a->top;
        while (current_a)
        {
            if (current_a->value > current_b->value)
            {
                if (!best_target || current_a->value < best_target->value)
                    best_target = current_a;
            }
            current_a = current_a->next;
        }
        if (!best_target)
            best_target = stack_a->smallest;
        current_b->target = best_target;
        current_b = current_b->next;
    }
}

// void ft_update_target_b(t_stack **stack_a, t_stack **stack_b)
// {
// t_node *current_b;
//     t_node *current_a;
//     t_node *best_target;

//     if (!stack_a || !stack_b || (*stack_a)->size == 0 || (*stack_b)->size == 0)
//         return;
//     current_b = (*stack_b)->top;
//     while (current_b)
//     {
//         best_target = NULL;
//         current_a = (*stack_a)->top;
//         while (current_a)
//         {
//             if (current_a->value > current_b->value)
//             {
//                 if (!best_target || current_a->value < best_target->value)
//                     best_target = current_a;
//             }
//             current_a = current_a->next;
//         }
//         if (!best_target)
//             best_target = (*stack_a)->smallest;
//         current_b->target = best_target;
//         current_b = current_b->next;
//     }
// }


void ft_update_index(t_stack *stack)
{
    t_node *current;
    int i;

    i = 0;
    current = stack->top;
    while (current)
    {
        current->index = i;
        i++;
        current = current->next;
    }
}

void ft_update_node(t_stack **stack_a, t_stack **stack_b)
{
    ft_update_target_a(*stack_a, *stack_b);
    ft_update_target_b(*stack_a, *stack_b);
    ft_update_index(*stack_a);
    ft_update_index(*stack_b);
}
