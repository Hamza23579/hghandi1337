/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 22:36:58 by hghandi           #+#    #+#             */
/*   Updated: 2018/10/09 21:37:14 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	while (src[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(*str) * (i + 1));
	j = 0;
	while (src[j] != '\0')
	{
		str[j] = src[j];
		j++;
	}
	str[i] = '\0';
	return (str);
}
