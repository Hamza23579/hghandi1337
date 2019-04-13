/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_funcitons.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 18:27:44 by hghandi           #+#    #+#             */
/*   Updated: 2019/03/10 18:27:46 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calcule_move_para(t_map *map, t_chemin c)
{
	int varx;
	int vary;

	varx = map->width / 2 - map->scale * (map->ncol - 1) / 2;
	vary = map->height_size / 2 - map->scale * (map->nligne - 1) / 2;
	map->k.pi.x = c.pi.x * map->scale + map->move.x + varx;
	map->k.pf.x = c.pf.x * map->scale + map->move.x + varx;
	map->k.pi.y = c.pi.y * map->scale + map->move.y + vary;
	map->k.pf.y = c.pf.y * map->scale + map->move.y + vary;
}

void	calcule_move_iso(t_map *map, t_chemin c)
{
	int varx;
	int vary;

	varx = map->width / 2 - map->scale * (map->ncol - 4) / 2;
	vary = map->scale * (map->nligne - 1) / 2;
	map->k.pi.x = c.pi.x * map->scale + map->move.x + varx;
	map->k.pf.x = c.pf.x * map->scale + map->move.x + varx;
	map->k.pi.y = c.pi.y * map->scale + map->move.y - vary;
	map->k.pf.y = c.pf.y * map->scale + map->move.y - vary;
}

void	iso_loop1(t_map *map, t_chemin *c)
{
	int		map_temp;
	int		z;

	while (c->pi.x < map->ncol - 1)
	{
		c->pf.x = c->pi.x + 1;
		calcule_move_iso(map, *c);
		map_temp = map->map[c->pi.y][c->pi.x] * map->height;
		z = map->map[c->pi.y][c->pi.x + 1];
		iso(&map->k.pi.x, &map->k.pi.y, map_temp, *map);
		if (map->map[c->pi.y][c->pi.x] || map->map[c->pi.y][c->pi.x + 1])
			iso(&map->k.pf.x, &map->k.pf.y, z * map->height, *map);
		if (map->map[c->pi.y][c->pi.x] && map->map[c->pi.y][c->pi.x + 1])
			dessinligne(map->mlx, map->k, 0xf1c40f - z * map->height);
		else if (map->map[c->pi.y][c->pi.x] || map->map[c->pi.y][c->pi.x + 1])
			dessinligne(map->mlx, map->k, 0xe74c3c + z * map->height);
		else
		{
			iso(&map->k.pf.x, &map->k.pf.y, map_temp, *map);
			dessinligne(map->mlx, map->k, 0x2c3e50);
		}
		c->pi.x++;
	}
}

void	iso_loop2(t_map *map, t_chemin *c)
{
	int		map_temp;
	int		z;

	while (c->pi.y < map->nligne - 1)
	{
		c->pf.y = c->pi.y + 1;
		calcule_move_iso(map, *c);
		map_temp = map->map[c->pi.y][c->pi.x] * map->height;
		z = map->map[c->pi.y + 1][c->pi.x];
		iso(&map->k.pi.x, &map->k.pi.y, map_temp, *map);
		if (map->map[c->pi.y][c->pi.x] || map->map[c->pi.y + 1][c->pi.x])
			iso(&map->k.pf.x, &map->k.pf.y, z * map->height, *map);
		if (map->map[c->pi.y][c->pi.x] && map->map[c->pi.y + 1][c->pi.x])
			dessinligne(map->mlx, map->k, 0xf1c40f - z * map->height);
		else if (map->map[c->pi.y][c->pi.x] || map->map[c->pi.y + 1][c->pi.x])
			dessinligne(map->mlx, map->k, 0xe74c3c + z * map->height);
		else
		{
			iso(&map->k.pf.x, &map->k.pf.y, map_temp, *map);
			dessinligne(map->mlx, map->k, 0x2c3e50);
		}
		c->pi.y++;
	}
}

int		condition(int keycode)
{
	if (keycode != 124 && keycode != 11 && keycode != 1 && keycode != P
		&& keycode != I && keycode != C && keycode != 123 && keycode != ESC)
		return (1);
	return (0);
}
