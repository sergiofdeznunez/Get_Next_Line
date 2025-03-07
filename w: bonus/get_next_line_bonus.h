/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:23:11 by snunez            #+#    #+#             */
/*   Updated: 2021/03/16 17:23:15 by snunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
#endif
