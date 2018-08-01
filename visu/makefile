# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vburidar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/06 17:41:06 by vburidar          #+#    #+#              #
#    Updated: 2018/04/06 18:05:32 by vburidar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main.c\
	  ft_get_data.c\
	  ft_is.c\
	  ft_is_2.c\
	  ft_next.c\
	  ft_get.c\
	  ft_print_data.c\
	  ft_get_path.c\
	  ft_fill_path.c\
	  ft_add_line.c\
	  ft_free.c\
	  ft_dellastline.c\
	  ft_get_nxt_room.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) lem_in.h
	make -C LIBFT
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) -L. LIBFT/libft.a

$(FT_PRINTF):
	make all -C LIBFT

%.o : %.c
	gcc -o $@ -c $< -g -Wall -Wextra -Werror

clean :
	rm -rf $(OBJ)
	make clean -C LIBFT

fclean : clean 
	rm -rf $(NAME)
	make fclean -C LIBFT

re :	
	make fclean
	make
