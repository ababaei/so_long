#include <stdlib.h>
#include <stdio.h>

#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>

#include "so_long.h"

int	control_handler(int keysym, t_parse *data, t_data *gfx)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(gfx->mlx_ptr, gfx->win_ptr);
		gfx->win_ptr = NULL;
	}
	printf("Keypress : %d\n", keysym);
	return(data->collec);
}
