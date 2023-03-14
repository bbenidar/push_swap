/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:56:35 by bbenidar          #+#    #+#             */
/*   Updated: 2023/03/13 23:52:16 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sing(const char *str, int *hi)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	*hi = i;
	return (sign);
}

long long	ft_atol(const char *str)
{
	int			sign;
	long long	result;
	int			i;

	result = 0;
	i = 0;
	sign = ft_sing(str, &i);
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	result *= sign;
	return (result);
}

void	check_empty(char *str)
{
	if (check_space(str))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}

char	**ft_join_av(char **av, int ac)
{
	int		i;
	char	*tr1;
	char	**str1;

	i = 1;
	tr1 = ft_strjoin(ft_strdup(av[i]), " ");
	check_empty(av[i++]);
	while (i < ac)
	{
		check_empty(av[i]);
		tr1 = ft_strjoin(tr1, " ");
		tr1 = ft_strjoin(tr1, av[i]);
		i++;
	}
	str1 = ft_split(tr1, ' ');
	free(tr1);
	return (str1);
}

int	check_sorting(t_stack **stack_a)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->num < tmp->next->num)
			i++;
		tmp = tmp->next;
	}
	return (i);
}
