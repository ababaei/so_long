#include <stdlib.h>
#include <stdio.h>

#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>

#include "so_long.h"

int render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (1);
}

int draw_game(t_data *gfx, int row, int col)
{
	//printf("%p | %p | %p\n",gfx->mlx_ptr, gfx->win_ptr, gfx->mur_img.mlx_img);
	if (gfx->game->map[row][col] == '1')
		mlx_put_image_to_window(gfx->mlx_ptr, gfx->win_ptr, gfx->mur_img.mlx_img, col * 32, row * 32);
		//render_rect(&gfx->img, (t_rect){col * 32, row * 32, 32, 32, 0xFF0000});
	if (gfx->game->map[row][col] == 'P')
		mlx_put_image_to_window(gfx->mlx_ptr, gfx->win_ptr, gfx->cha_img.mlx_img, col * 32, row * 32);
		//render_rect(&gfx->img, (t_rect){col * 32, row * 32, 32, 32, 0xF000F0});
	if (gfx->game->map[row][col] == 'E')
		mlx_put_image_to_window(gfx->mlx_ptr, gfx->win_ptr, gfx->por_img.mlx_img, col * 32, row * 32);
		//render_rect(&gfx->img, (t_rect){col * 32, row * 32, 32, 32, 0x0000FF});
	if (gfx->game->map[row][col] == 'C')
		mlx_put_image_to_window(gfx->mlx_ptr, gfx->win_ptr, gfx->ene_img.mlx_img, col * 32, row * 32);
		//render_rect(&gfx->img, (t_rect){col * 32, row * 32, 32, 32, 0xFFFF00});
	if (gfx->game->map[row][col] == '0')
		mlx_put_image_to_window(gfx->mlx_ptr, gfx->win_ptr, gfx->sol_img.mlx_img, col * 32, row * 32);
		//render_rect(&gfx->img, (t_rect){col * 32, row * 32, 32, 32, 0x000000});
	return (1);
}

int renderer(t_data *gfx)
{
	int row;
	int col;

	row = 0;
	col = 0;
	if (gfx->win_ptr == NULL)
		return (-1);
	while (gfx->game->map[row])
	{
		col = 0;
		while (gfx->game->map[row][col])
		{
			draw_game(gfx, row, col);
			col++;
		}
		row++;
	}
	//mlx_put_image_to_window(gfx->mlx_ptr, gfx->win_ptr, gfx->img.mlx_img, 0, 0);
	return (1);
}
