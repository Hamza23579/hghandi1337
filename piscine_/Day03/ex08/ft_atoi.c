/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 19:16:08 by hghandi           #+#    #+#             */
/*   Updated: 2018/09/03 19:16:11 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_change(int *i, int *j)
{
	*i = *i - 1;
	*j = *j + 1;
}

void	ft_init(int *i, int *j, int *numr, char *str)
{
	int		temp;

	*numr = 0;
	*j = 0;
	while (str[*j] == ' ')
	{
		*j = *j + 1;
	}
	temp = *j;
	if (str[temp] == '+' || str[temp] == '-')
		temp = temp + 1;
	if (str[temp] > '9' || str[temp] < '0')
		*i = 0;
	while ((str[temp] <= '9') && (str[temp] >= '0'))
	{
		*i = *i + 1;
		temp = temp + 1;
	}
}

int		ft_calcul(int *i, int *j, char *str, int *numr)
{
	if (str[*j] == '-')
	{
		if (str[*j + 1] > '9' || str[*j + 1] < '0')
			return (0);
		else
		{
			*i = *i - 1;
			*j = *j + 1;
			while (str[*j] != ' ')
			{
				*numr = *numr * 10 + (str[*j] - 48);
				ft_change(i, j);
			}
			return ((-1) * (*numr));
		}
	}
	else
	{
		while (str[*j] != ' ')
		{
			*numr = *numr * 10 + (str[*j] - 48);
			ft_change(i, j);
		}
		return (*numr);
	}
}

int		ft_atoi(char *str)
{
	int		i;
	int		j;
	int		numr;

	ft_init(&i, &j, &numr, str);
	if (str[j] == '+')
	{
		if (str[j + 1] > '9' || str[j + 1] < '0')
		{
			return (0);
		}
		else
		{
			ft_change(&i, &j);
			while (str[j] != ' ')
			{
				numr = numr * 10 + (str[j] - 48);
				ft_change(&i, &j);
			}
			return (numr);
		}
	}
	return (ft_calcul(&i, &j, str, &numr));
}
