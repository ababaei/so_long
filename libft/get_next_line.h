/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:28:34 by ababaei           #+#    #+#             */
/*   Updated: 2021/01/29 14:25:10 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

int		get_next_line(int fd, char **line);
char	*readline(int *ret, char *str, int fd);
int		fillline(char *str, char **line, int *ret);

char	*ft_substr(char const *s, unsigned int start);
size_t	ft_strlen(const char *s);
int		isincharset(char *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
