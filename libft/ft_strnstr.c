/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 15:35:52 by hghandi           #+#    #+#             */
/*   Updated: 2018/10/20 15:35:54 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	int		cmpt;
	char	*t;

	i = 0;
	t = (char *)haystack;
	if (*needle == '\0')
	{
		return (t);
	}
	while (t[i] != '\0' && (unsigned int)(i + ft_strlen(needle)) <= len)
	{
		j = 0;
		cmpt = i;
		while (needle[j] == t[cmpt])
		{
			j++;
			cmpt++;
			if (needle[j] == '\0')
				return (&t[i]);
		}
		i++;
	}
	return (NULL);
}
