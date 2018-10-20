/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:36:13 by hghandi           #+#    #+#             */
/*   Updated: 2018/09/05 10:36:15 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		fact;

	fact = 1;
	if (nb >= 0)
	{
		if (nb < 2)
		{
			return (1);
		}
		else
		{
			while (nb > 1)
			{
				fact *= nb;
				nb--;
			}
			return (fact);
		}
	}
	return (0);
}
