/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:02:39 by bbenidar          #+#    #+#             */
/*   Updated: 2023/03/16 19:39:17 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_g(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_g(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen_g(left_str) + ft_strlen_g(buff))
				+ 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen_g(left_str) + ft_strlen_g(buff)] = '\0';
	free(left_str);
	return (str);
}

char	*ft_strchr_g(char *s, int c)
{
	char	*ss;

	ss = (char *)s;
	if (!ss)
		return (NULL);
	while (*ss && *ss != (char)c)
		ss++;
	if (*ss == (char)c)
		return (ss);
	return (NULL);
}

char	*ft_get_line(char *lbaki)
{
	int		i;
	char	*str;

	i = 0;
	if (!lbaki[i])
		return (NULL);
	while (lbaki[i] && lbaki[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (lbaki[i] && lbaki[i] != '\n')
	{
		str[i] = lbaki[i];
		i++;
	}
	if (lbaki[i] == '\n')
	{
		str[i] = lbaki[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_newlstr(char *lbaki)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (lbaki[i] && lbaki[i] != '\n')
		i++;
	if (!lbaki[i])
	{
		free(lbaki);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen_g(lbaki) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (lbaki[i])
		str[j++] = lbaki[i++];
	str[j] = '\0';
	free(lbaki);
	return (str);
}
