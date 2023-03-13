/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:46:44 by bbenidar          #+#    #+#             */
/*   Updated: 2023/03/11 15:39:56 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freetab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

t_stack	*ft_new_node(void)
{
	t_stack	*begin;

	begin = (t_stack *)malloc(sizeof(t_stack));
	if (!begin)
		return (NULL);
	begin->num = 0;
	begin->end = -1;
	begin->next = NULL;
	return (begin);
}

int	copy_av2(t_stack *begin, char **str, int i)
{
	if (check_av(str[i]))
	{
		ft_freetab(str);
		del_stack(&begin);
		return (0);
	}
	return (1);
}

void	copy_av3(t_stack **tmp, int i, char **str)
{
	int		jen;

	jen = ft_lentab(str);
	if (i < jen - 1)
	{
		(*tmp)->next = ft_new_node();
		(*tmp) = (*tmp)->next;
		(*tmp)->end = -1;
	}
}

t_stack	*copy_av(int ac, char **av)
{
	t_stack	*begin;
	t_stack	*tmp;
	char	**str;
	int		i;
	int		len;

	begin = ft_new_node();
	str = ft_join_av(av, ac);
	len = ft_lentab(str);
	tmp = begin;
	i = 0;
	while (i < len)
	{
		if (!copy_av2(begin, str, i))
			return (0);
		tmp->num = ft_atoi(str[i]);
		copy_av3(&tmp, i, str);
		i++;
	}
	ft_check_deplicat(&begin);
	ft_freetab(str);
	return (begin);
}
