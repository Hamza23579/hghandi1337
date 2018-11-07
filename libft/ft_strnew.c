/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 15:24:48 by hghandi           #+#    #+#             */
/*   Updated: 2018/10/21 15:24:50 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*t;
	size_t	i;

	t = NULL;
	i = 0;
	if ((int)size >= 0)
	{
		t = (char *)malloc(sizeof(char) * (size + 1));
		if (t == NULL)
			return (NULL);
		while (i < size)
			t[i++] = '\0';
		t[i] = '\0';
		return (t);
	}
	return (t);
}
