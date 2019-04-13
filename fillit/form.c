/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:58:33 by hghandi           #+#    #+#             */
/*   Updated: 2019/01/28 15:00:18 by mel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_get_all_str(int fd)
{
	char	*all_file;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		nbr_oct;

	all_file = NULL;
	tmp = NULL;
	while ((nbr_oct = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[nbr_oct] = '\0';
		if (!all_file)
			all_file = ft_strdup(buf);
		else
		{
			tmp = ft_strdup(all_file);
			free(all_file);
			all_file = NULL;
			all_file = ft_strjoin(tmp, buf);
			free(tmp);
			tmp = NULL;
		}
	}
	return (all_file);
}

char	*ft_file_to_str(char *file_name)
{
	int		fd;
	char	buf[1];
	char	*str;

	fd = open(file_name, O_RDONLY);
	if (fd == -1 || !file_name || read(fd, buf, 0) < 0)
		return (NULL);
	str = ft_get_all_str(fd);
	close(fd);
	return (str);
}

int		ft_check_symbols(int aux, char *str, int *i, int *nbr)
{
	while (*i < ((((*i + aux) / 5) + 1) * 5) - 1 - aux)
	{
		if ((str[*i] != '#' && str[*i] != '.') || *nbr > 4)
			return (-1);
		if (str[*i] == '#')
			*nbr += 1;
		*i += 1;
	}
	return (0);
}

int		ft_check_form(char *str)
{
	int		nbr_line;
	int		i;
	int		aux;
	int		nbr;

	ft_initialize1(&nbr, &aux, &i, &nbr_line);
	while (str[++i])
	{
		if ((((i + aux) / 5) + 1) % 5 == 0)
		{
			if (str[i] != '\n' || (str[i + 1] != '.' && str[i + 1] != '#'))
				return (-1);
			aux = aux + 4;
			i++;
			nbr = 0;
		}
		if (str[((((i + aux) / 5) + 1) * 5) - 1 - aux] != '\n')
			return (-1);
		if (ft_check_symbols(aux, str, &i, &nbr) == -1)
			return (-1);
	}
	if (((((i + aux) / 5) + 1) % 5 == 0 ||
		(((i + aux) / 5) + 1) == 4) && nbr == 4)
		return (1);
	return (-1);
}

char	**str_to_lines(char *str)
{
	char	**line;
	int		i;

	if (str == NULL)
		return (NULL);
	line = ft_strsplit(str, '\n');
	i = 0;
	while (line[i])
		i++;
	if (i > (26 * 4))
		return (NULL);
	return (line);
}
