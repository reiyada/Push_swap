/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rei <rei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:45:49 by ryada             #+#    #+#             */
/*   Updated: 2025/01/24 17:03:42 by rei              ###   ########.fr       */
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
int ft_check_digit(int argc, char **argv)
{
    int i;
    int j;
    if (argc == 2)
        i = 0;
    else
        i = 1;
    while(argv[i])
    {
        j = 0;
        while (argv[i][j] == ' ' || (argv[i][j] >= 9 && argv[i][j] <= 13))
            j++;
        if (argv[i][j] == '\0')
            return (0);
        if (argv[i][j] == '-' || argv[i][j] == '+')
        {
            if (argv[i][j + 1] == '\0')
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
int ft_check_range(int argc, char **argv)
{
    int i;
    int len;

    if (argc == 2)
        i = 0;
    else
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
int ft_check_dup(int argc, char **argv)
{
    int i;
    int j;

    if (argc == 2)
        i = 0;
    else
        i = 1;
    while (argv[i])
    {
        j = i + 1;
        while (argv[j])
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int ft_error(int argc, char **argv)
{
    if (!ft_check_argc(argc))
        return (0);
    if (!ft_check_digit(argc, argv))
        return (0);
    else if (!ft_check_range(argc, argv))
        return (0);
    else if (!ft_check_dup(argc, argv))
        return (0);
    return (1);
}
