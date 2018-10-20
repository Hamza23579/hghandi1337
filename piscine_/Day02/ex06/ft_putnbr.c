/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 10:00:05 by hghandi           #+#    #+#             */
/*   Updated: 2018/09/02 10:56:45 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int		ft_nombre_digit(int nbr)
{
	int		i;

	i = 0;
	if (nbr == 0)
	{
		i = 1;
		return (i);
	}
	else
	{
		while (nbr != 0)
		{
			nbr = nbr / 10;
			i++;
		}
	}
	return (i);
}

int		ft_puissance(int nbr, int p)
{
	if (p == 0)
	{
		return (1);
	}
	else
	{
		return (ft_puissance(nbr, p - 1) * nbr);
	}
}

void	ft_afficher(int *mod, int *div, int a, int nb)
{
	*mod = nb % ft_puissance(10, a - 1);
	*div = nb / ft_puissance(10, a - 1);
}

void	ft_put_max(void)
{
	int		max_i;
	int		a;
	int		div;
	int		mod;
	char	nbr;

	max_i = 2147483647;
	a = ft_nombre_digit(max_i);
	ft_putchar('-');
	while (a > 0)
	{
		if (a == 1)
		{
			ft_putchar('8');
			break ;
		}
		else
		{
			ft_afficher(&mod, &div, a, max_i);
			nbr = '0' + div;
			ft_putchar(nbr);
			a--;
			max_i = mod;
		}
	}
}

void	ft_putnbr(int nb)
{
	int		a;
	int		mod;
	int		div;

	if (nb == -2147483648)
	{
		ft_put_max();
	}
	else
	{
		a = ft_nombre_digit(nb);
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -1 * nb;
		}
		while (a > 0)
		{
			ft_afficher(&mod, &div, a, nb);
			ft_putchar('0' + div);
			a--;
			nb = mod;
		}
	}
}
