/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 11:57:38 by jmousset          #+#    #+#             */
/*   Updated: 2019/09/15 11:01:58 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_int_max(char *s)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] && ft_isdigit(s[i]))
		{
			res++;
			i++;
		}
		if (res >= 9)
			return (0);
		else
			res = 0;
		i++;
	}
	return (1);
}

void	fill_pixel(t_env *env, int x, int y, int color)
{
	int		i;

	i = (((WIN_HEIGHT - (WIN_HEIGHT - y)) * WIN_WIDTH) - (WIN_WIDTH - x)) * 4;
	if (x < WIN_WIDTH && x > 0 && y < WIN_HEIGHT && y > 0)
	{
		env->img_data_ptr[i + 0] = (color & 0xFF000000) >> 24;
		env->img_data_ptr[i + 1] = (color & 0x00FF0000) >> 16;
		env->img_data_ptr[i + 2] = (color & 0x0000FF00) >> 8;
		env->img_data_ptr[i + 3] = (color & 0x000000FF) >> 0;
	}
}

void	vertical_line(t_env *env, t_line *line, int z)
{
	int		i;
	int		cumul;

	i = 1;
	cumul = line->dy / 2;
	while (i <= line->dy)
	{
		line->y = line->y + line->yinc;
		cumul = cumul + line->dx;
		if (cumul >= line->dy)
		{
			cumul = cumul - line->dy;
			line->x = line->x + line->xinc;
		}
		if (env->palette == 0)
			choose_color_1(env, line->x, line->y, z);
		else
			choose_color_2(env, line->x, line->y, z);
		i++;
	}
}

void	horizontal_line(t_env *env, t_line *line, int z)
{
	int		i;
	int		cumul;

	i = 1;
	cumul = line->dx / 2;
	while (i <= line->dx)
	{
		line->x = line->x + line->xinc;
		cumul = cumul + line->dy;
		if (cumul >= line->dx)
		{
			cumul = cumul - line->dx;
			line->y = line->y + line->yinc;
		}
		if (env->palette == 0)
			choose_color_1(env, line->x, line->y, z);
		else
			choose_color_2(env, line->x, line->y, z);
		i++;
	}
}

void	draw_line(t_env *env, t_line *line, int z)
{
	line->x = line->x1;
	line->y = line->y1;
	line->dx = line->x2 - line->x1;
	line->dy = line->y2 - line->y1;
	line->xinc = (line->dx > 0) ? 1 : -1;
	line->yinc = (line->dy > 0) ? 1 : -1;
	line->dx = abs(line->dx);
	line->dy = abs(line->dy);
	if (line->dx > line->dy)
		horizontal_line(env, line, z);
	else
		vertical_line(env, line, z);
}
