/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 20:27:06 by hghandi           #+#    #+#             */
/*   Updated: 2018/10/22 20:27:08 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_nbr_digit(int n)
{
	int	cpt;

	cpt = 0;
	if (n < 0)
	{
		n *= (-1);
		cpt++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		cpt++;
	}
	return (cpt);
}

static	int		ft_power_ten(int nbr)
{
	int	res;

	res = 1;
	while (nbr-- > 0)
		res *= 10;
	return (res);
}

static char		*ft_holdnbr(int n)
{
	char	*holder;
	int		power;
	int		i;
	int		nbr;

	i = 0;
	if (n < 0)
		n *= (-1);
	nbr = ft_nbr_digit(n);
	power = ft_power_ten(ft_nbr_digit(n) - 1);
	holder = ft_strnew(nbr + 1);
	while (i < nbr)
	{
		holder[i++] = (n / power) + 48;
		n %= power;
		power /= 10;
	}
	holder[nbr + 1] = '\0';
	return (holder);
}

static	char	*ft_intmax(int n)
{
	char	*holder;
	int		nbr;
	int		i;

	n--;
	nbr = ft_nbr_digit(n);
	i = nbr + 1;
	holder = ft_strnew(nbr + 1);
	holder = ft_holdnbr(n);
	holder[nbr - 1] = '8';
	while (i > 0)
	{
		holder[i] = holder[i - 1];
		i--;
	}
	holder[0] = '-';
	holder[nbr + 1] = '\0';
	return (holder);
}

char			*ft_itoa(int n)
{
	char	*holder;
	int		i;

	if (!(holder = ft_strnew(ft_nbr_digit(n) + 1)))
		return (NULL);
	if (n >= 0)
		ft_strcpy(holder, ft_holdnbr(n));
	else if (n == -2147483648)
		ft_strcpy(holder, ft_intmax(n));
	else
	{
		i = ft_nbr_digit(n) + 1;
		ft_strcpy(holder, ft_holdnbr(n));
		while (i > 0)
		{
			holder[i] = holder[i - 1];
			i--;
		}
		holder[0] = '-';
		holder[ft_nbr_digit(n) + 1] = '\0';
	}
	return (holder);
}
