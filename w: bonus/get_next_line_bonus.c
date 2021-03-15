/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:26:25 by snunez            #+#    #+#             */
/*   Updated: 2021/03/15 17:12:20 by snunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

void	free_and_join(char **pt, char *s1)
{
	char	*tmp;

	tmp = *pt;
	*pt = ft_strjoin(*pt, s1);
	free(tmp);
}

void	lft_rght(char *apoyo, char **line, char **buffaux)
{
	unsigned int	j;
	int				cont;
	char			*sub;

	j = 0;
	cont = 0;
	while (*(apoyo + cont) && *(apoyo + cont) != '\n')
		cont++;
	while (*(apoyo + cont + j))
		j++;
	sub = ft_substr(apoyo, 0, cont);
	if (*line != NULL)
		free_and_join(line, sub);
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

int	ft_read(int fd, int result, char **line, char **buffaux)
{
	char	buff[BUFFER_SIZE + 1];
	char	*apoyo;

	while ((result = (read(fd, buff, BUFFER_SIZE))) >= 0)
	{
		*(buff + result) = '\0';
		apoyo = ft_strdup(buff);
		if (ft_strchr(apoyo, '\n') == (NULL))
		{
			if (*line == NULL)
				*line = ft_strdup(apoyo);
			else
				free_and_join(line, apoyo);
			free(apoyo);
		}
		else
		{
			lft_rght(apoyo, line, &buffaux[fd]);
			free(apoyo);
			return (1);
		}
		if (result == 0)
			break ;
	}
	return (result);
}

int		get_next_line(int fd, char **line)
{
	static char	*buffaux[FOPEN_MAX];
	int			result;
	
	if ((fd < 0 || fd > FOPEN_MAX)|| BUFFER_SIZE < 1)
		return (-1);
	*line = NULL;
	result = 0;
	if (buffaux[fd] != (NULL))
	{
		*line = buffaux[fd];
		if (ft_strchr(buffaux[fd], '\n') != NULL)
		{
			izq_dcha(line, &buffaux[fd]);
			return (1);
		}
		
	}
	result = ft_read(fd, result, line, buffaux);
	if (result == 0)
		buffaux[fd] = NULL;
	return (result);
}
