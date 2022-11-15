/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:14:40 by esalorin          #+#    #+#             */
/*   Updated: 2019/12/12 16:05:25 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>

# define BUFF_SIZE 21

typedef struct		s_blocks
{
	int				cols[3];
	int				rows[3];
	char			letter;
}					t_blocks;

int					validate(char *block, char c, int ret);
int					put_block(t_blocks s, char **map, int x, int y);
void				solver(t_blocks *s, char **map, int count, int size);
void				create_map(t_blocks *s, int count, int size);
void				print_solution(char **map);
void				delete_map(char **map);
void				error(void);

#endif
