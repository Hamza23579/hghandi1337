/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 14:16:31 by hghandi           #+#    #+#             */
/*   Updated: 2018/10/20 14:16:34 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*t;

	i = 0;
	t = (char *)s;
	if ((char)c == '\0')
	{
		while (t[i] != '\0')
			i++;
		return (&t[i]);
	}
	else
	{
		while (t[i] != '\0')
		{
			if (t[i] == (char)c)
				return (&t[i]);
			i++;
		}
	}
	return (NULL);
}
