/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 14:49:36 by hghandi           #+#    #+#             */
/*   Updated: 2018/10/20 14:49:39 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*t;

	i = ft_strlen(s);
	t = (char *)s;
	if ((char)c == '\0')
	{
		while (t[i] != '\0')
			i++;
		return (&t[i]);
	}
	else
	{
		while (i--)
		{
			if (t[i] == (char)c)
				return (&t[i]);
		}
	}
	return (NULL);
}
