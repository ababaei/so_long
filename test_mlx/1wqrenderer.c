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
	return (0);
}

int renderer(t_parse *data, t_data *gfx)
{
	int row;
	int col;

	row = 0;
	if (gfx->win_ptr == NULL)
		return (-1);
	while (data->map[row])
	{
		col = 0;
		while (data->map[col])
		{
			img_pix_put(&gfx->img, row, col, 0xFF0000);
			if (data->map[row][col] == 1)
				render_rect(&gfx->img, (t_rect){col * 32, row * 32, 32, 32, 0xFF0000});
			col++;
		}
		row++;
	}
	printf("TOTO\n");
	printf("%p | %p | %p\n",gfx->mlx_ptr, gfx->win_ptr, gfx->img.mlx_img); 
	mlx_put_image_to_window(gfx->mlx_ptr, gfx->win_ptr, gfx->img.mlx_img, 0, 0);
	return (1);
}
