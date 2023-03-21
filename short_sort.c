/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:36:16 by bbenidar          #+#    #+#             */
/*   Updated: 2023/03/16 14:12:38 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_tlata_2(t_stack **stack)
{
	if ((*stack)->num < (*stack)->next->num)
	{
		if ((*stack)->num < (*stack)->next->next->num)
		{
			if ((*stack)->next->num < (*stack)->next->next->num)
				return ;
			else
			{
				ft_sa(*stack, 1);
				ft_ra(stack, 1);
			}
		}
		else if ((*stack)->num > (*stack)->next->next->num)
			ft_rra(stack, 1);
	}
}

void	short_tlata(t_stack **stack)
{
	if ((*stack)->num > (*stack)->next->num)
	{
		if ((*stack)->num < (*stack)->next->next->num)
			ft_sa(*stack, 1);
		else if ((*stack)->num > (*stack)->next->next->num)
		{
			if ((*stack)->next->num > (*stack)->next->next->num)
			{
				ft_sa(*stack, 1);
				ft_rra(stack, 1);
			}
			else if ((*stack)->next->num < (*stack)->next->next->num)
				ft_ra(stack, 1);
		}
	}
	else
		short_tlata_2(stack);
}

void	short_sort(t_stack **stack, int len)
{
	if (len == 1)
		return ;
	if (len == 2 && (*stack)->num > (*stack)->next->num)
		ft_sa(*stack, 1);
	if (len == 3)
		short_tlata(stack);
	return ;
}
