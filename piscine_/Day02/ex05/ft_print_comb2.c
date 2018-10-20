/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 15:04:27 by hghandi           #+#    #+#             */
/*   Updated: 2018/09/02 00:41:42 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print(int a)
{
	int		first_d;
	int		second_d;
	char	first_c;
	char	second_c;

	first_d = a / 10;
	second_d = a % 10;
	first_c = first_d + 48;
	second_c = second_d + 48;
	ft_putchar(first_c);
	ft_putchar(second_c);
}

void	ft_print_comb2(void)
{
	int	a;
	int	i;

	i = 0;
	while (i <= 98)
	{
		a = i + 1;
		while (a <= 99)
		{
			ft_print(i);
			ft_putchar(' ');
			ft_print(a);
			if (a != 99 || i != 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			a++;
		}
		i++;
	}
}
