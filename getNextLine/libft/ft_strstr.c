/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 15:10:08 by hghandi           #+#    #+#             */
/*   Updated: 2018/10/20 15:10:09 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
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
	while (t[i] != '\0')
	{
		j = 0;
		cmpt = i;
		while (needle[j] == t[cmpt])
		{
			if (needle[j + 1] == '\0')
				return (&t[i]);
			j++;
			cmpt++;
		}
		i++;
	}
	return (NULL);
}
