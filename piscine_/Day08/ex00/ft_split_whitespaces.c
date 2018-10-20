/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:57:19 by hghandi           #+#    #+#             */
/*   Updated: 2018/09/17 15:57:22 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_whitespace(char *str, int i)
{
	if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
	{
		return (1);
	}
	else if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
	{
		return (0);
	}
	return (0);
}

int		ft_lenght(char *str)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		while (ft_is_whitespace(str, i) && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			words += 1;
		i++;
		while (!(ft_is_whitespace(str, i)) && str[i] != '\0')
			i++;
	}
	return (words);
}

char	*ft_assign(char *str, int i)
{
	char	*t;
	int		end;
	int		k;

	end = 0;
	k = i;
	while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\0')
		i++;
	end = i - k;
	t = (char *)malloc(sizeof(char) * (end + 1));
	k = 0;
	while (k < end)
	{
		t[k] = str[i - end];
		k++;
		i++;
	}
	t[k] = '\0';
	return (t);
}

char	**ft_split_whitespaces(char *str)
{
	char	**sent;
	int		l;
	int		i;
	int		j;

	j = 0;
	i = 0;
	l = ft_lenght(str);
	sent = (char **)malloc(sizeof(char *) * l);
	while (str[i] != '\0' && j < l)
	{
		while (ft_is_whitespace(str, i) && str[i] != '\0')
			i++;
		sent[j] = ft_assign(str, i);
		j++;
		while (!(ft_is_whitespace(str, i)) && str[i] != '\0')
			i++;
	}
	sent[j] = NULL;
	return (sent);
}
