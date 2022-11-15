/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:57:54 by okoponen          #+#    #+#             */
/*   Updated: 2019/12/12 16:07:34 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int		helper(int i, int x)
{
	if (i > 4)
		x = i % 5;
	else
		x = i;
	return (x);
}

static t_blocks	add_block(char *str, int i, int y)
{
	t_blocks	new;
	int			x;
	int			a;

	a = 0;
	x = -1;
	y = 0;
	while (str[i])
	{
		(str[i] == '\n') ? y++ : y;
		if (str[i] != '.' && str[i] != '\n')
		{
			if (x == -1)
				x = helper(i, x);
			else
			{
				(i > 4) ? (new.cols[a] = (i % 5) - x) : x;
				(i <= 4) ? (new.cols[a] = i - x) : x;
				new.rows[a++] = y;
			}
		}
		i++;
	}
	return (new);
}

static void		create_structs(char **blocks, int i)
{
	int			y;
	int			x;
	char		c;
	t_blocks	array[i];

	y = 0;
	i = 0;
	c = 'A';
	while (blocks[y])
	{
		x = 0;
		while (blocks[y][x] != c)
			x++;
		array[i] = add_block(blocks[y], x, y);
		array[i++].letter = c++;
		free(blocks[y++]);
	}
	create_map(array, i, 2);
}

static int		validate_blocks(char **blocks)
{
	int		i;
	int		last;
	char	c;

	i = 0;
	last = 0;
	c = 'A';
	while (blocks[i])
	{
		(blocks[i + 1] == NULL) ? (last = 1) : last;
		if (c > 'Z')
			return (-1);
		if (validate(blocks[i], c, last) < 0)
			return (-1);
		c++;
		i++;
	}
	create_structs(blocks, i);
	return (1);
}

int				main(int ac, char **av)
{
	char	*blocks[26];
	char	buf[BUFF_SIZE + 1];
	int		fd;
	int		i;
	int		ret;

	if (ac != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		return (0);
	}
	i = 0;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		error();
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		blocks[i++] = ft_strdup(buf);
	}
	close(fd);
	blocks[i] = NULL;
	if (i == 0 || ret == -1 || (validate_blocks(blocks) == -1))
		error();
	return (0);
}
