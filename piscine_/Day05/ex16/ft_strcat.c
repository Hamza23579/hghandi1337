/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:48:10 by hghandi           #+#    #+#             */
/*   Updated: 2018/09/12 20:48:12 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int i;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	dest[i] = src[0];
	i = 0;
	while (src[i] != '\0')
	{
		src[i] = src[i + 1];
		i++;
	}
	return (dest);
}
