/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:51:11 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/25 18:11:24 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void) 
{
	int	fd;
	char *test;
	int	i;

	i = -1;
	fd = open("test", O_RDONLY);
	while (++i < 4)
	{
		test = get_next_line(fd);
		printf("%s", test);
		free(test);
	}
	close(fd);
	return 0;
}