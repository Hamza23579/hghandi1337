/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <mderri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:44:21 by mderri            #+#    #+#             */
/*   Updated: 2019/02/11 18:44:23 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int		ft_count_words(char const *s, char c)
{
	int			v;
	int			i;
	int			cnt_word;

	i = 0;
	v = 0;
	cnt_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && v == 0)
		{
			v = 1;
			cnt_word++;
		}
		else if (s[i] == c && v == 1)
			v = 0;
		i++;
	}
	return (cnt_word);
}

int				init_and_loop(int fd, char *line, t_map *map)
{
	map->i = 0;
	map->j = 0;
	map->v = 0;
	while (get_next_line(fd, &line))
	{
		if ((map->i = ft_count_words(line, ' ')) == 0 ||
		(map->i - map->j != 0 && map->v == 1))
			return (1);
		map->v = 1;
		map->j = map->i;
	}
	free(line);
	close(fd);
	return (0);
}

int				verify(char *name, t_map *map)
{
	char		*line;
	int			fd;

	fd = open(name, O_RDONLY);
	line = NULL;
	if ((map->i = get_next_line(fd, &line)) < 0)
	{
		free(line);
		close(fd);
		return (1);
	}
	if (ft_strlen(line) == 0)
		return (1);
	return (init_and_loop(fd, line, map));
}

void			init_nb_ligne_col(int fd, t_map *map)
{
	char		*line;
	int			i;

	i = 0;
	while (get_next_line(fd, &line))
	{
		if (i == 0)
			map->ncol = ft_count_words(line, ' ');
		i++;
	}
	map->nligne = i;
	free(line);
}

void			readmap(char *arg, t_map *map)
{
	t_point		inc;
	char		**tmp;
	char		*line;
	int			fd;

	fd = open(arg, O_RDONLY);
	map->map = malloc(sizeof(int) * map->nligne);
	inc.y = 0;
	while (get_next_line(fd, &line))
	{
		map->map[inc.y] = malloc(sizeof(int) * map->ncol);
		tmp = ft_strsplit(line, ' ');
		inc.x = 0;
		while (inc.x < map->ncol)
		{
			map->map[inc.y][inc.x] = ft_atoi(tmp[inc.x]);
			inc.x++;
		}
		free(tmp);
		inc.y++;
	}
	free(line);
	close(fd);
}
