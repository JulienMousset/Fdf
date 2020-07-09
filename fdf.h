/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 11:17:37 by jmousset          #+#    #+#             */
/*   Updated: 2020/07/09 12:24:52 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define ESC 53
# define R 15
# define E 14
# define Q 12
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define MINUS 27
# define PLUS 24
# define O 31
# define P 35

typedef struct	s_line
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		xinc;
	int		yinc;
}				t_line;

typedef struct	s_map
{
	int		**board;
	char	**tmp;
	char	*line;
	int		nb_lines;
	int		nb_columns;
}				t_map;

typedef struct	s_env
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data_ptr;
	int		bpp;
	int		s_l;
	int		endian;
	int		is_iso;
	int		starting_x;
	int		starting_y;
	int		scale_x;
	int		scale_y;
	float	zoom;
	float	altitude;
	int		palette;
	char	*file;
	t_map	*map;
	t_line	*line;
}				t_env;

int				fdf(char *file);
int				init_structure(t_env *env, char *file);
float			check_altitude(t_map *map, int nb_lines, int nb_columns);
void			print_menu(t_env *env, char *file);

int				parsing(t_map *map, char *file);
int				check_file(t_map *map, char *file);
int				count_lines(t_map *map, char *file);
int				count_columns(char *s);
int				fill_board(t_map *map, int fd);

void			draw_parallel_h1(t_env *env, t_map *map);
void			draw_parallel_h2(t_env *env, t_map *map, int i, int j);
void			draw_parallel_v1(t_env *env, t_map *map);
void			draw_parallel_v2(t_env *env, t_map *map, int i, int j);

void			init_iso(t_env *env, int i);
void			draw_iso_h1(t_env *env, t_map *map);
void			draw_iso_h2(t_env *env, t_map *map, int i, int j);
void			draw_iso_v1(t_env *env, t_map *map);
void			draw_iso_v2(t_env *env, t_map *map, int i, int j);

void			draw_line(t_env *env, t_line *line, int z);
void			horizontal_line(t_env *env, t_line *line, int z);
void			vertical_line(t_env *env, t_line *line, int z);
void			fill_pixel(t_env *env, int x, int y, int color);
int				check_int_max(char *s);

int				deal_key(int key, t_env *env);
void			reset_parallel(t_env *env);
void			reset_iso(t_env *env);
void			change_to_iso(t_env *env);
void			change_to_parallel(t_env *env);

int				deal_key_2(int key, t_env *env);
void			move_up(t_env *env);
void			move_down(t_env *env);
void			move_left(t_env *env);
void			move_right(t_env *env);

int				close_program(t_env *env);
void			zoom_in(t_env *env);
int				zoom_out(t_env *env);
void			higher(t_env *env);
void			lower(t_env *env);

void			choose_color_1(t_env *env, int x, int y, int z);
void			choose_color_2(t_env *env, int x, int y, int z);
void			color_palette_1(t_env *env);
void			color_palette_2(t_env *env);

void			no_data_found(void);
void			free_tmp_board(char **s);
void			free_all(t_env *env);
#endif
