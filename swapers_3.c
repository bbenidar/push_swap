/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapers_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:03:23 by bbenidar          #+#    #+#             */
/*   Updated: 2023/03/13 02:15:16 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (s_len(*stack_a) <= 1 || s_len(*stack_b) <= 1)
		return ;
	ft_ra(stack_a, 0);
	ft_rb(stack_b, 0);
	if (i)
		ft_putstr_fd("rr\n", 1);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (s_len(*stack_a) <= 1 || s_len(*stack_b) <= 1)
		return ;
	ft_sa(*stack_a, 0);
	ft_sb(*stack_b, 0);
	if (i)
		ft_putstr_fd("ss\n", 1);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (s_len(*stack_a) <= 1 || s_len(*stack_b) <= 1)
		return ;
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	if (i)
		ft_putstr_fd("rrr\n", 1);
}
