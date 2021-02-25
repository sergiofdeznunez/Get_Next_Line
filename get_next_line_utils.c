/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:55:21 by snunez            #+#    #+#             */
/*   Updated: 2021/02/25 18:25:08 by snunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t			size;
	char			*new;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(new = (char *)malloc(size * sizeof(char))))
		return (NULL);
	while (*(s1 + i))
	{
		*(new + j) = *(s1 + i);
		i++;
		j++;
	}
	i = 0;
	while (*(s2 + i))
	{
		*(new + j) = *(s2 + i);
		i++;
		j++;
	}
	*(new + j) = '\0';
	return (new);
}

char	*ft_strchr(const char *str,int c)
{
	char	*aux;
	int		i;

	aux = (char *)str;
	i = 0;
	while (*(aux + i))
	{
		if (*(aux + i == (char)c))
			return (aux + i);
		i++;
	}
	if (c == '\0')
		return (aux + i);
	return (NULL);
}
