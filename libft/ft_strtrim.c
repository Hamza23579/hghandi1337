/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:08:57 by hghandi           #+#    #+#             */
/*   Updated: 2018/10/22 11:09:00 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*t;
	int		len;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	i = 0;
	while ((s[i] == '\t' || s[i] == '\n' || s[i] == ' ') && s[i] != '\0')
		i++;
	if (i == (len + 1))
		return (ft_strnew(1));
	while (s[len] == '\t' || s[len] == '\n' || s[len] == ' ')
		len--;
	len = len - i + 1;
	t = (char *)malloc(sizeof(char) * (len + 1));
	if (!t)
		return (NULL);
	j = 0;
	while (j < len)
		t[j++] = s[i++];
	t[j] = '\0';
	return (t);
}
