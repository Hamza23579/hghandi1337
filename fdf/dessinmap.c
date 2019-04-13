/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dessinmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <mderri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 21:57:58 by mderri            #+#    #+#             */
/*   Updated: 2019/02/10 21:58:00 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(int *x, int *y, int z, t_map map)
{
	int previous_x;
	int previous_y;
	int i;

	i = map.scale;
	z *= i * 0.25;
	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (float)(-z) + (previous_x + previous_y) * sin(0.523599);
}

t_map	dessinhori_paral(t_map map)
{
	t_chemin	c;
	int			z;

	c.pi.y = 0;
	c.pf.y = 0;
	while (c.pi.y < map.nligne)
	{
		c.pi.x = 0;
		while (c.pi.x < map.ncol - 1)
		{
			z = map.map[c.pi.y][c.pi.x + 1] * map.height;
			c.pf.x = c.pi.x + 1;
			calcule_move_para(&map, c);
			if (map.map[c.pi.y][c.pi.x] && map.map[c.pi.y][c.pi.x + 1])
				dessinligne(map.mlx, map.k, 0xf1c40f - z);
			else if (map.map[c.pi.y][c.pi.x] || map.map[c.pi.y][c.pi.x + 1])
				dessinligne(map.mlx, map.k, 0xe74c3c + z);
			else
				dessinligne(map.mlx, map.k, 0x2c3e50);
			c.pi.x++;
		}
		c.pi.y++;
		c.pf.y = c.pi.y;
	}
	return (map);
}

t_map	dessinverti_paral(t_map map)
{
	t_chemin	c;
	int			z;

	c.pi.x = 0;
	c.pf.x = 0;
	while (c.pi.x < map.ncol)
	{
		c.pi.y = 0;
		while (c.pi.y < map.nligne - 1)
		{
			z = map.map[c.pi.y + 1][c.pi.x] * map.height;
			c.pf.y = c.pi.y + 1;
			calcule_move_para(&map, c);
			if (map.map[c.pi.y][c.pi.x] && map.map[c.pi.y + 1][c.pi.x])
				dessinligne(map.mlx, map.k, 0xf1c40f - z);
			else if (map.map[c.pi.y][c.pi.x] || map.map[c.pi.y + 1][c.pi.x])
				dessinligne(map.mlx, map.k, 0xe74c3c + z);
			else
				dessinligne(map.mlx, map.k, 0x2c3e50);
			c.pi.y++;
		}
		c.pi.x++;
		c.pf.x = c.pi.x;
	}
	return (map);
}

void	dessinhori_iso(t_map map)
{
	t_chemin	c;

	c.pi.y = 0;
	c.pf.y = 0;
	while (c.pi.y < map.nligne)
	{
		c.pi.x = 0;
		iso_loop1(&map, &c);
		c.pi.y++;
		c.pf.y = c.pi.y;
	}
}

void	dessinverti_iso(t_map map)
{
	t_chemin	c;

	c.pi.x = 0;
	c.pf.x = 0;
	while (c.pi.x < map.ncol)
	{
		c.pi.y = 0;
		iso_loop2(&map, &c);
		c.pi.x++;
		c.pf.x = c.pi.x;
	}
}
