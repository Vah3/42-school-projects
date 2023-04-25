# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edgghaza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 15:17:43 by vagevorg          #+#    #+#              #
#    Updated: 2023/01/10 13:56:36 by edgghaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

SRCS		= $(wildcard *.c) 

OBJS 		= $(SRCS:.c=.o)

%.o:%.c
			@$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar rcs $(NAME) $(OBJS)

clean:
			@$(RM) $(OBJS) 

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re
