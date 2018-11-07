/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 17:25:24 by hghandi           #+#    #+#             */
/*   Updated: 2018/10/23 17:25:25 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n < 10 && n >= 0)
		ft_putchar('0' + n);
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar('0' + (n % 10));
	}
	else if (n < 0 && n > -10)
	{
		ft_putchar('-');
		n *= (-1);
		ft_putchar('0' + n);
	}
	else
	{
		ft_putchar('-');
		ft_putnbr(-1 * (n / 10));
		ft_putchar('0' + (n % 10) * (-1));
	}
}
