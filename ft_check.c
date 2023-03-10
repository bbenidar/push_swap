/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:38:03 by bbenidar          #+#    #+#             */
/*   Updated: 2023/03/10 22:26:29 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_deplicat(t_stack **stack)
{
	int	*array;
	int	len;
	int	i;
	int	c = 0;
    
	int	j;

	i = 0;
	len = s_len(*stack);
	array = copy_stack_to_array(*stack, len);
    while(array[c])
        printf("hadik : %d\n", array[c++]);
	while (i <= len)
	{
		j = i;
		while (++j < len)
		{
			if (array[i] == array[j])
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

int	check_overflow(char *str)
{
	if (str[0] == '-')
	{
		if (ft_atoi(str) > 0)
			return (1);
	}
	if (str[0] != '-')
	{
		if (ft_atoi(str) < 0)
			return (1);
	}
	return (0);
}

int	ft_lentab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_av(char *str)
{
	int	i;
	int	len;

	i = 0;
	while (str[i] == ' ' || str[i] == 9)
		i++;
	if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1]))
		return (1);
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
		i++;
	len = ft_strlen(&str[i]);
	if (len == 0)
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	if (len == 10 && check_overflow(str))
		return (1);
	return (0);
}

int	check_space(char *str)
{
	int	i;
	int	len;

	i = 0;
	while (str[i] == ' ')
		i++;
	len = ft_strlen(&str[i]);
	if (len == 0)
		return (1);
	return (0);
}
// int copy_av2(t_stack *begin, char **str, int i)
// {
// 		if (check_av(str[i]))
// 		{
// 			ft_freetab(str);
// 			del_stack(&begin);
// 			return (0);
// 		}
// 		return (1);
// }
// void copy_av3(t_stack **tmp, char **str, int i, int ac)
// {
// 		(*tmp)->num = ft_atoi(str[i]);
// 		if (i < ac - 1)
// 		{
// 			(*tmp)->next = ft_new_node();
// 			*tmp = (*tmp)->next;
// 			(*tmp)->end = -1;
// 		}
// }