#include "../includes/push_swap.h"

void ft_ini_stack(t_stack *stack)
{
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;
    stack->biggest = NULL;
    stack->smallest = NULL;
}

t_node *ft_ini_node(int value)
{
    t_node *new_node;

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

//to_top
// 0: 1 2 3 4 5 -> 1 2 3 4 5
// 1: 1 2 3 4 5 -> 5 4 3 2 1
void ft_set_next(t_stack *stack, t_node *node, int to_top)
{
    if(to_top || !stack->top)
        node->next = stack->top;
    else if (stack->bottom)
        stack->bottom->next = node;
}

void ft_set_top_bottom(t_stack *stack, t_node *node)
{
    if (!stack->top)
    {
        stack->top = node;
        stack->bottom = node;
    }
    else
    {
        stack->bottom->next = node;
        stack->bottom = node;
    }
}

void ft_set_index(t_stack *stack)
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

void ft_push(t_stack *stack_a, int value, int to_top)
{
    t_node *new_node;

    new_node = ft_ini_node(value);
    if (!new_node)
        return (ft_putstr_fd("Error\n", 2));
    ft_set_next(stack_a, new_node, to_top);
    ft_set_top_bottom(stack_a, new_node);
    ft_set_index(stack_a);
    stack_a->size++;
}

void ft_fill_stack(t_stack *stack_a, int argc, char **argv)
{
    int i;
    int size;
    int value;

    if (argc == 2)
    {
        i = 0;
        size = ft_countstr(argv);
    }
    else
    {
        i = 1;
        size = argc;
    }
    while (i < size)
    {
        value = ft_atoi(argv[i]);
        ft_push(stack_a, value, 0);
        i++;
    }
}


// void ft_push(t_stack *stack, int value, int to_top)
// {
//     t_node *new_node;

//     new_node = malloc(sizeof(t_node));
//     if (!new_node)
//     {
//         ft_putstr_fd("Error\n", 2);
//         return;
//     }
//     new_node->value = value;
//     new_node->next = NULL;
//     if (to_top || !stack->top)
//     {
//         new_node->next = stack->top;
//         stack->top = new_node;
//         if (!stack->bottom)
//             stack->bottom = new_node;
//     }
//     else
//     {
//         stack->bottom->next = new_node;
//         stack->bottom = new_node;
//     }
// }

// void ft_set_biggest_smallest(t_stack *stack)
// {
//     if (!stack || !stack->top)
//         return;

//     t_node *current = stack->top;
//     stack->biggest = current;
//     stack->smallest = current;

//     while (current)
//     {
//         if (current->value > stack->biggest->value)
//             stack->biggest = current;
//         if (current->value < stack->smallest->value)
//             stack->smallest = current;
//         current = current->next;
//     }
// }