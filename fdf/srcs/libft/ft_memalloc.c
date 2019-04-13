/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 20:05:31 by mderri            #+#    #+#             */
/*   Updated: 2018/10/13 20:05:33 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t *zf;
	size_t i;

	i = 0;
	zf = (size_t *)malloc(sizeof(zf) * size);
	if (zf == NULL)
		return (NULL);
	while (i <= size)
	{
		zf[i] = 0;
		i++;
	}
	return (zf);
}
