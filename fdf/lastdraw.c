/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lastdraw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:53:06 by hghandi           #+#    #+#             */
/*   Updated: 2019/02/26 20:53:10 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dessinmap(t_map *map)
{
	mlx_clear_window(map->mlx.ptr, map->mlx.win);
	if (map->is_iso == 1)
	{
		dessinhori_iso(*map);
		dessinverti_iso(*map);
	}
	else
	{
		dessinhori_paral(*map);
		dessinverti_paral(*map);
	}
}

void	free_map(t_map *m)
{
	int i;

	i = 0;
	while (i < m->nligne)
	{
		free(m->map[i]);
		i++;
	}
	free(m->map);
}

void	ft_close(t_map *m)
{
	mlx_destroy_window(m->mlx.ptr, m->mlx.win);
	free_map(m);
	free(m->mlx.ptr);
	exit(0);
}
