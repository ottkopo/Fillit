/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:27:03 by okoponen          #+#    #+#             */
/*   Updated: 2019/12/12 15:03:05 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_block_fit(t_blocks s, char **map, int x, int y)
{
	int c;
	int r;
	int i;

	c = 0;
	r = 0;
	i = 0;
	while (i <= 2)
	{
		c = (x + s.cols[i]);
		r = (y + s.rows[i]);
		if (c < 0 || r < 0 || !map[r] || !map[r][c])
			return (0);
		if (map[r][c] != '.')
			return (0);
		i++;
	}
	return (1);
}

static void	delete_block(t_blocks s, char **map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == s.letter)
				map[y][x] = '.';
			x++;
		}
		x = 0;
		y++;
	}
}

static int	insert_block(t_blocks s, char **map, int x, int y)
{
	while (1)
	{
		if (!map[y] || !map[y][x])
			return (0);
		if (map[y][x] == '.' && check_block_fit(s, map, x, y))
		{
			if (put_block(s, map, x, y))
				break ;
		}
		else
		{
			if (map[y][x + 1])
				x++;
			else if (map[y + 1])
			{
				x = 0;
				y++;
			}
			else
				return (0);
		}
	}
	return (1);
}

static int	move_block(t_blocks s, char **map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map[y] && map[y][x] != s.letter)
	{
		while (map[y][x] && map[y][x] != s.letter)
			x++;
		if (map[y][x] && map[y][x] == s.letter)
			break ;
		x = 0;
		y++;
	}
	delete_block(s, map);
	if (map[y] && map[y][x + 1])
		x++;
	else if (map[y] && map[y + 1])
	{
		x = 0;
		y++;
	}
	else
		return (0);
	return (insert_block(s, map, x, y));
}

void		solver(t_blocks *s, char **map, int count, int size)
{
	int i;

	i = 0;
	while (i < count)
	{
		if (!insert_block(s[i], map, 0, 0))
		{
			if (i != 0)
				i--;
			while (i > 0)
			{
				if (move_block(s[i], map))
					break ;
				i--;
			}
			if (i == 0)
				if (!move_block(s[0], map))
				{
					delete_map(map);
					return (create_map(s, count, ++size));
				}
		}
		i++;
	}
	print_solution(map);
}
