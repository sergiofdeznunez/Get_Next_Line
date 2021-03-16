/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 10:13:32 by snunez            #+#    #+#             */
/*   Updated: 2021/03/16 17:45:19 by snunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int		main()
{
	int		arch;
	char	*linea;
	int		i = 0;

	arch = open("gnlTester/files/42_with_nl", O_RDONLY);
	while ((i = get_next_line(arch, &linea)) != 0)
	{
		printf("%s\n", linea);
		free(linea);
	}
	printf("%s\n", linea);
	free(linea);
	system ("leaks a.out");
	return (0);
}
