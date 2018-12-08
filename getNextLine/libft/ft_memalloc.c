/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 14:14:42 by hghandi           #+#    #+#             */
/*   Updated: 2018/10/21 14:14:44 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*t;
	size_t	i;

	i = 0;
	t = NULL;
	if (size > 0)
	{
		t = (void *)malloc(sizeof(unsigned char) * size);
		if (t == NULL)
			return (NULL);
		while (i < size)
			t[i++] = 0;
		return (t);
	}
	return (t);
}
