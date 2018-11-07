/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:07:46 by hghandi           #+#    #+#             */
/*   Updated: 2018/10/15 16:08:11 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const	void *src, int c, size_t n)
{
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *)src;
	t2 = (unsigned char *)dst;
	while (n--)
	{
		*(t2++) = *(t1++);
		if (*(t1 - 1) == (unsigned char)c)
			return (t2);
	}
	return (NULL);
}
