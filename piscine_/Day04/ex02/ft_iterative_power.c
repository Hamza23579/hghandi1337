/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:47:45 by hghandi           #+#    #+#             */
/*   Updated: 2018/09/05 15:47:50 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int		pow;

	pow = 1;
	if (power >= 0)
	{
		if (power == 0)
		{
			return (1);
		}
		while (power > 0)
		{
			pow *= nb;
			power--;
		}
		return (pow);
	}
	return (0);
}
