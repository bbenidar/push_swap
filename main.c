/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:51:30 by bbenidar          #+#    #+#             */
/*   Updated: 2023/03/10 22:31:18 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_join_av(char **av, int ac)
{
	int		i;
	char	*tr1;
	char	**str1;

	i = 1;
	tr1 = ft_strjoin(ft_strdup(av[i++]), " ");
	while (i < ac)
	{
		if (check_space(av[i]))
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		tr1 = ft_strjoin(tr1, " ");
		tr1 = ft_strjoin(tr1, av[i]);
		i++;
	}
        printf("hadikdd : %s\n", tr1);
	str1 = ft_split(tr1, ' ');
	free(tr1);
    // int c = 0;
    // while(str1[c])
    // printf("hadikdd : %s\n", str1[c++]);
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

	stack_a = copy_av(ac, av);
	if (!stack_a)
	{
		del_stack(&stack_a);
		write(1, "Error\n", 6);
		return (1);
	}
    while(stack_a)
    {
        printf("num : %d\n", stack_a->num);
        stack_a = stack_a->next;
    }
	// ft_max(stack_a);
	// len = s_len(stack_a);
	// if (check_sorting(&stack_a) == len - 1)
	// {
	// 	del_stack(&stack_a);
	// 	return (0);
	// }
	// stack_b = NULL;
	// main_two(stack_a, stack_b, len);
	return (0);
}
