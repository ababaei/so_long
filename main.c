/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 01:48:00 by ababaei           #+#    #+#             */
/*   Updated: 2021/10/06 22:58:47 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Le main va venir lancer et recuperer les donnes des different
 * modules du projet. 
 * Pour l'instant il y a de prevu, dans l'ordre:
 * 	-parser
 * 	-checker
 * 	-renderer
 * 	-exiter ?
 *
 * 	Pensez a free la map 5 + 1 block.
 * 
 * init_struct gonna initialize the data's values.
 * namecheck gonna check for the filename's extension.
 *
 */

#include <stdio.h>
#include "so_long.h"

static void init_struct(t_parse *data)
{
	data->exit = 0;
	data->collec = 0;
	data->map_width = 0;
	data->map_height = 0;
	data->map = NULL;
	data->player_pos[0] = 0;
	data->player_pos[1] = 0;
}

static int namecheck(char *filename)
{
	char *name;

	name = ft_strrchr(filename, '.');
	if (name == NULL || ft_strncmp(name, ".ber", 3) ||
			ft_strncmp(filename, ".ber", 3) == 0)
		return (-1);
	return (1);
}

int main(int argc, char **argv)
{
	t_parse data;
	int i = 0;
	int errflag = 0;
	
	init_struct(&data);
	if (argc == 1 || namecheck(argv[1]) == -1)
		errflag = -1;
	if (!errflag)
		parser(&data, argv[1], &errflag);
	if (!errflag)
		checker(&data, &errflag);
	if (errflag)
	{
		printf("Error\n");
		return (EXIT_FAILURE);
	}
	while (data.map[i])
	{
		printf("%s\n",data.map[i]);
		i++;
	}
	printf("Player = %i\n", data.player);
	printf("exit = %i\n", data.exit);
	printf("collec = %i\n", data.collec);
	printf("map_width = %i\n", data.map_width);
	printf("map_height = %i\n", data.map_height);
	return (EXIT_SUCCESS);
}
