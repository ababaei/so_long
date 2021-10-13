/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:10:23 by ababaei           #+#    #+#             */
/*   Updated: 2021/10/13 19:15:52 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>

#include "so_long.h"

int	init_textures(t_data *gfx, t_parse *data)
{
	int	i;
	int	j;

	gfx->sol_img.mlx_img = mlx_xpm_file_to_image(gfx->mlx_ptr,
			data->sol_tex, &i, &j);
	gfx->mur_img.mlx_img = mlx_xpm_file_to_image(gfx->mlx_ptr,
			data->mur_tex, &i, &j);
	gfx->por_img.mlx_img = mlx_xpm_file_to_image(gfx->mlx_ptr,
			data->port_tex, &i, &j);
	gfx->cha_img.mlx_img = mlx_xpm_file_to_image(gfx->mlx_ptr,
			data->cha_tex, &i, &j);
	gfx->ene_img.mlx_img = mlx_xpm_file_to_image(gfx->mlx_ptr,
			data->ene_tex, &i, &j);
	return (1);
}
