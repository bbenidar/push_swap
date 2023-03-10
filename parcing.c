/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:46:44 by bbenidar          #+#    #+#             */
/*   Updated: 2023/03/10 22:29:35 by bbenidar         ###   ########.fr       */
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

t_stack	*copy_av(int ac, char **av)
{
	t_stack	*begin;
	t_stack	*tmp;
	char	**str;
	int		i;
	int		len;

	i = 1;
	begin = ft_new_node();
	str = ft_join_av(av, ac);
	len = ft_lentab(str);
	tmp = begin;
	i = 1;
	while (i < len)
	{
		if (check_av(str[i]))
		{
			ft_freetab(str);
			del_stack(&begin);
			return (0);
		}
		tmp->num = ft_atoi(str[i]);
		if (i < ac - 1)
		{
			tmp->next = ft_new_node();
			tmp = tmp->next;
			tmp->end = -1;
		}
		i++;
	}
	ft_check_deplicat(&begin);
	ft_freetab(str);
	return (begin);
}