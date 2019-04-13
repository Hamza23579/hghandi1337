/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 23:14:53 by mderri            #+#    #+#             */
/*   Updated: 2018/10/13 23:14:56 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*zf;
	char	*aux;
	size_t	i;

	i = 0;
	aux = (char *)s;
	if (aux == NULL)
		return (NULL);
	zf = (char *)malloc(sizeof(char) * (ft_strlen(aux) + 1));
	if (zf == NULL)
		return (NULL);
	while (i < ft_strlen(aux))
	{
		zf[i] = (*f)(i, aux[i]);
		i++;
	}
	zf[i] = '\0';
	return (zf);
}
