/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:56:27 by hghandi           #+#    #+#             */
/*   Updated: 2018/10/22 11:56:29 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_nbr_mot(char const *s, char c)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			nbr++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (nbr);
}

static	size_t	ft_strlenc(const char *s, char c)
{
	size_t i;

	i = 0;
	while (*s && s[i] != c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**t1;
	size_t		i;
	size_t		j;

	if (!s)
		return (NULL);
	if (!(t1 = (char **)malloc(sizeof(char *) * (ft_nbr_mot(s, c) + 1))))
		return (NULL);
	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	j = 0;
	while (j < ft_nbr_mot(s, c))
	{
		if (!(t1[j] = (char *)malloc(sizeof(char) * ft_strlenc(s + i, c) + 1)))
			return (NULL);
		t1[j] = ft_strncpy(t1[j], &s[i], ft_strlenc(s + i, c));
		t1[j][ft_strlenc(s + i, c)] = '\0';
		j++;
		i += ft_strlenc(s + i, c);
		while (s[i] == c)
			i++;
	}
	t1[j] = NULL;
	return (t1);
}
