/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:05:27 by ababaei           #+#    #+#             */
/*   Updated: 2021/10/13 19:24:04 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "mlx/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>

#include "so_long.h"

void	exit_game(t_parse *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	exit_mlx(t_data *gfx)
{
	mlx_destroy_image(gfx->mlx_ptr, gfx->sol_img.mlx_img);
	mlx_destroy_image(gfx->mlx_ptr, gfx->mur_img.mlx_img);
	mlx_destroy_image(gfx->mlx_ptr, gfx->por_img.mlx_img);
	mlx_destroy_image(gfx->mlx_ptr, gfx->cha_img.mlx_img);
	mlx_destroy_image(gfx->mlx_ptr, gfx->ene_img.mlx_img);
	mlx_destroy_window(gfx->mlx_ptr, gfx->win_ptr);
	gfx->win_ptr = NULL;
}
