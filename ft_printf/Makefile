# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jting <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 11:47:34 by jting             #+#    #+#              #
#    Updated: 2022/04/01 13:39:25 by jting            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = ./libft/libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iheaders -I . -c
RM = rm -f 

SRCS = srcs/ft_hex.c srcs/ft_putptr.c srcs/ft_putstr.c srcs/ft_printf.c srcs/ft_unsign.c

OBJS = $(SRCS:.c=.o)

OBJ_DEST = mv *.o srcs

all: $(NAME)

$(NAME):
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(CFLAGS) $(SRCS)
	$(OBJ_DEST)
	ar rcs $(NAME) $(OBJS)

bonus: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re
