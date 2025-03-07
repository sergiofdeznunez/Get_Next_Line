/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:56:05 by snunez            #+#    #+#             */
/*   Updated: 2021/03/16 10:13:07 by snunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	lft_rght(char *apoyo, char **line, char **buffaux)
{
	unsigned int	j;
	int				cont;
	char			*sub;
	char			*tmp;

	j = 0;
	cont = 0;
	while (*(apoyo + cont) && *(apoyo + cont) != '\n')
		cont++;
	while (*(apoyo + cont + j))
		j++;
	sub = ft_substr(apoyo, 0, cont);
	if (*line != NULL)
	{
		tmp = *line;
		*line = ft_strjoin(*line, sub);
		free(tmp);
	}
	else
		*line = ft_strdup(sub);
	free(sub);
	*buffaux = ft_substr(apoyo, cont + 1, j - 1);
}

void	izq_dcha(char **line, char **buffaux)
{
	unsigned int	i;
	unsigned int	j;
	char			*aux;
	int				cont;

	aux = *buffaux;
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
	*line = ft_substr(*buffaux, 0, cont);
	*buffaux = ft_substr(*buffaux, cont + 1, j - 1);
	free(aux);
}

int		get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*buffaux;
	char		*apoyo;
	char		*tmp;
	int			result;
	
	if (fd == -1 || BUFFER_SIZE < 1)
		return (-1);
	*line = NULL;
	if (buffaux != (NULL))
	{
		*line = buffaux;
		if (ft_strchr(buffaux, '\n') != NULL)
		{
			izq_dcha(line, &buffaux);
			return (1);
		}
	}
	while ((result = (read(fd, buff, BUFFER_SIZE))) >= 0)
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
		if (result == 0)
			break ;
	}
	buffaux = NULL;
	return (result);
}
