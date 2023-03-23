/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:51:30 by bbenidar          #+#    #+#             */
/*   Updated: 2023/03/21 17:00:47 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_two(t_stack *stack_a, t_stack *stack_b, int len)
{
	if (len < 4)
	{
		short_sort(&stack_a, len);
		del_stack(&stack_a);
	}
	else if (len <= 5)
	{
		ft_sort_five(stack_a, stack_b);
		del_stack(&stack_a);
	}
	else if (len <= 100)
	{
		ft_sort_onehunder(&stack_a, &stack_b, len / 5);
		del_stack(&stack_a);
	}
	else
	{
		ft_sort_fivehunder(&stack_a, &stack_b, len / 9);
		del_stack(&stack_a);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;

	if (ac < 2)
		return (0);
	stack_a = copy_av(ac, av);
	if (!stack_a)
	{
		del_stack(&stack_a);
		write(1, "Error\n", 6);
		return (1);
	}
	ft_max(stack_a);
	len = s_len(stack_a);
	if (check_sorting(&stack_a) == len - 1)
	{
		del_stack(&stack_a);
		return (0);
	}
	stack_b = NULL;
	main_two(stack_a, stack_b, len);
	return (0);
}
