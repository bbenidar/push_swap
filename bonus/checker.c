/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:03:18 by bbenidar          #+#    #+#             */
/*   Updated: 2023/03/13 02:16:35 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "./get_next_line/get_next_line.h"

void	ft_checking_2(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (!ft_strncmp(str, "pa\n", ft_strlen(str)))
		ft_pa(stack_a, stack_b, 0);
	else if (!ft_strncmp(str, "rr\n", ft_strlen(str)))
		ft_rr(stack_a, stack_b, 0);
	else if (!ft_strncmp(str, "ss\n", ft_strlen(str)))
		ft_ss(stack_a, stack_b, 0);
	else if (!ft_strncmp(str, "rrr\n", ft_strlen(str)))
		ft_rrr(stack_a, stack_b, 0);
	else
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}

int	ft_checking(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (!ft_strncmp(str, "sa\n", ft_strlen(str)))
		ft_sa(*stack_a, 0);
	else if (!ft_strncmp(str, "sb\n", ft_strlen(str)))
		ft_sb(*stack_b, 0);
	else if (!ft_strncmp(str, "ra\n", ft_strlen(str)))
		ft_ra(stack_a, 0);
	else if (!ft_strncmp(str, "rb\n", ft_strlen(str)))
		ft_rb(stack_b, 0);
	else if (!ft_strncmp(str, "rra\n", ft_strlen(str)))
		ft_rra(stack_a, 0);
	else if (!ft_strncmp(str, "rrb\n", ft_strlen(str)))
		ft_rrb(stack_b, 0);
	else if (!ft_strncmp(str, "pb\n", ft_strlen(str)))
		ft_pb(stack_a, stack_b, 0);
	else
		ft_checking_2(stack_a, stack_b, str);
	return (0);
}

int	check_instr(t_stack **stk_a, t_stack **stk_b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		ft_checking(stk_a, stk_b, str);
		str = get_next_line(0);
	}
	free(str);
	return (1);
}

void	checker_main_2(t_stack **stack_a, int len)
{
	if (check_sorting(stack_a) != len - 1)
	{
		ft_putstr_fd("KO", 1);
		del_stack(stack_a);
		exit(0);
	}
	del_stack(stack_a);
	ft_putstr_fd("OK", 1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;

	stack_a = copy_av(ac, av);
	if (!stack_a)
	{
		del_stack(&stack_a);
		write(1, "Error\n", 6);
		return (1);
	}
	ft_max(stack_a);
	len = s_len(stack_a);
	stack_b = NULL;
	if (!check_instr(&stack_a, &stack_b))
	{
		del_stack(&stack_a);
		del_stack(&stack_b);
		return (0);
	}
	checker_main_2(&stack_a, len);
	return (0);
}
