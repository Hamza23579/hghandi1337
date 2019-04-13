/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:44:14 by hghandi           #+#    #+#             */
/*   Updated: 2019/01/25 15:44:17 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_redifine_coord(t_element *e)
{
	int		i;
	int		xmin;
	int		ymin;

	i = 0;
	if (e == NULL)
		return ;
	xmin = ft_extract_min(e->coord, 0);
	ymin = ft_extract_min(e->coord, 1);
	while (i < 4)
	{
		e->coord[i][0] = e->coord[i][0] - xmin;
		e->coord[i][1] = e->coord[i][1] - ymin;
		i++;
	}
	ft_redifine_coord(e->next);
}

int		place_tetrimino(char **square, int n, t_element *e, t_point p)
{
	int		max_x;
	int		max_y;

	max_x = ft_extract_max(e->coord, 0);
	max_y = ft_extract_max(e->coord, 1);
	if (max_y + p.y < n && max_x + p.x < n)
	{
		if (square[e->coord[0][0] + p.x][e->coord[0][1] + p.y] == '.'
			&& square[e->coord[1][0] + p.x][e->coord[1][1] + p.y] == '.'
			&& square[e->coord[2][0] + p.x][e->coord[2][1] + p.y] == '.'
			&& square[e->coord[3][0] + p.x][e->coord[3][1] + p.y] == '.')
		{
			square[e->coord[0][0] + p.x][e->coord[0][1] + p.y] = e->val;
			square[e->coord[1][0] + p.x][e->coord[1][1] + p.y] = e->val;
			square[e->coord[2][0] + p.x][e->coord[2][1] + p.y] = e->val;
			square[e->coord[3][0] + p.x][e->coord[3][1] + p.y] = e->val;
			return (1);
		}
	}
	return (0);
}

void	remove_tetriminos(t_element *e, char **square, t_point p)
{
	square[e->coord[0][0] + p.x][e->coord[0][1] + p.y] = '.';
	square[e->coord[1][0] + p.x][e->coord[1][1] + p.y] = '.';
	square[e->coord[2][0] + p.x][e->coord[2][1] + p.y] = '.';
	square[e->coord[3][0] + p.x][e->coord[3][1] + p.y] = '.';
}

int		place_all_tetris(char **square, int n, t_element *e)
{
	t_point	p;

	if (e == NULL)
		return (1);
	p.x = 0;
	while (p.x < n)
	{
		p.y = 0;
		while (p.y < n)
		{
			if (place_tetrimino(square, n, e, p) == 1)
			{
				if (place_all_tetris(square, n, e->next) == 1)
					return (1);
				else
					remove_tetriminos(e, square, p);
			}
			p.y += 1;
		}
		p.x += 1;
	}
	return (0);
}
