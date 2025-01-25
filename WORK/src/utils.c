#include "../includes/push_swap.h"

void ft_ini_stack(t_stack *stack_a, t_stack *stack_b)
{
    stack_a->top = NULL;
    stack_a->bottom = NULL;
    stack_a->size = 0;
    stack_a->biggest = NULL;
    stack_a->smallest = NULL;

    stack_b->top = NULL;
    stack_b->bottom = NULL;
    stack_b->size = 0;
    stack_b->biggest = NULL;
    stack_b->smallest = NULL;
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

void ft_push(t_stack *stack, int value, int to_top)
{
    t_node *new_node;

    new_node = malloc(sizeof(t_node));
    if (!new_node)
    {
        ft_putstr_fd("Error\n", 2);
        return;
    }
    new_node->value = value;
    new_node->next = NULL;
    if (to_top || !stack->top)
    {
        new_node->next = stack->top;
        stack->top = new_node;
        if (!stack->bottom)
            stack->bottom = new_node;
    }
    else
    {
        stack->bottom->next = new_node;
        stack->bottom = new_node;
    }
}

void ft_push(t_stack *stack, int value, int to_top)
{
    t_node *new_node;

    new_node = malloc(sizeof(t_node));
    if (!new_node)
    {
        ft_putstr_fd("Error\n", 2);
        return;
    }
    new_node->value = value;
    new_node->next = NULL;
    if (to_top || !stack->top)
    {
        new_node->next = stack->top;
        stack->top = new_node;
        if (!stack->bottom)
            stack->bottom = new_node;
    }
    else
    {
        stack->bottom->next = new_node;
        stack->bottom = new_node;
    }
}