/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:17:21 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/20 15:40:22 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 42

static void	*ft_error(char **buffer, char **rest, char **res)
{

}

char	*get_next_line(int fd)
{
	int			byte_r;
	char		*buffer;
	static char	*rest;
	int			i;
	char		*res;

	i = 0;
	buffer = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	res = "";
	while (byte_r || !ft_strchr(res, '\n'))
	{
		byte_r = read(fd, buffer, BUFFER_SIZE);
		if (byte_r == -1)
			return (ft_error(&buffer, &rest, &res));
		res = ft_strjoin(res, buffer, ft_strchr(buffer, '\n'));
	}
	
	read(fd, buffer, BUFFER_SIZE);
	return (0);
}
