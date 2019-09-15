/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:29:27 by jmousset          #+#    #+#             */
/*   Updated: 2019/09/15 11:12:03 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_up(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	env->img_data_ptr = mlx_get_data_addr(env->img_ptr, &(env->bpp),
	&(env->s_l), &(env->endian));
	env->starting_y -= 20;
	if (env->is_iso == 1)
		draw_iso_h1(env, env->map);
	else
		draw_parallel_h1(env, env->map);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	print_menu(env, env->file);
}

void	move_down(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	env->img_data_ptr = mlx_get_data_addr(env->img_ptr, &(env->bpp),
	&(env->s_l), &(env->endian));
	env->starting_y += 20;
	if (env->is_iso == 1)
		draw_iso_h1(env, env->map);
	else
		draw_parallel_h1(env, env->map);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	print_menu(env, env->file);
}

void	move_left(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	env->img_data_ptr = mlx_get_data_addr(env->img_ptr, &(env->bpp),
	&(env->s_l), &(env->endian));
	env->starting_x -= 20;
	if (env->is_iso == 1)
		draw_iso_h1(env, env->map);
	else
		draw_parallel_h1(env, env->map);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	print_menu(env, env->file);
}

void	move_right(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	env->img_data_ptr = mlx_get_data_addr(env->img_ptr, &(env->bpp),
	&(env->s_l), &(env->endian));
	env->starting_x += 20;
	if (env->is_iso == 1)
		draw_iso_h1(env, env->map);
	else
		draw_parallel_h1(env, env->map);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	print_menu(env, env->file);
}

int		deal_key_2(int key, t_env *env)
{
	if (key == UP)
		move_up(env);
	if (key == DOWN)
		move_down(env);
	if (key == LEFT)
		move_left(env);
	if (key == RIGHT)
		move_right(env);
	if (key == PLUS)
		zoom_in(env);
	if (key == MINUS)
		zoom_out(env);
	if (key == P)
		higher(env);
	if (key == O)
		lower(env);
	return (0);
}
