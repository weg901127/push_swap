# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 12:53:59 by gilee             #+#    #+#              #
#    Updated: 2021/11/16 19:36:08 by gilee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  				= push_swap

CC 					= cc -g
CFLAGS 				= -Wall -Wextra -Werror

LIBFT_DIR 			= ./libft/
LIBFT_NAME			= libft.a
LIB					= $(LIBFT_DIR)$(LIBFT_NAME)

SRCS				= ./deque_base.c ./deque_calc.c \
					./deque_get.c	./push_swap.c \
					./push_swap_inst.c ./push_swap_multi.c \
					./push_swap_single.c ./push_swap_sort.c \
					./quicksort.c

OBJ					=	$(SRCS:.c=.o)

all : MAKE_LIB $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re : clean
	rm -f $(NAME)
	make -C . all

MAKE_LIB :
	make -C $(LIBFT_DIR) all

.PHONY : all clean fclean re
