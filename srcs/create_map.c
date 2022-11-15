/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 10:16:51 by okoponen          #+#    #+#             */
/*   Updated: 2019/12/12 16:05:39 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	delete_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int		put_block(t_blocks s, char **map, int x, int y)
{
	int i;

	i = 0;
	map[y][x] = s.letter;
	while (i <= 2)
	{
		map[y + s.rows[i]][x + s.cols[i]] = s.letter;
		i++;
	}
	return (1);
}

void	create_map(t_blocks *s, int count, int size)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = (char **)malloc(sizeof(char *) * (size + 1));
	if (count * 4 > size * size)
	{
		free(map);
		return (create_map(s, count, ++size));
	}
	while (i < size)
	{
		map[i] = (char *)malloc(sizeof(char) * (size + 1));
		while (j < size)
			map[i][j++] = '.';
		map[i++][j] = '\0';
		j = 0;
	}
	map[i] = NULL;
	solver(s, map, count, size);
}

void	print_solution(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
	delete_map(map);
}

void	error(void)
{
	write(1, "error\n", 6);
	exit(1);
}
