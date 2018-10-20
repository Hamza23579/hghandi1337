/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:11:52 by hghandi           #+#    #+#             */
/*   Updated: 2018/09/05 16:11:57 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (power >= 0)
	{
		if (power < 1)
		{
			return (1);
		}
		return (nb * ft_recursive_power(nb, (power - 1)));
	}
	return (0);
}
