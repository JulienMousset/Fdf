/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 10:42:50 by jmousset          #+#    #+#             */
/*   Updated: 2019/09/22 16:43:47 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fill_board(t_map *map, int fd)
{
	int		read;
	int		i;
	int		j;
	int		k;

	i = 0;
	while ((read = get_next_line(fd, &map->line)))
	{
		map->tmp = ft_strsplit(map->line, ' ');
		j = 0;
		k = 0;
		if (!(map->board[i] = (int *)malloc(sizeof(int) * map->nb_columns)))
			return (0);
		while (map->tmp[j])
			map->board[i][j++] = ft_atoi(map->tmp[k++]);
		i++;
		free_tmp_board(map->tmp);
		ft_memdel((void **)&(map->line));
	}
	return (1);
}

int		count_columns(char *s)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (ft_isascii(s[i]) == 0)
			no_data_found();
		if (s[i])
			res++;
		while (s[i] != ' ' && s[i] != '\0')
			i++;
	}
	return (res);
}

int		count_lines(t_map *map, char *file)
{
	int		read;
	int		fd;
	int		i;
	int		previous;

	i = 0;
	map->nb_columns = 0;
	previous = 0;
	fd = open(file, O_RDONLY);
	while ((read = get_next_line(fd, &map->line)))
	{
		map->nb_columns = count_columns(map->line);
		previous = map->nb_columns;
		i++;
		ft_memdel((void **)&(map->line));
	}
	if (map->nb_columns <= 1)
		no_data_found();
	close(fd);
	return (i);
}

int		check_file(t_map *map, char *file)
{
	int		read;
	int		fd;

	if ((fd = open(file, O_DIRECTORY)) != -1)
		no_data_found();
	if ((fd = open(file, O_RDONLY)) == -1)
		no_data_found();
	fd = open(file, O_RDONLY);
	if (!(read = get_next_line(fd, &map->line)))
		return (0);
	ft_memdel((void **)&(map->line));
	close(fd);
	fd = open(file, O_RDONLY);
	while ((read = get_next_line(fd, &map->line)))
	{
		if (map->line[1] == '\n')
			return (0);
		if (!(check_int_max(map->line)))
			return (0);
		ft_memdel((void **)&(map->line));
	}
	close(fd);
	return (1);
}

int		parsing(t_map *map, char *file)
{
	int		fd;

	if (!(check_file(map, file)))
		no_data_found();
	map->nb_lines = count_lines(map, file);
	if (!(map->board = (int **)malloc(sizeof(int *) * map->nb_lines)))
		return (0);
	fd = open(file, O_RDONLY);
	fill_board(map, fd);
	close(fd);
	return (1);
}
