/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:25:56 by ababaei           #+#    #+#             */
/*   Updated: 2021/10/12 00:09:28 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"

typedef struct	s_img
{
	void *mlx_img;
	char *addr;
	int bpp;
	int line_len;
	int endian;
}				t_img;

typedef struct	s_rect
{
	int x;
	int y;
	int width;
	int height;
	int color;
}				t_rect;

typedef struct 	s_parse
{
	int player;
	int exit;
	int collec;
	int map_width;
	int map_height;
	char **map;
	int player_pos[2];
	int moves;
	int exit_x;
	int exit_y;
} 				t_parse;

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	t_img img;
	t_parse *game;
}				t_data;


int parser(t_parse *data, char *filename, int *errflag);
int checker(t_parse *data, int *errflag);
int game_loop(t_parse *data);
int control_handler(int keysym, t_data *gfx);
int renderer(t_data *gfx);

void get_exit(t_parse *data);
int encode_rgb(unsigned int red, unsigned int green, unsigned blue);
void img_pix_put(t_img *img, int x, int y, int color);
void print_game_info(t_parse *data);

void clean_exit(t_data *gfx);

#endif
