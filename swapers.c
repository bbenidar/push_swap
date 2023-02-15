/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:56:07 by bbenidar          #+#    #+#             */
/*   Updated: 2023/02/12 18:20:37 by bbenidar         ###   ########.fr       */
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
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void ft_sa(t_stack *stack)
{
    ft_swap(&stack->num, &stack->next->num);
    write(1, "sa\n", 3);
}

void ft_sb(t_stack *stack)
{
    ft_swap(&stack->num, &stack->next->num);
    write(1, "sb\n", 3);
}

void ft_rra(t_stack **stack)
{
    t_stack *tmp;
    t_stack *last;
    t_stack *head;
   
    head = *stack;
    last = ft_lstlast2(*stack);
    tmp = *stack;
    while(tmp->next->next != NULL)
        tmp = tmp->next;
    tmp->next = NULL;
    last->next = head;
    (*stack) = last;
    write(1, "rra\n", 4);
   
    
}

void ft_rrb(t_stack **stack)
{
        t_stack *tmp;
    t_stack *last;
    t_stack *head;
   
    head = *stack;
    last = ft_lstlast2(*stack);
    tmp = *stack;
    while(tmp->next->next != NULL)
        tmp = tmp->next;
    tmp->next = NULL;
    last->next = head;
    (*stack) = last;
    write(1, "rrb\n", 4);
}

void ft_rb(t_stack **stack, int i)
{
    t_stack *tmp;
    t_stack *last;
    t_stack *head;
    head = (*stack)->next;
    last = ft_lstlast2(*stack);
    tmp = *stack;
    last->next = tmp;
    tmp->next = NULL;
    (*stack) = head;
    if(i)
        write(1, "rb\n", 4);
}
void ft_ra(t_stack **stack, int i)
{
    t_stack *tmp;
    t_stack *last;
    t_stack *head;
    head = (*stack)->next;
    last = ft_lstlast2(*stack);
    tmp = *stack;
    last->next = tmp;
    tmp->next = NULL;
    (*stack) = head;
    if(i)
        write(1, "ra\n", 4);
}

void ft_pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    t_stack *head;
    tmp = *stack_b;
    head = (*stack_a)->next;
    *stack_b = *stack_a;
    *stack_a = head;
    (*stack_b)->next = tmp;
    write(1, "pb\n", 4);
}
void ft_pa(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    t_stack *head;
    tmp = *stack_a;
    head = (*stack_b)->next;
    *stack_a = *stack_b;
    *stack_b = head;
    (*stack_a)->next = tmp;
    write(1, "pa\n", 4);
}

void ft_rr(t_stack **stack_a,t_stack **stack_b)
{
    ft_ra(stack_a, 0);
    ft_rb(stack_b, 0);
    write(1, "rr\n", 4);
}