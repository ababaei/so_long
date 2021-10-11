#include <stdlib.h>
#include <stdio.h>

#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>

# define WINDOW_WIDTH 600 
# define WINDOW_HEIGHT 300

# define RED_PIXEL 0xFF0000
# define WHITE_PIXEL 0xFFFFFF

typedef struct s_img
{
	void *mlx_img;
	char *addr;
	int bpp;
	int line_len;
	int endian;
}	t_img;

typedef struct s_rect
{
	int x;
	int y;
	int width;
	int height;
	int color;
}	t_rect;

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	t_img img;
}	t_data;

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

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_rect(&data->img, (t_rect){0, 0, 500, 300, RED_PIXEL});
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	printf("Keypress : %d\n", keysym);
	return(0);
}

int renderer(t_parse *data, t_data *gfx)
{
	int row;
	int col;

	row = 0;
	printf("%p | %p | %p\n",gfx->mlx_ptr, gfx->win_ptr, gfx->img.mlx_img); 
	if (gfx->win_ptr == NULL)
		return (-1);
	while (data->map[row])
	{
		col = 0;
		while (data->map[col])
		{
			img_pix_put(&gfx->img, row, col, 0xFF0000);
			if (data->map[row][col] == '1')
				render_rect(&gfx->img, (t_rect){col * 32, row * 32, 32, 32, 0xFF0000});
			col++;
		}
		row++;
	}
	printf("TOTO\n");
	//mlx_put_image_to_window(gfx->mlx_ptr, gfx->win_ptr, gfx->img.mlx_img, 0, 0);
	return (1);
}

int	main(void)
{
	t_data data;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "MY firrt");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (1);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
