/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 00:03:09 by mderri            #+#    #+#             */
/*   Updated: 2018/10/14 00:03:11 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*s3;
	size_t		i;

	i = 0;
	s3 = (char *)malloc(sizeof(char) * (len + 1));
	if (s3 == NULL || s == NULL)
		return (NULL);
	while (i < len)
	{
		s3[i] = s[start + i];
		i++;
	}
	s3[i] = '\0';
	return (s3);
}
