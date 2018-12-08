/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 12:50:29 by hghandi           #+#    #+#             */
/*   Updated: 2018/10/15 12:50:31 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*t1;
	const char	*t2;

	i = 0;
	t1 = dst;
	t2 = src;
	while (i < n)
	{
		t1[i] = t2[i];
		i++;
	}
	return (dst);
}
