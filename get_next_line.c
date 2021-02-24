/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:56:05 by snunez            #+#    #+#             */
/*   Updated: 2021/02/24 12:56:05 by snunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
# define BUFF_SIZE	1

int		get_next_line(int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*buffaux;

	buff[BUFF_SIZE + 1] = '\0';
	while (read(int fd, buff, BUFF_SIZE) > 0)
	{
		
	}
}
