#include <stdlib.h>
#include <stdio.h>

#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>

#include "so_long.h"

//Ajouter les collisions ici
void	player_movement(int keysym, t_data *gfx)
{
	gfx->game.map[gfx->game.player_pos[0]][gfx->game.player_pos[1]] = '0';
	if (keysym == XK_Up)
		gfx->game.player_pos[0] -= 1;
	else if (keysym == XK_Down)
		gfx->game.player_pos[0] += 1;
	else if (keysym == XK_Left)
		gfx->game.player_pos[1] -= 1;
	else if (keysym == XK_Right)
		gfx->game.player_pos[1] += 1;
	gfx->game.map[gfx->game.player_pos[0]][gfx->game.player_pos[1]] = 'P';
}

int	control_handler(int keysym, t_data *gfx)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(gfx->mlx_ptr, gfx->win_ptr);
		gfx->win_ptr = NULL;
	}
	player_movement(keysym, gfx);
	printf("[%d][%d]\n", gfx->game.player_pos[0], gfx->game.player_pos[1]);
	return (1);
}
