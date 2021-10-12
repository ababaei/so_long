/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:05:33 by ababaei           #+#    #+#             */
/*   Updated: 2021/10/12 00:13:44 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>

#include "so_long.h"

int	collision(t_data *gfx, int py, int px)
{
	if (gfx->game->map[py][px] == '1')
		return (0);
	else if (gfx->game->map[py][px] == 'C')	
		gfx->game->collec -= 1;	
	else if (gfx->game->map[py][px] == 'E' && !gfx->game->collec)
		clean_exit(gfx);
	gfx->game->moves++;
	return (1);
}

void	player_movement(int keysym, t_data *gfx)
{
	int px;
	int py;

	px = gfx->game->player_pos[1];
	py = gfx->game->player_pos[0];
	gfx->game->map[py][px] = '0';
	if (keysym == XK_Up && collision(gfx, py - 1, px))
		gfx->game->player_pos[0] -= 1;
	else if (keysym == XK_Down && collision(gfx, py + 1, px))
		gfx->game->player_pos[0] += 1;
	else if (keysym == XK_Left && collision(gfx, py, px - 1))
		gfx->game->player_pos[1] -= 1;
	else if (keysym == XK_Right && collision(gfx, py, px + 1))
		gfx->game->player_pos[1] += 1;
	gfx->game->map[gfx->game->exit_y][gfx->game->exit_x] = 'E';
	gfx->game->map[gfx->game->player_pos[0]][gfx->game->player_pos[1]] = 'P';
}

int	control_handler(int keysym, t_data *gfx)
{
	if (keysym == XK_Escape)
	{
		clean_exit(gfx);
	}
	player_movement(keysym, gfx);
	printf("[%d][%d]\n", gfx->game->player_pos[0], gfx->game->player_pos[1]);
	printf("moves = %i\n", gfx->game->moves);
	printf("collec = %i\n", gfx->game->collec);
	return (1);
}
