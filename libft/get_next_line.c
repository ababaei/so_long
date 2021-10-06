/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 09:29:04 by ababaei           #+#    #+#             */
/*   Updated: 2021/01/29 16:47:03 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	clean_exit(char **tmp, char *buf, int ret)
{
	if (ret == 0)
	{
		free(*tmp);
		tmp = NULL;
	}
	free(buf);
}

int	get_next_line(int fd, char **line)
{
	static char	*tmp = NULL;
	char		*buf;
	int			ret;
	int			inl;

	ret = 1;
	buf = NULL;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while (!(isincharset(tmp, '\n')) && ret)
	{
		buf = readline(&ret, buf, fd);
		tmp = ft_strjoin(tmp, buf);
		if (!buf || !tmp)
			return (-1);
	}
	inl = fillline(tmp, line, &ret);
	if (inl == -1)
		return (-1);
	tmp = ft_substr(tmp, inl + 1);
	clean_exit(&tmp, buf, ret);
	return (ret);
}

char	*readline(int *ret, char *str, int fd)
{
	free(str);
	str = NULL;
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (str == NULL)
		return (0);
	*ret = read(fd, str, BUFFER_SIZE);
	if (*ret == -1)
	{
		free(str);
		str = NULL;
		return (0);
	}
	str[*ret] = '\0';
	return (str);
}

int	fillline(char *str, char **line, int *ret)
{
	int	count;

	count = 0;
	while (str[count] != '\n' && str[count])
		count++;
	*line = malloc(sizeof(char) * (count + 1));
	if (*line == NULL)
		return (-1);
	count = 0;
	while (str[count] != '\n' && str[count])
	{
		(*line)[count] = str[count];
		count++;
	}
	(*line)[count] = '\0';
	if (isincharset(str, '\n'))
		*ret = 1;
	return (count);
}
