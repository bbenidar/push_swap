/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:44:33 by bbenidar          #+#    #+#             */
/*   Updated: 2023/02/02 00:25:29 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int s_len(t_stack *stack)
{
    int i;
    t_stack *tmp;

    i = 0;
    tmp = stack;
    while(tmp)
    {
        tmp = tmp->next;
        i++;
    }
    return (i);
}

int *copy_stack_to_array(t_stack *stack, int len)
{
    int *array;
    int i;

    i = 0;
    array = (int *)malloc(sizeof(int) * len);
    while(i < len)
    {
        array[i] = stack->num;
        stack = stack->next;
        i++;
    }
    return (array);
}

void del_stack(t_stack **stack)
{
    t_stack *del;
    t_stack *tmp;

    tmp = *stack;
    while(tmp)
    {
        del =tmp;
        tmp = tmp->next;
        free (del); 
    }
    *stack = NULL;
}