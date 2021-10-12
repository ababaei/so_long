/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:07:56 by ababaei           #+#    #+#             */
/*   Updated: 2021/10/12 18:37:45 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

static int	check_obj(t_parse *data)
{
	if (data->player != 1 || data->exit != 1 || data->collec == 0)
		return (-1);
	return (1);
}

static int	check_map(t_parse *data)
{
	int	col;
	int	row;

	row = 0;
	if (data->map_width == data->map_height)
	{
		printf("CACA\n");
		return (-1);
	}
	if (!ft_isincharset('1', data->map[0])
		|| !ft_isincharset('1', data->map[data->map_height - 1]))
	{
		printf("RORO\n");
		return (-1);
	}
	while (data->map[row])
	{
		col = 0;
		if (data->map[row][0] != '1' ||
				data->map[row][data->map_width - 1] != '1')
		{
			printf("FOFO\n");
			return (-1);
		}
		while (data->map[col])
		{
			if (!ft_isincharset(data->map[row][col], "ECP10"))
			{
				printf("[%i][%i] = %c\n",row, col, data->map[row][col]);
				return (-1);
			} 
			col++;
		}
		row++;
	}
	return (1);
}

int	checker(t_parse *data, int *errflag)
{
	if (check_map(data) == -1)
	{
		printf("TOTO\n");
		return (*errflag = -1);
	}
	if (check_obj(data) == -1)
	{
		printf("T!TO\n");
		return (*errflag = -1);
	}
	return (1);
}
