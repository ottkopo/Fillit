/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:34:07 by esalorin          #+#    #+#             */
/*   Updated: 2019/12/12 15:47:45 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_matches(char **array, int x, int y, char c)
{
	int	match;

	match = 0;
	if (array[y][x + 1] == c)
		match++;
	if (array[y][x - 1] == c)
		match++;
	if (y != 0 && array[y - 1][x] == c)
		match++;
	if (array[y + 1] && array[y + 1][x] == c)
		match++;
	return (match);
}

static int	check_tetramino(char *block, char c)
{
	char	**array;
	int		x;
	int		y;
	int		match;

	y = 0;
	match = 0;
	array = ft_strsplit(block, '\n');
	while (array[y])
	{
		x = 0;
		while (array[y][x])
		{
			if (array[y][x] == c)
				match = match + check_matches(array, x, y, c);
			x++;
		}
		y++;
	}
	delete_map(array);
	if (match != 6 && match != 8)
		return (-1);
	return (1);
}

int			validate(char *block, char c, int last)
{
	int		i;
	int		hash;
	int		line;

	i = 0;
	hash = 0;
	line = 0;
	while (block[i] && (block[i] == '.' || block[i] == '#' || block[i] == '\n'))
	{
		if (block[i] == '#')
		{
			block[i] = c;
			hash++;
		}
		if (block[i] == '\n' && (i == 4 || i == 9 || i == 14 ||\
								i == 19 || i == 20))
			line++;
		i++;
	}
	if (last && (i != 20 || line != 4 || hash != 4))
		return (-1);
	if (!last && (i != 21 || hash != 4 || line != 5))
		return (-1);
	return (check_tetramino(block, c));
}
