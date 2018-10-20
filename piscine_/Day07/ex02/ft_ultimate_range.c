/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 16:04:03 by hghandi           #+#    #+#             */
/*   Updated: 2018/09/16 16:04:05 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		*tab;
	int		j;
	int		i;

	i = 0;
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	else
	{
		j = max - min;
		tab = (int *)malloc(sizeof(int) * (j + 1));
		while (i < j)
		{
			tab[i] = min + i;
			i++;
		}
		tab[i] = 0;
		*range = tab;
	}
	return (j);
}
