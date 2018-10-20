/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 17:19:59 by hghandi           #+#    #+#             */
/*   Updated: 2018/09/16 17:20:00 by hghandi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_lenght(int argc, char **argv)
{
	int		i;
	int		j;
	int		*l;

	i = 1;
	l = (int *)malloc(sizeof(int) * argc);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			j++;
		}
		l[i] = j;
		i++;
	}
	return (l);
}

char	*ft_table(int argc, char **argv, int *l, char *t)
{
	int		i;
	int		j;
	int		end;

	i = 0;
	j = 0;
	end = 0;
	while (i < argc)
	{
		j = 0;
		while (j < l[i])
		{
			t[end + j] = argv[i][j];
			j++;
			if (j == l[i] && i != (argc - 1))
			{
				t[end + j] = '\n';
				j++;
			}
		}
		end += j;
		i++;
	}
	return (t);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		*l;
	int		i;
	int		j;
	char	*t;

	l = ft_lenght(argc, argv);
	j = 0;
	i = 0;
	while (i < argc)
	{
		j += l[i];
		i++;
	}
	t = (char *)malloc(sizeof(char) * (j + 1));
	t[j - 1] = '\n';
	t = ft_table(argc, argv, l, t);
	t[j] = '\0';
	return (t);
}
