/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:56:07 by bbenidar          #+#    #+#             */
/*   Updated: 2023/03/13 00:49:56 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrb(t_stack **stack, int i)
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
		ft_putstr_fd("rrb\n", 1);
}

void	ft_rb(t_stack **stack, int i)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*head;

	if (s_len(*stack) <= 1)
		return ;
	head = (*stack)->next;
	last = ft_lstlast2(*stack);
	tmp = *stack;
	last->next = tmp;
	tmp->next = NULL;
	(*stack) = head;
	if (i)
		ft_putstr_fd("rb\n", 1);
}

void	ft_ra(t_stack **stack, int i)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*head;

	if (s_len(*stack) <= 1)
		return ;
	head = (*stack)->next;
	last = ft_lstlast2(*stack);
	tmp = *stack;
	last->next = tmp;
	tmp->next = NULL;
	(*stack) = head;
	if (i)
		ft_putstr_fd("ra\n", 1);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b, int i)
{
	t_stack	*tmp;
	t_stack	*head;

	if (!stack_a)
		return ;
	tmp = *stack_b;
	head = (*stack_a)->next;
	*stack_b = *stack_a;
	*stack_a = head;
	(*stack_b)->next = tmp;
	if (i)
		ft_putstr_fd("pb\n", 1);
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b, int i)
{
	t_stack	*tmp;
	t_stack	*head;

	if (!(*stack_b))
		return ;
	tmp = *stack_a;
	head = (*stack_b)->next;
	*stack_a = *stack_b;
	*stack_b = head;
	(*stack_a)->next = tmp;
	if (i)
		ft_putstr_fd("pa\n", 1);
}
