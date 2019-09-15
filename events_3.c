/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:34:17 by jmousset          #+#    #+#             */
/*   Updated: 2019/09/15 11:12:33 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		close_program(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	free_all(env);
	exit(EXIT_SUCCESS);
}

void	zoom_in(t_env *env)
{
	if (env->is_iso == 1)
	{
		env->starting_x = env->starting_x - 750;
		env->starting_y = env->starting_y + 50;
	}
	else
	{
		env->starting_x = env->starting_x - 500;
		env->starting_y = env->starting_y - 200;
	}
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	env->img_data_ptr = mlx_get_data_addr(env->img_ptr,
	&(env->bpp), &(env->s_l), &(env->endian));
	env->zoom += 1;
	if (env->is_iso == 1)
		draw_iso_h1(env, env->map);
	else
		draw_parallel_h1(env, env->map);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	print_menu(env, env->file);
}

int		zoom_out(t_env *env)
{
	if (env->zoom == 1)
		return (0);
	if (env->is_iso == 1)
	{
		env->starting_x = env->starting_x + 750;
		env->starting_y = env->starting_y - 50;
	}
	else
	{
		env->starting_x = env->starting_x + 500;
		env->starting_y = env->starting_y + 200;
	}
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	env->img_data_ptr = mlx_get_data_addr(env->img_ptr, &(env->bpp),
	&(env->s_l), &(env->endian));
	env->zoom -= 1;
	if (env->is_iso == 1)
		draw_iso_h1(env, env->map);
	else
		draw_parallel_h1(env, env->map);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	print_menu(env, env->file);
	return (0);
}

void	higher(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	env->img_data_ptr = mlx_get_data_addr(env->img_ptr, &(env->bpp),
	&(env->s_l), &(env->endian));
	env->altitude += 0.5;
	if (env->is_iso == 1)
		draw_iso_h1(env, env->map);
	else
		draw_parallel_h1(env, env->map);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	print_menu(env, env->file);
}

void	lower(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	env->img_data_ptr = mlx_get_data_addr(env->img_ptr, &(env->bpp),
	&(env->s_l), &(env->endian));
	env->altitude -= 0.5;
	if (env->is_iso == 1)
		draw_iso_h1(env, env->map);
	else
		draw_parallel_h1(env, env->map);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	print_menu(env, env->file);
}
