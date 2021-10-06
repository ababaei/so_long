/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:25:56 by ababaei           #+#    #+#             */
/*   Updated: 2021/10/06 22:51:21 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"

typedef struct 	s_parse
{
	int player;
	int exit;
	int collec;
	int map_width;
	int map_height;
	char **map;
	int player_pos[2];
} 				t_parse;

int parser(t_parse *data, char *filename, int *errflag);
int checker(t_parse *data, int *errflag);

#endif
