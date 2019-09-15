/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 12:08:03 by jmousset          #+#    #+#             */
/*   Updated: 2019/09/15 15:01:33 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_env *env, char *file)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 1040, 0xFFF8FF, file);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 20, 0xFFF8FF,
	"ESC : Close Program");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 60, 0xFFF8FF, "R : Reset");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 480, 20, 0xFFF8FF,
	"E : Switch view");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 820, 20, 0xFFF8FF,
	"Q : Switch color palette");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 1240, 20, 0xFFF8FF,
	"WASD : Move");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 1740, 20, 0xFFF8FF,
	"+/- : Zoom");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 1740, 60, 0xFFF8FF,
	"O/P : Altitudes");
}

float	check_altitude(t_map *map, int nb_lines, int nb_columns)
{
	int		i;
	int		j;
	float	res;

	i = 0;
	j = 0;
	while (i < nb_lines)
	{
		while (j < nb_columns)
		{
			if (map->board[i][j] > 100)
			{
				res = 0.5;
				return (res);
			}
			j++;
		}
		j = 0;
		i++;
	}
	res = 6;
	return (res);
}

int		init_structure(t_env *env, char *file)
{
	if (!(env->map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	parsing(env->map, file);
	if (!(env->line = (t_line *)malloc(sizeof(t_line))))
		return (0);
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	env->img_data_ptr = mlx_get_data_addr(env->img_ptr, &(env->bpp),
	&(env->s_l), &(env->endian));
	env->is_iso = 0;
	env->starting_x = WIN_WIDTH / 4;
	env->starting_y = WIN_HEIGHT / 10;
	env->scale_x = (WIN_WIDTH / env->map->nb_columns) / 2;
	env->scale_y = (WIN_WIDTH / env->map->nb_lines) / 2;
	env->zoom = 1;
	env->altitude = check_altitude(env->map, env->map->nb_lines,
	env->map->nb_columns);
	env->palette = 0;
	env->file = file;
	return (1);
}

int		fdf(char *file)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	init_structure(env, file);
	draw_parallel_h1(env, env->map);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	print_menu(env, file);
	mlx_hook(env->win_ptr, 2, (1L << 0), deal_key, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
