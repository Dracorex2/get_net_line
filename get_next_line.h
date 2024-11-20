/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:19:27 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/20 13:36:34 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2, int n);
int     ft_strchr(const char *s, char c);
void	ft_strlcpy(char *dst, const char *src, size_t size);
char    *get_next_line(int fd);

#endif