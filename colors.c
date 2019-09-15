/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:17:08 by jmousset          #+#    #+#             */
/*   Updated: 2019/09/15 11:11:10 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	choose_color_1(t_env *env, int x, int y, int z)
{
	int		color;

	if (z <= 0)
		color = 0x7D5C3500;
	else if (z > 0 && z <= 10)
		color = 0x7B5B6C00;
	else if (z > 10 && z <= 25)
		color = 0x846CC000;
	else if (z > 25 && z <= 100)
		color = 0x8072F600;
	else
		color = 0x95B1F800;
	fill_pixel(env, x, y, color);
}

void	choose_color_2(t_env *env, int x, int y, int z)
{
	int		color;

	if (z <= 0)
		color = 0xFDBE9500;
	else if (z > 0 && z <= 10)
		color = 0xA3E1B400;
	else if (z > 10 && z <= 25)
		color = 0xA3D2E100;
	else if (z > 25 && z <= 100)
		color = 0x7998A200;
	else
		color = 0xF1F6F700;
	fill_pixel(env, x, y, color);
}

void	color_palette_1(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	env->img_data_ptr = mlx_get_data_addr(env->img_ptr, &(env->bpp),
	&(env->s_l), &(env->endian));
	env->palette = 0;
	if (env->is_iso == 0)
		draw_parallel_h1(env, env->map);
	else
		draw_iso_h1(env, env->map);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	print_menu(env, env->file);
}

void	color_palette_2(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	env->img_data_ptr = mlx_get_data_addr(env->img_ptr, &(env->bpp),
	&(env->s_l), &(env->endian));
	env->palette = 1;
	if (env->is_iso == 0)
		draw_parallel_h1(env, env->map);
	else
		draw_iso_h1(env, env->map);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	print_menu(env, env->file);
}
