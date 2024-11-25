/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:17:21 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/25 18:59:25 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_return(char **rest)
{
	char 	*res;
	int		i;
	char	*tmp;
	int		end;

	if(!rest)
		return(NULL);
	end = 0;
	i = ft_strchr(*rest, '\n');
	if ( i == -1)
	{
		end = -1;
		i = ft_strchr(*rest, '\0') - 1;
	}
	res = ft_strjoin(NULL, *rest, i + 1);
	tmp = *rest;
	*rest = ft_strjoin(NULL, *rest + i + 1, ft_strchr(*rest + i + 1, '\0'));
	if (!end)
		free(tmp);
	if (end == -1)
		free(*rest);
	return (res);
}

char	*get_next_line(int fd)
{
	int			byte_r;
	char		*buffer;
	static char	*rest = NULL;

	if (!fd || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	while (ft_strchr(rest, '\n') == -1)
	{
		byte_r = read(fd, buffer, BUFFER_SIZE);
		buffer[byte_r] = 0 ;
		if (byte_r == -1 || (byte_r == 0 && !rest)
			|| (byte_r == 0 && rest[0] == 0))
			return (free(buffer), NULL);
		else if (byte_r == 0)
			break;
		rest = ft_strjoin(rest, buffer, byte_r);
	}
	free(buffer);
	return (ft_return(&rest));
}
