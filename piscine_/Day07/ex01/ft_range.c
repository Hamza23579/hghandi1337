/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 12:59:34 by hghandi           #+#    #+#             */
/*   Updated: 2018/09/14 12:59:37 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*tab;
	int		i;
	int		j;

	i = 0;
	if (min >= max)
		return (NULL);
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
	}
	return (tab);
}
