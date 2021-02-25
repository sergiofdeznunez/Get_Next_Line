/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:55:21 by snunez            #+#    #+#             */
/*   Updated: 2021/02/24 13:59:02 by snunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strlcat(char *s1, static char *s2)
{
	char	*aux;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	aux = s2;
	i = 0;
	j = 0;
	while (*(s1 + i))
		i++;
	while (*(aux + j))
	{
		*(s1 + i) = *(aux + j);
		i++;
		j++;
	}
	*(s1 + i) = '\0';
	return (s1);
}
