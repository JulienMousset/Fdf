/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:40:29 by jmousset          #+#    #+#             */
/*   Updated: 2019/09/15 11:11:41 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_parallel(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	env->img_data_ptr = mlx_get_data_addr(env->img_ptr, &(env->bpp),
	&(env->s_l), &(env->endian));
	env->scale_x = (WIN_WIDTH / env->map->nb_columns) / 2;
	env->scale_y = (WIN_WIDTH / env->map->nb_lines) / 2;
	env->starting_x = WIN_WIDTH / 4;
	env->starting_y = WIN_HEIGHT / 10;
	env->altitude = check_altitude(env->map, env->map->nb_lines,
	env->map->nb_columns);
	env->zoom = 1;
	draw_parallel_h1(env, env->map);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	print_menu(env, env->file);
}

void	reset_iso(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	env->img_data_ptr = mlx_get_data_addr(env->img_ptr, &(env->bpp),
	&(env->s_l), &(env->endian));
	env->scale_x = (WIN_WIDTH / env->map->nb_columns) / 4;
	env->scale_y = (WIN_WIDTH / env->map->nb_lines) / 4;
	env->starting_x = WIN_WIDTH / 10;
	env->starting_y = WIN_HEIGHT / 2;
	env->altitude = check_altitude(env->map, env->map->nb_lines,
	env->map->nb_columns);
	env->zoom = 1;
	draw_iso_h1(env, env->map);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	print_menu(env, env->file);
}

void	change_to_iso(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	env->img_data_ptr = mlx_get_data_addr(env->img_ptr,
	&(env->bpp), &(env->s_l), &(env->endian));
	env->scale_x = (WIN_WIDTH / env->map->nb_columns) / 4;
	env->scale_y = (WIN_WIDTH / env->map->nb_lines) / 4;
	env->starting_x = WIN_WIDTH / 10;
	env->starting_y = WIN_HEIGHT / 2;
	draw_iso_h1(env, env->map);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	print_menu(env, env->file);
	env->is_iso = 1;
}

void	change_to_parallel(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	env->img_data_ptr = mlx_get_data_addr(env->img_ptr, &(env->bpp),
	&(env->s_l), &(env->endian));
	env->scale_x = (WIN_WIDTH / env->map->nb_columns) / 2;
	env->scale_y = (WIN_WIDTH / env->map->nb_lines) / 2;
	env->starting_x = WIN_WIDTH / 4;
	env->starting_y = WIN_HEIGHT / 10;
	draw_parallel_h1(env, env->map);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	print_menu(env, env->file);
	env->is_iso = 0;
}

int		deal_key(int key, t_env *env)
{
	if (key == ESC)
		close_program(env);
	if (key == R)
	{
		if (env->is_iso == 0)
			reset_parallel(env);
		else
			reset_iso(env);
	}
	if (key == E)
	{
		if (env->is_iso == 0)
			change_to_iso(env);
		else
			change_to_parallel(env);
	}
	if (key == Q)
	{
		if (env->palette == 0)
			color_palette_2(env);
		else
			color_palette_1(env);
	}
	deal_key_2(key, env);
	return (0);
}
