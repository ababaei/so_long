#include <stdlib.h>
#include <stdio.h>

#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>

#include "so_long.h"

int renderer(t_parse *data)
{
	t_data gfx;

	gfx.mlx_ptr = mlx_init();
	if (gfx.mlx_ptr == NULL)
		return (-1);
	gfx.win_ptr = mlx_new_window(gfx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"MY firrt");
	if (gfx.win_ptr == NULL)
	{
		free(gfx.win_ptr);
		return (-1);
	}
	gfx.img.mlx_img = mlx_new_image(gfx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	gfx.img.addr = mlx_get_gfx_addr(gfx.img.mlx_img, &gfx.img.bpp,
			&gfx.img.line_len, &gfx.img.endian);
	mlx_loop_hook(gfx.mlx_ptr, &render_loop, &gfx);
	mlx_hook(gfx.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &gfx);

	mlx_loop(gfx.mlx_ptr);

	mlx_destroy_display(gfx.mlx_ptr);
	free(gfx.mlx_ptr);

}

int game_loop(t_data *gfx)
{
	
}
