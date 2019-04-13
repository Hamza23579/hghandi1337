/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dessinligne.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <mderri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:01:15 by mderri            #+#    #+#             */
/*   Updated: 2019/02/10 15:01:17 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dessinligne(t_mlx mlx, t_chemin c, int color)
{
	t_point delta;
	t_point	newv;
	int		erreur;
	int		erraux;

	delta.x = ft_abs(c.pf.x - c.pi.x);
	delta.y = ft_abs(c.pf.y - c.pi.y);
	erreur = (delta.x > delta.y ? delta.x : -delta.y) / 2;
	newv.x = c.pi.x < c.pf.x ? 1 : -1;
	newv.y = c.pi.y < c.pf.y ? 1 : -1;
	while (c.pi.x != c.pf.x || c.pi.y != c.pf.y)
	{
		mlx_pixel_put(mlx.ptr, mlx.win, c.pi.x, c.pi.y, color);
		erraux = erreur;
		if (erraux > -delta.x)
		{
			erreur -= delta.y;
			c.pi.x += newv.x;
		}
		if (erraux < delta.y)
		{
			erreur += delta.x;
			c.pi.y += newv.y;
		}
	}
}
