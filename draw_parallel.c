/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_parallel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:45:07 by jmousset          #+#    #+#             */
/*   Updated: 2019/09/15 10:16:14 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_parallel_h1(t_env *env, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map->nb_lines)
	{
		env->line->x1 = env->starting_x;
		env->line->x2 = env->starting_x + (env->scale_x * env->zoom);
		if (map->board[i][j] != 0)
			env->line->y1 = (env->starting_y + (i * env->scale_y * env->zoom))
			- env->altitude * (map->board[i][j] + 1);
		else
			env->line->y1 = env->starting_y + (i * env->scale_y * env->zoom);
		if (map->board[i][j + 1] != 0)
			env->line->y2 = (env->starting_y + (i * env->scale_y * env->zoom))
			- env->altitude * (map->board[i][j + 1] + 1);
		else
			env->line->y2 = env->starting_y + (i * env->scale_y * env->zoom);
		draw_parallel_h2(env, map, i, j);
		j = 0;
		i++;
	}
	draw_parallel_v1(env, env->map);
}

void	draw_parallel_h2(t_env *env, t_map *map, int i, int j)
{
	while (j < map->nb_columns - 1)
	{
		draw_line(env, env->line, map->board[i][j]);
		env->line->x1 = env->line->x1 + (env->scale_x * env->zoom);
		env->line->x2 = env->line->x2 + (env->scale_x * env->zoom);
		j++;
		if (j < map->nb_columns - 1)
		{
			if (map->board[i][j] != 0)
				env->line->y1 = (env->starting_y + (i * env->scale_y
				* env->zoom)) - env->altitude * (map->board[i][j] + 1);
			else
				env->line->y1 = env->starting_y + (i * env->scale_y
				* env->zoom);
			if (map->board[i][j + 1] != 0)
				env->line->y2 = (env->starting_y + (i * env->scale_y
				* env->zoom)) - env->altitude * (map->board[i][j + 1] + 1);
			else
				env->line->y2 = env->starting_y + (i * env->scale_y
				* env->zoom);
		}
	}
}

void	draw_parallel_v1(t_env *env, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map->nb_columns)
	{
		env->line->x1 = env->starting_x + (i * env->scale_x * env->zoom);
		env->line->x2 = env->starting_x + (i * env->scale_x * env->zoom);
		if (map->board[j][i] != 0)
			env->line->y1 = env->starting_y - env->altitude
			* (map->board[j][i] + 1);
		else
			env->line->y1 = env->starting_y;
		if (map->board[j + 1][i] != 0)
			env->line->y2 = env->starting_y + env->scale_y * env->zoom
			- env->altitude * (map->board[j + 1][i] + 1);
		else
			env->line->y2 = env->starting_y + (env->scale_y * env->zoom);
		draw_parallel_v2(env, map, i, j);
		j = 0;
		i++;
	}
}

void	draw_parallel_v2(t_env *env, t_map *map, int i, int j)
{
	while (j < map->nb_lines - 1)
	{
		draw_line(env, env->line, map->board[j][i]);
		j++;
		if (j < map->nb_lines - 1)
		{
			if (map->board[j][i] != 0)
				env->line->y1 = (env->starting_y + (j * env->scale_y
				* env->zoom)) - env->altitude * (map->board[j][i] + 1);
			else
				env->line->y1 = env->starting_y + (j * env->scale_y
				* env->zoom);
			if (map->board[j + 1][i])
				env->line->y2 = (env->starting_y + env->scale_y * env->zoom
				+ (j * env->scale_y * env->zoom)) - env->altitude
				* (map->board[j + 1][i] + 1);
			else
				env->line->y2 = env->starting_y + env->scale_y * env->zoom
				+ (j * env->scale_y * env->zoom);
		}
	}
}
