# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 19:01:44 by vagevorg          #+#    #+#              #
#    Updated: 2022/08/10 18:06:42 by vagevorg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	philo

CC		=	CC

CFLAGS	=	-Wall -Wextra -Werror

RM		=	-rm -f

SOURCE	=	$(wildcard *.c)

OBJECT	=	$(SOURCE:.c=.o)

MAK		=	make -s

%.o:%.c
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJECT)
			$(CC) $(OBJECT) -o $(NAME)

clean:
			$(RM) $(OBJECT)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

