/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:16:10 by ababaei           #+#    #+#             */
/*   Updated: 2021/10/20 12:49:07 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "mlx/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>

#include "so_long.h"

int	init_game(t_parse *data, t_data *gfx)
{
	gfx->mlx_ptr = mlx_init();
	if (gfx->mlx_ptr == NULL)
		return (-1);
	gfx->win_ptr = mlx_new_window(gfx->mlx_ptr,
			data->map_width * 32, data->map_height * 32, "RME FDP");
	if (gfx->win_ptr == NULL)
	{
		free(gfx->win_ptr);
		return (-1);
	}
	return (1);
}

int	game_loop(t_parse *data)
{
	t_data	gfx;

	gfx.game = data;
	if (init_game(data, &gfx) == -1)
		return (-1);
	init_textures(&gfx, data);
	mlx_loop_hook(gfx.mlx_ptr, &renderer, &gfx);
	mlx_hook(gfx.win_ptr, KeyPress, KeyPressMask, &control_handler, &gfx);
	mlx_loop(gfx.mlx_ptr);
	exit_game(data);
	mlx_destroy_display(gfx.mlx_ptr);
	free(gfx.mlx_ptr);
	return (1);
}
