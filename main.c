/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 01:48:00 by ababaei           #+#    #+#             */
/*   Updated: 2021/10/12 21:54:04 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Le main va venir lancer et recuperer les donnes des different
 * modules du projet. 
 * Pour l'instant il y a de prevu, dans l'ordre:
 * 	-parser
 * 	-checker
 * 	-renderer
 *
 */

#include <stdio.h>
#include "so_long.h"

static void init_struct(t_parse *data)
{
	data->exit = 0;
	data->player = 0;
	data->collec = 0;
	data->map_width = 0;
	data->map_height = 0;
	data->map = NULL;
	data->player_pos[0] = 0;
	data->player_pos[1] = 0;
	data->moves = 0;
	ft_strlcpy(data->port_tex, "assets/por.xpm", 15);
	ft_strlcpy(data->sol_tex, "assets/sol.xpm", 15);
	ft_strlcpy(data->mur_tex, "assets/mur.xpm", 15);
	ft_strlcpy(data->ene_tex, "assets/ene.xpm", 15);
	ft_strlcpy(data->cha_tex, "assets/cha.xpm", 15);
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
//	int i = 0;
	int errflag = 0;
	
	init_struct(&data);
	if (argc != 2 || namecheck(argv[1]) == -1)
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
//	while (data.map[i])
//	{
//		printf("%s\n",data.map[i]);
//		i++;
//	}
	//print_game_info(&data);
	game_loop(&data);	
	return (EXIT_SUCCESS);
}
