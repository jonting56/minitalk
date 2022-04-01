# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jting <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 15:42:55 by jting             #+#    #+#              #
#    Updated: 2022/04/01 13:40:03 by jting            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CFLAGS = -Wall -Wextra -Werror
PRINTF = ft_printf/
PRINTF_A = ft_printf/libftprintf.a
CC = gcc
RM = rm -f

all: 
	make -C $(PRINTF)
	make server
	make client

server:
	$(CC) $(CFLAGS) -g srcs/server.c $(PRINTF_A) -o server
client:
	$(CC) $(CFLAGS) -g srcs/client.c $(PRINTF_A) -o client

clean:
	make clean -C $(PRINTF) 

fclean: clean
	$(RM) server client $(PRINTF_A)

re: fclean all
