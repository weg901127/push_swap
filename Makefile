# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 21:03:11 by gilee             #+#    #+#              #
#    Updated: 2021/06/23 16:02:53 by gilee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  		= push_swap

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
INCLUDE 	= -I./libft/

LIB_DIR 	= ./libft/
LIB_NAME	= ft
LIB			= $(LIB_DIR)lib$(LIB_NAME).a

all : MAKE_LIB $(NAME)

clean :
	make -C $(LIB_DIR) clean

fclean : clean
	rm -rf $(NAME) $(NAME2) $(LIB)

re : fclean all

MAKE_LIB :
	make -C $(LIB_DIR) all

$(NAME) : $(NAME).c
	$(CC) $(CFLAGS) $< -o $@ $(INCLUDE) -L$(LIB_DIR) -l$(LIB_NAME)

.PHONY : all clean fclean re
