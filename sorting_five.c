/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 01:10:19 by bbenidar          #+#    #+#             */
/*   Updated: 2023/03/12 18:52:17 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_max(t_stack *stack)
{
	int		i;
	t_stack	*tmp;
	t_stack	*tmp2;

	i = 0;
	tmp = stack;
	tmp->end = i;
	while (tmp)
	{
		i = 0;
		tmp->end = i;
		tmp2 = stack;
		while (tmp2)
		{
			if (tmp->num > tmp2->num)
				tmp->end = ++i;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

int	ft_position(t_stack *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->end == index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (0);
}

void	ft_ind(t_stack **stack_a, t_stack **stack_b, int index)
{
	while (ft_position(*stack_a, index) > 0 && ft_position(*stack_a,
			index) >= s_len(*stack_a) / 2)
		ft_rra(stack_a, 1);
	while (ft_position(*stack_a, index) > 0 && ft_position(*stack_a,
			index) <= s_len(*stack_a) / 2)
		ft_ra(stack_a, 1);
	if (!ft_position(*stack_a, index))
		ft_pb(stack_a, stack_b, 1);
}

void	ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_position(stack_a, 0) >= 0 && stack_a)
		ft_ind(&stack_a, &stack_b, 0);
	if (ft_position(stack_a, 1) >= 0 && stack_a)
		ft_ind(&stack_a, &stack_b, 1);
	if (s_len(stack_a) <= 3 && stack_a)
		short_sort(&stack_a, s_len(stack_a));
	ft_pa(&stack_a, &stack_b, 1);
	ft_pa(&stack_a, &stack_b, 1);
}
