/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 19:06:26 by hghandi           #+#    #+#             */
/*   Updated: 2018/10/15 19:06:29 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*t;

	i = 0;
	t = (char *)s;
	if (n != 0)
	{
		while (i < n)
		{
			if (*t == (char)c)
			{
				return (t);
			}
			else
				t++;
			i++;
		}
	}
	return (NULL);
}
