/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rei <rei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:45:49 by ryada             #+#    #+#             */
/*   Updated: 2025/01/03 22:32:16 by rei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//No arguments provided
int ft_check_argc(int argc)
{
    if (argc < 2)
        return (0);
    return (1);
}

//Non-integer arguments
int ft_check_digit(char **argv)
{
    int i;
    int j;
    i = 1;
    while(argv[i])
    {
        j = 0;
        while (argv[i][j] == ' ' || (argv[i][j] >= 9 && argv[i][j] <= 13))
            j++;
        if (argv[i][j] == '\0')
            return (0);
        if (argv[i][0] == '-' || argv[i][0] == '+')
        {
            if (argv[i][j] == '\0')
                return (0);
            j++;
        }
        while(argv[i][j])
        {
            if (!ft_isdigit(argv[i][j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

//Overflow or Underflow
int ft_check_range(char **argv)
{
    int i;
    int len;

    i = 1;
    while (argv[i])
    {
        len = ft_strlen(argv[i]);
        if (len > 11)
            return (0);
        if (len == 11)
        {
            if (argv[i][0] == '-' && ft_strncmp(argv[i], "-2147483648", 11) > 0)
                return (0);
            else if (argv[i][0] != '-' && argv[i][0] != '+')
                return (0);
        }
        else if (len == 10)
        {
            if (ft_strncmp(argv[i], "2147483647", 10) > 0)
                return (0);
        }
        i++;
    }
    return (1);
}


//Duplicate numbers
int ft_check_dup(char **argv)
{
    int i;
    int j;

    i = 1;
    while (argv[i])
    {
        j = i + 1;
        while (argv[j])
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
                return (0);
            else
                j++;
        }
        i++;
    }
    return (1);
}

int ft_error(int argc, char **argv)
{
    if (ft_check_argc(argc) == 0)
        return (0);
    else if (ft_check_digit(argv) == 0)
        return (0);
    else if (ft_check_range(argv) == 0)
        return (0);
    else if (ft_check_dup(argv) == 0)
        return (0);
    return (1);
}
