/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:16:40 by ryada             #+#    #+#             */
/*   Updated: 2025/02/03 11:34:08 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int main (int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    char **tab;

    stack_a = malloc(sizeof(t_stack));
    stack_b = malloc(sizeof(t_stack));
    if(!stack_a || !stack_b)
        return (ft_putstr_fd("Error\n", 2),1);
    if (argc == 2)
    {
        tab = ft_split(argv[1], ' ');
        if (!ft_error(2, tab))
        {
            ft_putstr_fd("Error\n", 2);
            ft_free_tab(tab);
            return (1);
        }
        ft_push_swap_turk(&stack_a, &stack_b, argc, tab);
        ft_free_tab(tab);
    }
    else
    {
        if (!ft_error(argc, argv))
            return (ft_putstr_fd("Error\n", 2), 1);
        ft_push_swap_turk(&stack_a, &stack_b, argc, argv);
    }
    ft_display_stack(stack_a, stack_b);
    printf("Count: %d\n", get_operation_count());
    ft_free_stack(stack_a);
    ft_free_stack(stack_b);
    return (0);
}

void ft_align_stack_a(t_stack **stack_a, t_stack **stack_b)
{
    if (!(*stack_a) || !(*stack_a)->smallest || (*stack_a)->size <= 1)
        return;
    if ((*stack_a)->smallest->index <= (*stack_a)->size / 2)
    {
        while ((*stack_a)->top != (*stack_a)->smallest)
        {
            ra(stack_a, stack_b, false); // Rotate upwards
            //ft_display_stack(*stack_a, *stack_b);
        }
    }
    else
    {
        while ((*stack_a)->top != (*stack_a)->smallest)
        {
            rra(stack_a, stack_b, false); // Rotate downwards
            //ft_display_stack(*stack_a, *stack_b);
        }
    }
}

void ft_sort_large_stack(t_stack **stack_a, t_stack **stack_b)
{
    ft_display_stack(*stack_a, *stack_b);
    while ((*stack_b)->size < 2)
    {  
        pb(stack_b, stack_a);
        ft_display_stack(*stack_a, *stack_b);
    }
    // Push all but 3 elements from A to B
    while ((*stack_a)->size > 3)
    {
        ft_before_pb(stack_a, stack_b);
        pb(stack_b, stack_a);
        ft_display_stack(*stack_a, *stack_b);
        // printf("-------------------------------------\n");
        // t_node *current_a = (*stack_a)->top;
        // while (current_a)
        // {
        //     printf("[%d]%d : (target)%d (cost)%d\n", current_a->index, current_a->value, current_a->target->value, current_a->cost);
        //     current_a = current_a->next;
        // }
        // printf("-------------------------------------\n");
        // ft_display_stack(*stack_a, *stack_b);
    }
    ft_before_pb(stack_a, stack_b);
    // Sort the remaining 3 elements in A
    ft_tiny_sort(stack_a, stack_b);
    // printf("After tiny sort:\n");
    // ft_display_stack(*stack_a, *stack_b);

    // Push elements back from B to A
    while ((*stack_b)->size > 0)
    {
        // printf("Pushing elements from B to A\n");
       // printf("Top B[%d] -> Target[%d]\n", (*stack_b)->top->value, (*stack_b)->top->target->value);
        ft_update_node(stack_a, stack_b);
        if ((*stack_b)->top->target->mid)
        {
            ft_display_stack(*stack_a, *stack_b);
            printf("Top B:%d   Target of top B: %d\n", (*stack_b)->top->value, (*stack_b)->top->target->value);
            while ((*stack_a)->top != (*stack_b)->top->target)
            {
                ra(stack_a, stack_b, false);
                // ft_display_stack(*stack_a, *stack_b);
            }
        }
        else
        {
            while ((*stack_a)->top != (*stack_b)->top->target)
            {
                rra(stack_a, stack_b, false);
                // ft_display_stack(*stack_a, *stack_b);
            }
        }
        pa(stack_a, stack_b);
        // ft_display_stack(*stack_a, *stack_b);
    }
    //printf("A smallest %d\n", (*stack_a)->smallest->value);
    // Align the smallest element in A at the top
    ft_display_stack(*stack_a, *stack_b);
    if (!ft_is_sorted(*stack_a))
        ft_align_stack_a(stack_a, stack_b);
}

void ft_push_swap_turk(t_stack **stack_a, t_stack **stack_b, int argc, char **argv)
{
    // Initialize stacks
    ft_ini_stack(*stack_a);
    ft_ini_stack(*stack_b);
    ft_fill_stack(*stack_a, argc, argv);
    if (ft_is_sorted(*stack_a))
        return;
    if ((*stack_a)->size > 3)
        ft_sort_large_stack(stack_a, stack_b);
    else
        ft_tiny_sort(stack_a, stack_b); // Sort small stack
}


// void ft_sort_large_stack(t_stack **stack_a, t_stack **stack_b)
// {
//     // Push all but 3 elements from A to B
//     while ((*stack_a)->size > 3)
//     {
//         ft_find_cheapest(*stack_a, *stack_b);
//         ft_cheapest_to_top(stack_a, stack_b);
//         //ft_display_stack(*stack_a, *stack_b);
//         pb(stack_b, stack_a);
//         //ft_display_stack(*stack_a, *stack_b);
//     }
//     //printf("HERE\n");
//     //ft_display_stack(*stack_a, *stack_b);
//     // Sort remaining 3 elements in A
//     ft_tiny_sort(stack_a, stack_b);
//     // Push back elements from B to A in sorted order
//     while ((*stack_b)->size > 0)
//     {
//         if ((*stack_a)->top == (*stack_b)->top->target)
//         {
//             pa(stack_a, stack_b);
//             //ft_display_stack(*stack_a, *stack_b);
//         }
//         else if ((*stack_b)->top->target->index < (*stack_a)->size / 2)
//         {
//             while ((*stack_a)->top != (*stack_b)->top->target)
//             {
//                 ra(stack_a, stack_b, false);
//                 //ft_display_stack(*stack_a, *stack_b);
//             }
//         }
//         else
//         {
//             while ((*stack_a)->top != (*stack_b)->top->target)
//             {
//                 rra(stack_a, stack_b, false);
//                 //ft_display_stack(*stack_a, *stack_b);
//             }
                
//         }
//         pa(stack_a, stack_b);
//         //ft_display_stack(*stack_a, *stack_b);
//     }
//     // Rotate A to align the smallest element at the top
//     //if (!ft_is_sorted(*stack_a))
//         //ft_align_stack_a(stack_a, stack_b);
// }

        

// //NO DISPLAY
// void ft_push_swap_turk(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
// {
//     ft_ini_stack(stack_a);
//     ft_ini_stack(stack_b);
//     ft_fill_stack(stack_a, argc, argv);
//     if (ft_is_sorted(stack_a))
//         return;
//     if (stack_a->size > 3)
//     {
//         while (stack_a->size != 3 && stack_b->size != 2)
//             pb(stack_b, stack_a);
//         while(stack_a->size > 3)
//         {
//             ft_find_cheapest(stack_a, stack_b);
//             //printf("cheapest:%d\n", stack_a->cheapest->value);
//             ft_cheapest_to_top(stack_a, stack_b);

//             pb(stack_b, stack_a);
//         }
//         ft_tiny_sort(stack_a, stack_b);
//         while (stack_b->size > 0)
//         {
//             if (stack_a->top == stack_b->top->target)
//             {
//                 pa(stack_a, stack_b);
//             }
//             else
//             {
//                 if (stack_b->top->target->index < stack_a->size / 2)
//                 {
//                     while (stack_a->top != stack_b->top->target)
//                     {
//                         ra(stack_a, stack_b, false);
//                     } 
//                 }
//                 else
//                 {
//                     while (stack_a->top != stack_b->top->target)
//                     {
//                         rra(stack_a, stack_b, false); 
//                     }
//                 }
//                 pa(stack_a, stack_b);
//             }
//         }
//         //Sort A
//         if (stack_a->smallest->index < stack_a->size / 2)
//         {
//             while (stack_a->top != stack_a->smallest)
//             {
//                 ra(stack_a, stack_b,false);
//             }
//         }
//         else
//         {
//             while (stack_a->top != stack_a->smallest)
//             {
//                 rra(stack_a, stack_b,false);
//             }
                
//         }
//     }
//     else
//         ft_tiny_sort(stack_a, stack_b);
// }
