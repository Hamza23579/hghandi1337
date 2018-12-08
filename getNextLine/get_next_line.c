/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:25:10 by hghandi           #+#    #+#             */
/*   Updated: 2018/11/11 18:23:50 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_get_index(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	static	char	*oldstr[4864];
	char			buff[BUFF_SIZE + 1];
	int				i;
	int				finder;

	finder = 0;
	if (fd < 0 || read(fd, buff, 0) < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	if (!oldstr[fd])
		oldstr[fd] = ft_strnew(0);
	while ((i = read(fd, buff, BUFF_SIZE)))
	{
		buff[i] = '\0';
		oldstr[fd] = ft_strjoin(oldstr[fd], buff);
		if (ft_strchr(oldstr[fd], '\n'))
			break ;
	}
	finder = ft_get_index(oldstr[fd]);
	*line = ft_strsub(oldstr[fd], 0, finder);
	if (i == 0 && ft_strlen(oldstr[fd]) == 0)
		return (0);
	oldstr[fd] = ft_strdup(oldstr[fd] + finder + 1);
	return (1);
}
