/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:25:43 by ababaei           #+#    #+#             */
/*   Updated: 2021/10/06 02:25:16 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "so_long.h"

static int	count_lines(char ***tab)
{
	int i;

	i = 0;
	while(*tab && (*tab)[i])
		i++;
	return (i);
}

static void fill_data(t_parse *data)
{
	int col;
	int row;

	row = 0;
	while (data->map[row])
	{
		col = 0;
		while (data->map[row][col])
		{
			if (data->map[row][col] == 'P') 
				data->player += 1;
			if (data->map[row][col] == 'E')
				data->exit += 1;
			if (data->map[row][col] == 'C')
				data->collec += 1;
			col++;	
		}
		row++;
	}
	data->map_width = col;
	data->map_height = row;
}

static int	fill_map(t_parse *data, char *line)
{
	char **newmap;
	int i;

	i = count_lines(&data->map);
	newmap = malloc(sizeof(char *) * (i + 2));
	if (newmap == NULL)
		return (-1);
	i = 0;
	while (data->map && data->map[i])
	{
		newmap[i] = data->map[i];
		i++;
	}
	newmap[i] = ft_strdup(line);
	newmap[i + 1] = NULL;
	free(data->map);
	data->map = newmap;
	return (1);
}

int	parser(t_parse *data, char *filename)
{
	char *line;
	int fd;
	
	fd = open(filename, O_RDONLY);
	if (fd == - 1)
		return (-1);
	while (get_next_line(fd, &line))
	{
		if (fill_map(data, line) == -1)
		{
			free(line);
			return (-1);
		}
		free(line);	
	}
	free(line);
	fill_data(data);
	return (1);	
}
