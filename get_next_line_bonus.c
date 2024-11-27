/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:17:21 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/27 16:31:07 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_return(char **rest)
{
	char	*res;
	int		i;
	char	*tmp;

	if (!(*rest))
		return (NULL);
	i = ft_strchr(*rest, '\n');
	if (i == -1)
		i = ft_strchr(*rest, '\0') - 1;
	res = ft_strjoin(NULL, *rest, i + 1);
	tmp = *rest;
	*rest = ft_strjoin(NULL, *rest + i + 1, ft_strchr(*rest + i + 1, '\0'));
	free(tmp);
	return (res);
}

char	*ft_boucle(int fd, char *rest)
{
	char	*buffer;
	int		byte_r;

	buffer = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	while (ft_strchr(rest, '\n') == -1)
	{
		byte_r = read(fd, buffer, BUFFER_SIZE);
		if (byte_r < 0)
		{
			if (rest)
			{
				free(rest);
				rest = NULL;
			}
			return (free(buffer), NULL);
		}
		buffer[byte_r] = 0 ;
		if ((byte_r == 0 && !rest) || (byte_r == 0 && rest[0] == 0))
			return (free(buffer), free(rest), rest = NULL, NULL);
		else if (byte_r == 0)
			break ;
		rest = ft_strjoin(rest, buffer, byte_r);
	}
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest[1024];
	char		*res;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	rest[fd] = ft_boucle(fd, rest[fd]);
	res = ft_return(&(rest[fd]));
	if (ft_strchr(res, '\n') == -1)
		return (free(rest[fd]), rest[fd] = NULL, res);
	return (res);
}
