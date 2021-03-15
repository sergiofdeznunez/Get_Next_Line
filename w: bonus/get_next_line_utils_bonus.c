/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:26:57 by snunez            #+#    #+#             */
/*   Updated: 2021/03/15 17:14:52 by snunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char			*aux;
	char			*cad;
	unsigned int	i;

	if (!s)
		return (NULL);
	aux = (char *)s;
	i = 0;
	cad = (char *)malloc((ft_strlen(aux) + 1) * sizeof(char));
	if (cad == NULL )
		return (NULL);
	while (*(aux + i))
	{
		*(cad + i) = *(aux + i);
		i++;
	}
	*(cad + i) = '\0';
	return (cad);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t			size;
	char			*new;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = (char *)malloc(size * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (*(s1 + j))
	{
		*(new + j) = *(s1 + j);
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
		if (*(aux + i) == (char)c)
			return (aux + i);
		i++;
	}
	if (c == '\0')
		return (aux + i);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*cad;

	i = 0;
	if (!s)
		return (NULL);
	if (len < ft_strlen(s + start))
		cad = (char *)malloc((len + 1) * sizeof(char));
	else 
		cad = (char *)malloc((ft_strlen(s + start) + 1) * sizeof(char));
	if (!cad)
		return (NULL);
	if (start > ft_strlen(s))
	{
		*(cad) = '\0';
		return (cad);
	}
	while (i < len)
	{

		*(cad + i) = *(s + start + i);
		i++;
	}
	*(cad + i) = '\0';
	return (cad);
}
