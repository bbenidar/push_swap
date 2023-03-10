/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_fivehndr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 00:44:33 by bbenidar          #+#    #+#             */
/*   Updated: 2023/03/10 18:50:02 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_fivehunder(t_stack **stack_a, t_stack **stack_b, int chink)
{
	int	i;
	int	len;
	int	akhna;
	int	start;
	int	end;

	i = 0;
	start = 0;
	end = chink - 1;
	akhna = 0;
	while (*stack_a)
	{
		while (i < chink && (*stack_a))
		{
			if ((*stack_a) && (*stack_a)->end <= end)
			{
				ft_pb(stack_a, stack_b);
				i++;
				if ((*stack_b)->end > (end + start) / 2)
				{
					if (*stack_a && (*stack_a)->end > end)
						ft_rr(stack_a, stack_b);
					else
						ft_rb(stack_b, 1);
				}
			}
			else
				ft_ra(stack_a, 1);
		}
		i = 0;
		start += chink;
		end += chink;
	}
	while (*stack_b)
	{
		len = s_len(*stack_b);
		akhna = 0;
		while (*stack_b && ft_position((*stack_b), len - 1)
			&& ft_position((*stack_b), len - 1) < len / 2)
		{
			if (!akhna && len - 2 >= 0 && !ft_position((*stack_b), len - 2))
			{
				ft_pa(stack_a, stack_b);
				akhna = 1;
			}
			ft_rb(stack_b, 1);
		}

		while (*stack_b && ft_position((*stack_b), len - 1)
			&& ft_position((*stack_b), len - 1) >= len / 2)
		{
			if (!akhna && len - 2 >= 0 && !ft_position((*stack_b), len - 2))
			{
				ft_pa(stack_a, stack_b);
				akhna = 1;
			}
			ft_rrb(stack_b);
		}

		if (*stack_b && !ft_position((*stack_b), len - 1))
		{
			ft_pa(stack_a, stack_b);
			if ((*stack_a)->next && (*stack_a)->num > (*stack_a)->next->num)
				ft_sa(*stack_a);
		}
	}
}