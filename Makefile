# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esalorin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 15:18:35 by esalorin          #+#    #+#              #
#    Updated: 2019/12/12 12:44:54 by esalorin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = srcs/fillit.c srcs/validate.c srcs/solver.c srcs/create_map.c

OBJ = srcs/fillit.o srcs/validate.o srcs/solver.o srcs/create_map.o

.PHONY : all clean fclean re fillit

all : $(NAME)

$(NAME) :
	make -C libft/
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) libft/libft.a -I srcs

clean :
	rm -f $(OBJ)
	make clean -C libft/

fclean : clean
	rm -f $(NAME)
	make fclean -C libft/

re : fclean all
