/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 16:16:04 by hghandi           #+#    #+#             */
/*   Updated: 2019/02/11 17:58:40 by mel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nb)
{
	int		i;

	i = 1;
	while ((i * i) <= nb)
		i++;
	i--;
	if ((i * i) == nb)
		return (i);
	return (i + 1);
}

void	ft_afficher(int size, char **square)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(square[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		ft_bigger_square(char ***square, t_element *e, char **line)
{
	int		size;

	size = 0;
	while (line[size])
		size++;
	size = (ft_sqrt(size));
	*square = create_map(size);
	while (place_all_tetris(*square, size, e) != 1)
	{
		size++;
		ft_clean_square(*square);
		*square = create_map(size);
	}
	return (size);
}

int		main(int argc, char **argv)
{
	char		*str;
	char		**line;
	int			ret;
	t_element	*e;
	char		**square;

	str = ft_file_to_str(argv[argc - argc + 1]);
	line = str_to_lines(str);
	ret = ft_check(str, line, argc);
	if (ret == -1)
	{
		if (argc != 2)
			ft_putstr("usage: ./fillit valid_file\n");
		else
			ft_putstr("error\n");
		return (0);
	}
	e = store_elemnts(line);
	ft_redifine_coord(e);
	ret = ft_bigger_square(&square, e, line);
	ft_afficher(ret, square);
	ft_clean_all(square, e);
	ft_clean_square(line);
	ft_strdel(&str);
	return (0);
}
