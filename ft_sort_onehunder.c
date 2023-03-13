/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_onehunder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 00:02:42 by bbenidar          #+#    #+#             */
/*   Updated: 2023/03/12 18:50:52 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_onehunder_3(t_stack **stack_a, t_stack **stack_b, int len,
		int akhna)
{
	while (*stack_b && ft_position((*stack_b), len - 1)
		&& ft_position((*stack_b), len - 1) < len / 2)
	{
		if (!akhna && len - 2 >= 0 && !ft_position((*stack_b), len - 2))
		{
			ft_pa(stack_a, stack_b, 1);
			akhna = 1;
		}
		ft_rb(stack_b, 1);
	}
	while (*stack_b && ft_position((*stack_b), len - 1)
		&& ft_position((*stack_b), len - 1) >= len / 2)
	{
		if (!akhna && len - 2 >= 0 && !ft_position((*stack_b), len - 2))
		{
			ft_pa(stack_a, stack_b, 1);
			akhna = 1;
		}
		ft_rrb(stack_b, 1);
	}
}

void	ft_sort_onehunder_2(t_stack **stack_a, t_stack **stack_b, int chink,
		int end)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (*stack_a)
	{
		while (i < chink && (*stack_a))
		{
			if ((*stack_a) && (*stack_a)->end <= end)
			{
				ft_pb(stack_a, stack_b, 1);
				i++;
				another_one(stack_a, stack_b, end, start);
			}
			else
				ft_ra(stack_a, 1);
		}
		i = 0;
		start += chink;
		end += chink;
	}
}

void	ft_sort_onehunder(t_stack **stack_a, t_stack **stack_b, int chink)
{
	int	i;
	int	start;
	int	end;
	int	akhna;
	int	len;

	i = 0;
	start = 0;
	end = chink - 1;
	ft_sort_onehunder_2(stack_a, stack_b, chink, end);
	while (*stack_b)
	{
		len = s_len(*stack_b);
		akhna = 0;
		ft_sort_onehunder_3(stack_a, stack_b, len, akhna);
		if (*stack_b && !ft_position((*stack_b), len - 1))
		{
			ft_pa(stack_a, stack_b, 1);
			if ((*stack_a)->next && (*stack_a)->num > (*stack_a)->next->num)
				ft_sa(*stack_a, 1);
		}
	}
}
