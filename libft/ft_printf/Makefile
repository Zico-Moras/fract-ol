# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francima <francima@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 18:30:39 by francima          #+#    #+#              #
#    Updated: 2024/07/23 22:39:38 by francima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ./files

PRINTF_SRCS = ft_printf.c ft_put_func.c ft_hex.c ft_putpointer.c

OBJS = $(PRINTF_SRCS:.c=.o)

CC = cc
AR = ar rcs
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
CP = cp

all:	$(NAME)

$(NAME):	$(OBJS)
	@$(AR) $(NAME) $(OBJS)


%.o:	$(SRC)/%.c
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
