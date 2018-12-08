/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 20:29:14 by hghandi           #+#    #+#             */
/*   Updated: 2018/10/20 20:29:16 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_calculer(const char *str, int *i, int *nbr)
{
	int		cmpt;
	int		sign;

	if (str[*i - 1] == '-')
		sign = 1;
	else
		sign = 0;
	cmpt = 0;
	while (str[*i] != '\0' && str[*i] <= '9' && str[*i] >= '0')
	{
		cmpt++;
		*nbr = *nbr * 10 + str[*i] - '0';
		*i += 1;
	}
	if (cmpt > 10)
	{
		if (sign == 1)
			*nbr = 0;
		else if (sign == 0)
			*nbr = -1;
	}
}

static	int		ft_decide(int *nbr, int *sign)
{
	if (*sign == 1)
		return (-(*nbr));
	else
		return (*nbr);
}

int				ft_atoi(const char *str)
{
	int		i;
	int		nbr;
	int		sign;

	sign = 0;
	nbr = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ' ||
			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
			i++;
		if (str[i] == '-')
		{
			sign = 1;
			i++;
		}
		else if (str[i] == '+')
			i++;
		if (str[i] == '-' || str[i] == '+')
			return (0);
		ft_calculer(str, &i, &nbr);
		break ;
	}
	return (ft_decide(&nbr, &sign));
}
