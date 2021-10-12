#include <X11/X.h>
#include <stdio.h>

#include "so_long.h"

void print_game_info(t_parse *data)
{
	printf("Player = %i\n", data->player);
	printf("exit = %i\n", data->exit);
	printf("collec = %i\n", data->collec);
	printf("map_width = %i\n", data->map_width);
	printf("map_height = %i\n", data->map_height);
	printf("moves = %i\n", data->moves);
}

void get_exit(t_parse *data)
{
	int row;
	int col;

	row = 0;
	while (data->map[row])
	{
		col = 0;
		while (data->map[row][col])
		{
			if (data->map[row][col] == 'E') 
			{
				data->exit_x = col;
				data->exit_y = row;
			}	
			col++;	
		}
		row++;
	}
}

int	encode_rgb(unsigned int red, unsigned int green, unsigned int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}
