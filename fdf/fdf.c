/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <mderri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:00:34 by mderri            #+#    #+#             */
/*   Updated: 2019/02/10 15:00:37 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				event_handle(int keycode, t_map *map)
{
	if (keycode != 86 && keycode != 69 && keycode != 43 && keycode != 78 &&
		keycode != 47 && keycode != 125 && keycode != 126 && condition(keycode))
		return (0);
	if (keycode == 86)
		map->scale *= (-1);
	bigger_smaller_window(keycode, map);
	center(keycode, map);
	zoom_and_height(keycode, map);
	move(keycode, map);
	iso_para_conversion(keycode, map);
	if (keycode == ESC)
		ft_close(map);
	dessinmap(map);
	mlx_loop(map->mlx.ptr);
	free(map->mlx.win);
	free(map->mlx.ptr);
	free(map->mlx.win2);
	return (0);
}

void			key_definition(t_map map)
{
	mlx_string_put(map.mlx.ptr, map.mlx.win2, 10, 10, 0x9E0077,
		"==================~~FDF LEGENDS~~===============\n");
	mlx_string_put(map.mlx.ptr, map.mlx.win2, 10, 50, 0xe74c3c,
		">>>>>>>>> Zoom Avant    : '+'           <<<<<<<<\n");
	mlx_string_put(map.mlx.ptr, map.mlx.win2, 10, 90, 0xe74c3c,
		">>>>>>>>> Zoom Arriere  : '-'           <<<<<<<<\n");
	mlx_string_put(map.mlx.ptr, map.mlx.win2, 10, 130, 0x556627,
		">>>>>>>>> Centrer       : 'C'           <<<<<<<<\n");
	mlx_string_put(map.mlx.ptr, map.mlx.win2, 10, 170, 0xFF5B2B,
		">>>>>>>>> Mirroir       : '4'           <<<<<<<<\n");
	mlx_string_put(map.mlx.ptr, map.mlx.win2, 10, 210, 0x006D80,
		">>>>>>>>> ISO           : 'I'           <<<<<<<<\n");
	mlx_string_put(map.mlx.ptr, map.mlx.win2, 10, 250, 0xe74c3c,
		">>>>>>>>> Parallele     : 'P'           <<<<<<<<\n");
	mlx_string_put(map.mlx.ptr, map.mlx.win2, 10, 290, 0xE8CC06,
		">>>>>>>> Bigger Window  : 'B'           <<<<<<<<\n");
	mlx_string_put(map.mlx.ptr, map.mlx.win2, 10, 330, 0xFF483D,
		">>>>>>>> Smaller Window : 'S'           <<<<<<<<\n");
	mlx_string_put(map.mlx.ptr, map.mlx.win2, 10, 370, 0xC4FCCA,
		">>>>>>>> move           : 'use arrows'  <<<<<<<<\n");
}

void			initialize(t_map *map)
{
	map->nligne = 0;
	map->ncol = 0;
	map->k.pi.x = 10;
	map->k.pi.y = 10;
	map->k.pf.x = 10;
	map->k.pf.y = 10;
	map->is_iso = 0;
	map->is_center = 0;
	map->move.x = 0;
	map->move.y = 0;
	map->scale = 2;
	map->height = 1;
}

void			window(t_map *map)
{
	map->mlx.ptr = mlx_init();
	map->mlx.win = mlx_new_window(map->mlx.ptr, map->height_size,
		map->width, "Fdf");
	map->mlx.win2 = mlx_new_window(map->mlx.ptr, 500, 500, "keys");
}

int				main(int argc, char *argv[])
{
	int			fd;
	t_map		map;
	t_chemin	c;

	initialize(&map);
	if (argc != 2 || (fd = open(argv[1], OR)) == -1 || verify(argv[1], &map))
	{
		ft_putstr("Usage: ./fdf file.fdf\n");
		return (0);
	}
	init_nb_ligne_col(fd, &map);
	close(fd);
	readmap(argv[1], &map);
	map.height_size = map.nligne * map.scale;
	map.width = map.ncol * map.scale;
	window(&map);
	key_definition(map);
	dessinmap(&map);
	mlx_hook(map.mlx.win, 2, 1, event_handle, &map);
	mlx_hook(map.mlx.win2, 2, 1, event_handle, &map);
	mlx_loop(map.mlx.ptr);
	free(map.mlx.win);
	free(map.mlx.ptr);
	free(map.mlx.win2);
	return (0);
}
