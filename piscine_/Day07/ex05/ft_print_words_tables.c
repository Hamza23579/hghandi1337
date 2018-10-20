/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 21:25:52 by hghandi           #+#    #+#             */
/*   Updated: 2018/09/19 21:25:55 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_print_words_tables(char **tab)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (tab[i] != NULL)
		i++;
	while (j < i)
	{
		ft_putstr(tab[j]);
		ft_putchar('\n');
		j++;
	}
}
