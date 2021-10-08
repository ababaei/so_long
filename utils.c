#include <X11/X.h>

#include "so_long.h"

void get_pos(t_parse *data)
{
	int row;
	int col;

	row = 0;
	while (data->map[row])
	{
		col = 0;
		while (data->map[row][col])
		{
			if (data->map[row][col] == 'P') 
			{
				data->player_pos[0] = col;
				data->player_pos[0] = row;
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
