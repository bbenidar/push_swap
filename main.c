/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:51:30 by bbenidar          #+#    #+#             */
/*   Updated: 2023/02/12 19:12:05 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack *ft_new_node(void)
{
    t_stack *begin;

    begin = (t_stack *)malloc(sizeof(t_stack));
    if(!begin)
        return(NULL);
    begin->num = 0;
    begin->end = -1;
    begin->next = NULL;
    return (begin);
}

char **ft_join_av(char **av , int ac)
{
    int i = 0;
    char *tr1;
    char *tr2;
    char **str1;
    tr1 = (char *)malloc(sizeof(char) * ac);
    tr1 = ft_strjoin(av[i++], " ");
    while(i < ac )
    {
        if(check_space(av[i]))
        {
            write(1, "Error\n", 6);
            exit(0);
        }
        tr1 = ft_strjoin(tr1, av[i]);
        tr1 = ft_strjoin(tr1, " ");
        i++;
    }
    str1 = ft_split(tr1, ' ');
    return (str1);
}





t_stack *copy_av(int ac, char **av)
{
    t_stack *begin;
    t_stack *tmp;
    char **str;
    int i;
    int len;

    i = 1;
    begin = ft_new_node();
    str = ft_join_av(av, ac);
    len = ft_lentab(str);
    tmp = begin;
    i = 1;
    while(i < len)
    {
        if (check_av(str[i]))
        {
            del_stack(&begin);
            return (0);
        }  
        tmp->num = ft_atoi(str[i]);
        if(i < ac - 1)
        {
            tmp->next = ft_new_node();
            tmp = tmp->next;
            tmp->end = -1;
        }
        i++;
    }
    
   ft_check_deplicat(&begin);
    return (begin);
}

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;

    int len;
    stack_a = copy_av(ac, av);
    if(!stack_a)
    {
        write(1, "Error\n", 6);
        return (1);
    }
    ft_max(stack_a);
    len = s_len(stack_a);
    stack_b = NULL;
    if(len < 4)
    {
        short_sort(&stack_a, len);
        del_stack(&stack_a);
        return (0);
    }
    if(len <= 5)
    {
        ft_sort_five(stack_a, stack_b);
        return (0);
    }
    t_stack *tmp;
    tmp = stack_a;
    printf(" _________________________\n");
    printf("|     num   |     end     |\n");
    printf("|_________________________|\n");
    while(tmp)
    {
        printf("|num : %d | end : %d|\n", tmp->num, tmp->end);
        tmp = tmp->next;
    }
    ft_sort_onehunder(&stack_a, &stack_b);
    //   printf(" _________________________\n");
    // printf("|     num   |     end     |\n");
    // printf("|_________________________|\n");
    // while(stack_a)
    // {
    //     printf("|num : %d | end : %d|\n", stack_a->num, stack_a->end);
    //     stack_a = stack_a->next;
    // }
    // printf("|__________________________________________________-----____|\n");
    //  while(stack_b)
    // {
    //     printf("|num : %d | end : %d|\n", stack_b->num, stack_b->end);
    //     stack_b = stack_b->next;
    // }
      
    
}