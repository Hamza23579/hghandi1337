/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 23:14:23 by hghandi           #+#    #+#             */
/*   Updated: 2018/09/08 17:24:24 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_indicator(int nb, int mid, int i)
{
	while (i <= mid)
	{
		if ((nb % i) == 0)
		{
			return (0);
		}
		i += 2;
	}
	return (1);
}

int		ft_is_prime(int nb)
{
	int		i;
	int		j;
	int		mid;

	mid = nb / 2;
	i = 3;
	j = -3;
	if (nb < 0)
	{
		return (0);
	}
	else if (nb == 2)
		return (1);
	if (nb == 0 || nb == 1)
		return (0);
	else if ((nb % 2) == 0)
		return (0);
	else if (nb > 0)
		return (ft_indicator(nb, mid, i));
	return (0);
}

int		ft_find_next_prime(int nb)
{
	int		i;

	i = 0;
	if (nb < 0)
	{
		return (2);
	}
	while (ft_is_prime(nb + i) != 1)
	{
		i++;
	}
	return (nb + i);
}
