/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:45:49 by ryada             #+#    #+#             */
/*   Updated: 2024/12/30 17:23:39 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int ft_check_argc(int argc)
{
    if (argc < 2)
        return (0);
    return (1);
}

int ft_check_digit(char **argv)
{
    int i;
    int j;
    i = 1;
    while(argv[i])
    {
        if (argv[i][0] == '-')
            j = 1;
        else
            j = 0;
        while(argv[i][j])
        {
            if (ft_isdigit(argv[i][j]) == 1)
                j++;
            else
                return (0);
        }
        i++;
    }
    return (1);
}

int ft_check_range(char **argv)
{
    long int digit;
    int i;
    i = 1;
    while (argv[i])
    {
        digit = ft_atoi(argv[i]);
        if(digit < -2147483648 || digit > 2147483647)
            return (0);
        i++;
    }
    return (1);
}
