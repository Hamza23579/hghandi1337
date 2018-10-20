/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 11:12:31 by hghandi           #+#    #+#             */
/*   Updated: 2018/09/06 11:12:33 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// int		ft_eight_queens_puzzle(void)
// {
	
// }

int		main(void)
{
	int		tab[8][8] = {0};
	int		i = 0;
	int		j = 0;

	while (i < 8)
	{
		while (j < 8)
		{
			printf("%d\n", tab[i][j]);
			j++;
		}
		j++;
	}
	return (0);
}