/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionnal_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:54:56 by hghandi           #+#    #+#             */
/*   Updated: 2019/02/11 17:58:45 by mel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_extract_max(int coord[4][2], int i)
{
	int		max;
	int		j;

	j = 0;
	max = coord[0][i];
	while (j < 4)
	{
		if (coord[j][i] > max)
			max = coord[j][i];
		j++;
	}
	return (max);
}

int		ft_extract_min(int coord[4][2], int i)
{
	int		min;
	int		j;

	j = 0;
	min = coord[0][i];
	while (j < 4)
	{
		if (coord[j][i] < min)
			min = coord[j][i];
		j++;
	}
	return (min);
}

void	ft_initialize1(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = -1;
	*d = 0;
}

void	ft_clean_all(char **square, t_element *e)
{
	int			i;
	int			j;
	t_element	*tmp;

	i = ft_strlen(square[0]);
	j = 0;
	while (j < i)
	{
		free(square[j]);
		square[j] = NULL;
		j++;
	}
	square = NULL;
	while (e != NULL)
	{
		tmp = e->next;
		free(e);
		e = tmp;
	}
	e = NULL;
}

void	ft_clean_square(char **square)
{
	int			i;
	int			j;

	j = 0;
	i = ft_strlen(square[0]);
	while (j < i)
	{
		free(square[j]);
		square[j] = NULL;
		j++;
	}
	square = NULL;
}
