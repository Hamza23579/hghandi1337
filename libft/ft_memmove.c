/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 17:07:31 by hghandi           #+#    #+#             */
/*   Updated: 2018/10/15 17:07:36 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*t1;
	char		*t2;

	i = 0;
	t1 = (char *)dst;
	t2 = (char *)src;
	if (dst <= src)
		dst = ft_memcpy(t1, t2, len);
	else
		while (len--)
			*(t1 + len) = *(t2 + len);
	return (dst);
}
