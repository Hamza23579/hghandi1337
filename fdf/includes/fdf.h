/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <mderri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:19:23 by mderri            #+#    #+#             */
/*   Updated: 2019/02/10 19:19:25 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"
# include <math.h>

# define ESC 53
# define P 35
# define I 34
# define C 8
# define OR O_RDONLY

typedef struct	s_mlx
{
	void *ptr;
	void *win;
	void *win2;
}				t_mlx;

typedef struct	s_point
{
	int x;
	int y;
	int z;
}				t_point;

typedef struct	s_chemin
{
	t_point pi;
	t_point pf;
}				t_chemin;

typedef struct	s_map
{
	int			**map;
	t_mlx		mlx;
	int			nligne;
	int			ncol;
	int			is_iso;
	t_chemin	k;
	t_point		move;
	t_point		center;
	int			is_center;
	int			scale;
	int			height;
	int			width;
	int			height_size;
	int			j;
	int			v;
	int			i;

}				t_map;

void			dessinligne(t_mlx mlx, t_chemin c, int color);
void			dessinmap(t_map *map);
void			readmap(char *arg, t_map *map);
void			init_nb_ligne_col(int fd, t_map *map);
void			dessinhori_iso(t_map map);
void			dessinverti_iso(t_map map);
t_map			dessinhori_paral(t_map map);
t_map			dessinverti_paral(t_map map);
void			zoom_and_height(int keycode, t_map *map);
void			move(int keycode, t_map *map);
void			bigger_smaller_window(int keycode, t_map *map);
void			iso_para_conversion(int keycode, t_map *map);
void			center(int keycode, t_map *map);
int				event_handle(int keycode, t_map *map);
void			calcule_move_para(t_map *map, t_chemin c);
void			calcule_move_iso(t_map *map, t_chemin c);
void			iso_loop1(t_map *map, t_chemin *c);
void			iso_loop2(t_map *map, t_chemin *c);
void			iso(int *x, int *y, int z, t_map map);
void			free_map(t_map *m);
void			ft_close(t_map *m);
int				verify(char *name, t_map *map);
int				condition(int keycode);

#endif
