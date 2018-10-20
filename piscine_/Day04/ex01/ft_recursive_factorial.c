/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:18:48 by hghandi           #+#    #+#             */
/*   Updated: 2018/09/05 15:20:39 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (nb >= 0)
	{
		if (nb < 2)
		{
			return (1);
		}
		else
		{
			return (nb * ft_recursive_factorial(nb - 1));
		}
	}
	else
	{
		return (0);
	}
}
