/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:10:33 by hghandi           #+#    #+#             */
/*   Updated: 2019/03/10 15:10:35 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_and_height(int keycode, t_map *map)
{
	if (keycode == 69)
		map->scale += 1;
	if (keycode == 78 && map->scale > 0.5)
		map->scale -= 1;
	if (keycode == 43)
		map->height -= 1;
	if (keycode == 47)
		map->height += 1;
}

void	move(int keycode, t_map *map)
{
	if (keycode == 125)
	{
		map->move.y += 30;
		if (map->is_iso == 1)
			map->move.x += 30;
	}
	if (keycode == 126)
	{
		map->move.y -= 30;
		if (map->is_iso == 1)
			map->move.x -= 30;
	}
	if (keycode == 123)
	{
		map->move.x -= 30;
		if (map->is_iso == 1)
			map->move.y += 30;
	}
	if (keycode == 124)
	{
		map->move.x += 30;
		if (map->is_iso == 1)
			map->move.y -= 30;
	}
}

void	bigger_smaller_window(int keycode, t_map *map)
{
	if (keycode == 11)
	{
		mlx_destroy_window(map->mlx.ptr, map->mlx.win);
		map->scale += 2;
		map->width = map->ncol * map->scale;
		map->height_size = map->nligne * map->scale;
		map->mlx.win = mlx_new_window(map->mlx.ptr, map->width,
			map->height_size, "Fdf");
		mlx_hook(map->mlx.win, 2, 1, event_handle, map);
	}
	if (keycode == 1)
	{
		mlx_destroy_window(map->mlx.ptr, map->mlx.win);
		map->scale -= 2;
		map->width = map->ncol * map->scale;
		map->height_size = map->nligne * map->scale;
		map->mlx.win = mlx_new_window(map->mlx.ptr, map->width,
			map->height_size, "Fdf");
		mlx_hook(map->mlx.win, 2, 1, event_handle, map);
	}
}

void	iso_para_conversion(int keycode, t_map *map)
{
	if (keycode == P)
		map->is_iso = 0;
	if (keycode == I)
		map->is_iso = 1;
}

void	center(int keycode, t_map *map)
{
	if (keycode == C)
	{
		map->move.x = 0;
		map->move.y = 0;
	}
}
