/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:56:05 by snunez            #+#    #+#             */
/*   Updated: 2021/03/01 16:45:13 by snunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
# define BUFF_SIZE	5

void	lft_rght(char *apoyo, char **line, char **buffaux)
{
	unsigned int	i;
	unsigned int	j;
	char			*aux;
	int				cont;

	aux = (char *)apoyo;
	i = 0;
	j = 0;
	cont = 0;
	while (*(aux + i) && *(aux + i) != '\n')
	{
		i++;
		cont++;
	}
	while (*(aux + i))
	{
		i++;
		j++;
	}
	*line = ft_strjoin(*line, (ft_substr(aux, 0, cont)));
	*buffaux = ft_substr(aux, cont, j);
	printf("%s\n", *buffaux);
}

int		get_next_line(int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*buffaux;
	char		*apoyo;
	int			result;

	if (!fd || !line || BUFF_SIZE < 1)
		return (0);
	printf("restos :D %s\n", buffaux);
	if (buffaux != NULL)
		*line = buffaux;
	while ((result = (read(fd, buff, BUFF_SIZE))) > 0)
	{
		*(buff + result) = '\0';
		apoyo = ft_strdup(buff);
		if (ft_strchr(apoyo, '\n') == (NULL))
		{
			*line = ft_strjoin(*line, apoyo);
		}
		else
		{
			lft_rght(apoyo, line, &buffaux);
			return (1);
		}
	}
	return (result);
}
