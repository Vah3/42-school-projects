# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 20:40:44 by vagevorg          #+#    #+#              #
#    Updated: 2022/06/24 19:58:13 by vagevorg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

SRCS		= $(wildcard *.c )

OBJS 		= $(SRCS:.c=.o)

PRINT		= -C Printf/

CLE			= make clean

FCLE		= make fclean

INCLUDES	= -I./ -I ./Printf

LINKERS		= -lftprintf -L./Printf

%.o:%.c
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all:		$(NAME)
	
$(NAME):	$(OBJS)
			$(MAKE) $(PRINT)
			$(CC) $(CFLAGS) $(LINKERS) $(INCLUDES) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)
			$(CLE) $(PRINT)

fclean:		clean
			$(RM) $(NAME)
			$(FCLE) $(PRINT)

re:			fclean all

.PHONY: 	all clean fclean re

