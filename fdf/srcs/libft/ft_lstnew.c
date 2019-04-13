/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <flan@gmail.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 22:31:28 by mderri            #+#    #+#             */
/*   Updated: 2018/10/18 22:31:31 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nv_mai;

	if (!(nv_mai = (t_list *)malloc(sizeof(t_list) * content_size)))
		return (NULL);
	if (content == NULL)
	{
		nv_mai->content = NULL;
		nv_mai->content_size = 0;
	}
	else
	{
		if (!(nv_mai->content = (void *)malloc(sizeof(void) * content_size)))
			return (NULL);
		ft_memcpy(nv_mai->content, content, content_size);
		nv_mai->content_size = content_size;
	}
	nv_mai->next = NULL;
	return (nv_mai);
}
