/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:02:09 by bbenidar          #+#    #+#             */
/*   Updated: 2023/03/16 19:39:33 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_lbaki(int fd, char *lbaki)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr_g(lbaki, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			free(lbaki);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		lbaki = ft_strjoin_g(lbaki, buff);
	}
	free(buff);
	return (lbaki);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*lbaki;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	lbaki = ft_read_lbaki(fd, lbaki);
	if (!lbaki)
		return (NULL);
	line = ft_get_line(lbaki);
	lbaki = ft_newlstr(lbaki);
	return (line);
}
