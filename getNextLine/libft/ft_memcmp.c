/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 20:12:59 by hghandi           #+#    #+#             */
/*   Updated: 2018/10/18 20:13:03 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*t1;
	char	*t2;

	t1 = (char *)s1;
	t2 = (char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (*(t1 + i) == *(t2 + i) && i < n)
	{
		i++;
		if (i == n)
			return (0);
	}
	return ((unsigned char)*(t1 + i) - (unsigned char)*(t2 + i));
}
