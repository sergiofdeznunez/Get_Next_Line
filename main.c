/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 10:13:32 by snunez            #+#    #+#             */
/*   Updated: 2021/03/15 12:48:32 by snunez           ###   ########.fr       */
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
	//int		rslt;
	int		i = 0;

	arch = open("gnlTester/files/42_with_nl", O_RDONLY);
	//rslt = get_next_line(arch, &linea);
	while ((i = get_next_line(arch, &linea)) != 0)
	{
		printf("%s\n", linea);
		printf("i--%d\n", i);
		free(linea);
	}
	printf("%s\n", linea);
	printf("i--%d\n", i);
	free(linea);
	system ("leaks a.out");
	return (0);
}
