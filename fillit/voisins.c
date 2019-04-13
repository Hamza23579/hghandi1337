/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   voisins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 18:01:27 by hghandi           #+#    #+#             */
/*   Updated: 2019/02/11 17:59:12 by mel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_nbr_voisins_deb(char **line, int *i, int *nbr)
{
	int		j;

	j = 0;
	while (line[*i][j])
	{
		if (line[*i][j] == '#')
		{
			if (line[*i][j + 1] == '#')
				(*nbr)++;
			if (line[*i][j - 1] == '#')
				(*nbr)++;
			if (line[(*i) + 1][j] == '#')
				(*nbr)++;
		}
		j++;
	}
}

void	ft_nbr_voisins_fin(char **line, int *i, int *nbr)
{
	int		j;

	j = 0;
	while (line[*i][j])
	{
		if (line[*i][j] == '#')
		{
			if (line[*i][j + 1] == '#')
				(*nbr)++;
			if (line[*i][j - 1] == '#')
				(*nbr)++;
			if (line[(*i) - 1][j] == '#')
				(*nbr)++;
		}
		j++;
	}
}

void	ft_nbr_voisins_mil(char **line, int *i, int *nbr)
{
	int		j;

	j = 0;
	while (line[*i][j])
	{
		if (line[*i][j] == '#')
		{
			if (line[*i][j + 1] == '#')
				(*nbr)++;
			if (line[*i][j - 1] == '#')
				(*nbr)++;
			if (line[(*i) - 1][j] == '#')
				(*nbr)++;
			if (line[(*i) + 1][j] == '#')
				(*nbr)++;
		}
		j++;
	}
}

int		ft_check_tetriminos(char **line)
{
	int		i;
	int		j;
	int		nbr;

	i = -1;
	j = 0;
	nbr = 0;
	while (line[++i])
	{
		if (i % 4 == 0)
			ft_nbr_voisins_deb(line, &i, &nbr);
		if (i % 4 == 3)
		{
			ft_nbr_voisins_fin(line, &i, &nbr);
			if (nbr != 6 && nbr != 8)
				return (-1);
			nbr = 0;
		}
		if (i % 4 == 2 || i % 4 == 1)
			ft_nbr_voisins_mil(line, &i, &nbr);
	}
	return (1);
}

int		ft_check(char *str, char **line, int argc)
{
	int		ret;

	if (argc != 2)
		return (-1);
	if (str == NULL || line == NULL)
		return (-1);
	if (ft_strlen(str) < 20)
		return (-1);
	if ((ret = ft_check_form(str)) == -1)
		return (-1);
	if (line == NULL)
		return (-1);
	if ((ret = ft_check_tetriminos(line)) == -1)
		return (-1);
	return (1);
}
