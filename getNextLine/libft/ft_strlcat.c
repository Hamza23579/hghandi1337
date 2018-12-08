/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 21:36:57 by hghandi           #+#    #+#             */
/*   Updated: 2018/10/19 21:36:59 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dsize;

	i = 0;
	while (dst[i] != '\0')
		i++;
	dsize = 0;
	while (src[dsize] != '\0')
		dsize++;
	if (i >= size)
		dsize += size;
	else
		dsize += i;
	j = 0;
	while (i + 1 < size && src[j] != '\0')
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (dsize);
}
