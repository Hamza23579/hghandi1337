/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 23:35:15 by hghandi           #+#    #+#             */
/*   Updated: 2018/10/18 23:35:17 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int		i;
	int		j;

	i = ft_strlen(src);
	j = 0;
	while (j < i)
	{
		dst[j] = src[j];
		j++;
	}
	dst[i] = '\0';
	return (dst);
}
