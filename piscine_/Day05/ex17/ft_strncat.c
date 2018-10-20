/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 21:21:27 by hghandi           #+#    #+#             */
/*   Updated: 2018/09/12 21:21:28 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	int i;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	dest[i] = src[0];
	i = 0;
	while (src[i] != '\0' && i < nb)
	{
		src[i] = src[i + 1];
		i++;
	}
	src[i - 1] = '\0';
	return (dest);
}