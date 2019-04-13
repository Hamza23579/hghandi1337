/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghandi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:17:45 by hghandi           #+#    #+#             */
/*   Updated: 2019/02/11 17:55:44 by mel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFF_SIZE 100

typedef	struct	s_elements
{
	int					coord[4][2];
	char				val;
	struct s_elements	*next;
}				t_element;

typedef	struct	s_points
{
	int		x;
	int		y;
}				t_point;

char			*ft_get_all_str(int fd);
char			*ft_file_to_str(char *file_name);
int				ft_check_symbols(int aux, char *str, int *i, int *nbr);
int				ft_check_form(char *str);
char			**str_to_lines(char *str);
void			ft_nbr_voisins_deb(char **line, int *i, int *nbr);
void			ft_nbr_voisins_fin(char **line, int *i, int *nbr);
void			ft_nbr_voisins_mil(char **line, int *i, int *nbr);
int				ft_check_tetriminos(char **line);
int				ft_check(char *str, char **line, int argc);

void			ft_go_through(char **line, t_element *t, int i, int aux);
t_element		*store_elemnts(char **line);
char			**create_map(int n);

void			ft_redifine_coord(t_element *e);
int				place_tetrimino(char **square, int n, t_element *e, t_point p);
void			remove_tetriminos(t_element *e, char **square, t_point p);
int				place_all_tetris(char **square, int n, t_element *e);

int				ft_extract_max(int coord[4][2], int i);
int				ft_extract_min(int coord[4][2], int i);
void			ft_initialize1(int *a, int *b, int *c, int *d);
void			ft_afficher(int size, char **square);
int				ft_bigger_square(char ***square, t_element *e, char **line);
int				ft_sqrt(int nb);
void			ft_clean_all(char **square, t_element *e);
void			ft_clean_square(char **square);

#endif
