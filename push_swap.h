/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:59:43 by bbenidar          #+#    #+#             */
/*   Updated: 2023/02/12 18:21:06 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct b_stack
{
	int				num;
	int				end;
	struct b_stack	*next;

}					t_stack;

int					check_av(char *str);
int					check_overflow(char *str);
int					s_len(t_stack *stack);
int					*copy_stack_to_array(t_stack *stack, int len);
void				del_stack(t_stack **stack);
void				ft_check_deplicat(t_stack **stack);
char				**ft_join_av(char **av, int ac);
int					ft_lentab(char **str);
int					check_space(char *str);
void				short_sort(t_stack **stack, int len);
void				ft_swap(int *a, int *b);
void				ft_sa(t_stack *stack);
void				ft_rra(t_stack **stack);
void				ft_ra(t_stack **stack, int i);
void				ft_max(t_stack *stack);
int					ft_position(t_stack *stack, int index);
void				ft_sort_five(t_stack *stack_a, t_stack *stack_b);
void				ft_pb(t_stack **stack_a, t_stack **stack_b);
void				ft_pa(t_stack **stack_a, t_stack **stack_b);
void				ft_sort_onehunder(t_stack **stack_a, t_stack **stack_b);
void				ft_ind(t_stack **stack_a, t_stack **stack_b, int index);
void				ft_rb(t_stack **stack, int i);
void				ft_rr(t_stack **stack_a, t_stack **stack_b);
#endif