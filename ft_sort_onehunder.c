/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_onehunder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 00:02:42 by bbenidar          #+#    #+#             */
/*   Updated: 2023/02/13 17:02:52 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void ft_do_push()

void ft_sort_onehunder(t_stack **stack_a, t_stack **stack_b)
{
    int i;
    int index;
    int moyen;
    
    int chunk = 20; 
    i = -1;
    index = chunk;
    moyen = index / 2;
    while(*stack_a)
    {
             while(++i < chunk && *stack_a)
             {
                while(ft_position((*stack_a), chunk) < ft_lstsize(*stack_a) / 2 && (*stack_a)->end > chunk)
                    ft_ra(stack_a, 1);
                while(ft_position((*stack_a), chunk) >= ft_lstsize(*stack_a) / 2 && (*stack_a)->end > chunk)
                    ft_rra(stack_a);
                if ( (*stack_a)->end > chunk - moyen)
                    ft_do_push();
                    
             }
                    
            
    }
   printf("count : %d\n", count);
    
}