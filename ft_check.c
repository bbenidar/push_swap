/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:38:03 by bbenidar          #+#    #+#             */
/*   Updated: 2023/02/05 15:54:14 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void ft_check_deplicat(t_stack **stack)
{
    int *array;
    int len;
    int i;
    int j;

    i = 0;
    len = s_len(*stack);
    array = copy_stack_to_array(*stack, len);
    while(i < len)
    {
        j = i;
        while(++j < len)
        {
            if(array[i] == array[j])
            {
                del_stack(stack);
                free(array);
                write(1, "ERORR\n", 6);
                exit(1);
            }
        }
        i++;
    }
    free(array); 
}

int check_overflow(char *str)
{
    if(str[0] == '-')
    {
        if(ft_atoi(str) > 0)
            return(1);
    }
    if(str[0] != '-')
    {
        if(ft_atoi(str) < 0)
            return (1);
    }
    return (0);
}

int ft_lentab(char **str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

int check_av(char *str)
{
    int i;
    int len;

    i = 0;
    while(str[i] == ' ' || str[i] ==  9)
        i++;
    if ((str[i] == '-' || str[i] == '+')  && !ft_isdigit(str[i + 1]))
        return (1);
    if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
        i++;
    len = ft_strlen(&str[i]);
    if(len == 0)
        return (1);
    while(str[i])
    {
        if(!ft_isdigit(str[i]))
            return (1);
        i++;
    }
    if (len == 10 && check_overflow(str))
        return (1);
    return (0); 
}

int check_space(char *str)
{
    int i;
    int len;

    i = 0;
    while(str[i] == ' ')
        i++;
    len = ft_strlen(&str[i]);
    if (len == 0)
        return (1);
    return (0);
}