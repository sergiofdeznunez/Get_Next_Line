/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:56:05 by snunez            #+#    #+#             */
/*   Updated: 2021/02/25 18:25:13 by snunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# define BUFF_SIZE	1

int		get_next_line(int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*buffaux;
	char		*apoyo;
	int			result;
	int			i;
	int			j;

	if (!fd || !line || BUFF_SIZE < 1)
		return (0);
	j = 0;
	while (result = read(fd, buff, BUFF_SIZE) > 0)
	{
		i = 0;
		*(buff + result) = '\0';
		while (*(buff + i) && *(buff + i) != '\n')
		{
			*(apoyo + j) = *(buff + i);
			i++;
			j++;
		}
	}
	line = ft_strjoin(line, apoyo);
}
