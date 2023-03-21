/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:01:54 by bbenidar          #+#    #+#             */
/*   Updated: 2023/03/16 15:01:56 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//--------------haeders-------------//
# include "../../push_swap.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
//------------function prototype-----------//
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*ft_strjoin_g(char *left_str, char *buff);
char	*ft_strchr_g(char *s, int c);
size_t	ft_strlen_g(char *str);
char	*get_next_line(int fd);
char	*ft_newlstr(char *lbaki);
char	*ft_get_line(char *lbaki);
char	*ft_read_lbaki(int fd, char *lbaki);

#endif