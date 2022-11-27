# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 18:25:51 by vagevorg          #+#    #+#              #
#    Updated: 2022/06/11 18:41:48 by vagevorg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	CC

CFLAGS	=	-Wall -Wextra -Werror

RM		=	-rm -f

SOURCE	=	$(wildcard *.c)

OBJECT	=	$(SOURCE:.c=.o)

%.o:%.c
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJECT)
			$(CC) -lmlx -framework OpenGL -framework AppKit $(OBJECT) -o $(NAME)

clean:
			$(RM) $(OBJECT)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

