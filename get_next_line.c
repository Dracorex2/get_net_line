/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:17:21 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/21 19:36:28 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_error(char *buffer, char *rest)
{
	free(buffer);
	free(rest);
	return (NULL);
}

char	*ft_return(char *rest)
{
	char *res;
	int	i;

	i = ft_strchr(rest, '\n');
	if ( i == -1)
		i = ft_strchr(rest, '\0') - 1;
	res = "";
	res = ft_strjoin(res, rest, i + 1);
	rest = rest + i + 1;
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
		if (byte_r == -1 || (byte_r == 0 && rest[0] == 0))
			return (ft_error(buffer, rest));
		else if (byte_r == 0)
			break;
		rest = ft_strjoin(rest, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (ft_return(rest));
}
