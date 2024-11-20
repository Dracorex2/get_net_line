/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:19:44 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/20 15:32:10 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
    if (!s || s[0] == 0)
        return (0);
	while (s[i] != c)
	{
		if (s[i] == 0 && c != 0)
			return (0);
		i++;
	}
	return (i);
}

void	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = -1;
	if (size)
	{
		while ((src[++i] != 0) && (i < size - 1))
			dst[i] = src[i];
		dst[i] = '\0';
	}
}

char	*ft_strjoin(char const *s1, char const *s2, int n)
{
	char	*res;
	int	len;
	int		i;

	i = 0;
	len = ft_strchr(s1, '\0') + n;
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (0);
	ft_strlcpy(res, s1, ft_strchr(s1, '\0') + 1);
	while (res[i])
		i++;
	ft_strlcpy(&res[i], s2, n + 1);
	return (res);
}
