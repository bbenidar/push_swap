/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:02:04 by bbenidar          #+#    #+#             */
/*   Updated: 2023/03/12 19:31:31 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast2(t_stack *lst)
{
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sa(t_stack *stack, int i)
{
	if (s_len(stack) <= 1)
		return ;
	ft_swap(&stack->num, &stack->next->num);
	ft_swap(&stack->end, &stack->next->end);
	if (i)
		ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack *stack, int i)
{
	if (s_len(stack) <= 1)
		return ;
	ft_swap(&stack->num, &stack->next->num);
	ft_swap(&stack->end, &stack->next->end);
	if (i)
		ft_putstr_fd("sb\n", 1);
}

void	ft_rra(t_stack **stack, int i)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*head;

	if (s_len(*stack) <= 1)
		return ;
	head = *stack;
	last = ft_lstlast2(*stack);
	tmp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = head;
	(*stack) = last;
	if (i)
		ft_putstr_fd("rra\n", 1);
}
