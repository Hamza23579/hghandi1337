/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataStructure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:29:20 by hghandi           #+#    #+#             */
/*   Updated: 2019/01/23 21:29:24 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_go_through(char **line, t_element *t, int i, int aux)
{
	int		j;

	while (line[i])
	{
		j = 0;
		if (i % 4 == 0 && i != 0)
		{
			t->next = (t_element *)malloc(sizeof(t_element) * 1);
			t->next->val = t->val + 1;
			t = t->next;
			t->next = NULL;
			aux = 0;
		}
		while (j < 4)
		{
			if (line[i][j] == '#')
			{
				t->coord[aux][0] = i % 4;
				t->coord[aux][1] = j;
				aux++;
			}
			j++;
		}
		i++;
	}
}

t_element	*store_elemnts(char **line)
{
	t_element	*t;
	t_element	*tete;
	int			i;
	int			aux;

	i = 0;
	aux = 0;
	t = (t_element *)malloc(sizeof(t_element));
	t->next = NULL;
	t->val = 'A';
	tete = t;
	ft_go_through(line, t, i, aux);
	return (tete);
}

char		**create_map(int n)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * n);
	i = 0;
	while (i < n)
	{
		map[i] = (char *)malloc(sizeof(char) * n);
		i++;
	}
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
			map[i][j++] = '.';
		i++;
	}
	return (map);
}
