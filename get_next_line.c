/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:56:05 by snunez            #+#    #+#             */
/*   Updated: 2021/03/02 18:18:39 by snunez           ###   ########.fr       */
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
	char			*sub;
	char			*tmp;

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
	sub = ft_substr(aux, 0, cont);
	if (*line != NULL)
	{
		tmp = *line;
		*line = ft_strjoin(*line, sub);
		free(tmp);
	}
	else
		*line = ft_strdup(sub);
	free(sub);
	*buffaux = ft_substr(aux, cont, j - 1);
}

int		get_next_line(int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*buffaux;
	char		*apoyo;
	char		*tmp;
	int			result;

	*line= NULL;
	if (!fd || !line || BUFF_SIZE < 1)
		return (0);
	if (buffaux != NULL)
		*line = buffaux;
	while ((result = (read(fd, buff, BUFF_SIZE))) > 0)
	{
		*(buff + result) = '\0';
		apoyo = ft_strdup(buff);
		if (ft_strchr(apoyo, '\n') == (NULL))
		{
			if (*line == NULL)
				*line = ft_strdup(apoyo);
			else
			{
				tmp = *line;
				*line = ft_strjoin(*line, apoyo);
				free(tmp);
			}
			free(apoyo);
		}
		else
		{
			lft_rght(apoyo, line, &buffaux);
			free(apoyo);
			return (1);
		}
	}
	return (result);
}
