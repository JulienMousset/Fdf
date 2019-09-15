/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 12:08:34 by jmousset          #+#    #+#             */
/*   Updated: 2019/09/15 11:33:37 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_all(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->map->nb_lines)
	{
		ft_memdel((void **)&(env->map->board[i]));
		i++;
	}
	ft_memdel((void **)&(env->map->board));
	ft_memdel((void **)&(env->map));
	ft_memdel((void **)&(env->line));
	ft_memdel((void **)&(env));
}

void	free_tmp_board(char **s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_memdel((void **)&(s[i]));
		i++;
	}
	ft_memdel((void **)&(s));
}

void	no_data_found(void)
{
	ft_putstr("No data found.\n");
	exit(EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		fdf(av[1]);
	else
	{
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
