/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:51:11 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/20 14:10:19 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void) 
{
	int	fd;

	fd = open("test", O_RDONLY);
    printf("%s", get_next_line(fd));
	close(fd);
    return 0;
}