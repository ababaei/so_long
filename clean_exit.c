/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:05:27 by ababaei           #+#    #+#             */
/*   Updated: 2021/10/12 00:44:04 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>

#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>

#include "so_long.h"

void	clean_exit(t_data *gfx)
{
	int i;

	i = 0;
	while (gfx->game->map[i])
	{
		free(gfx->game->map[i]);
		i++;
	}
	free(gfx->game->map);
	mlx_destroy_image(gfx->mlx_ptr, gfx->img.mlx_img);
	mlx_destroy_window(gfx->mlx_ptr, gfx->win_ptr);
	gfx->win_ptr = NULL;
	mlx_destroy_display(gfx->mlx_ptr);
	free(gfx->mlx_ptr);
}
