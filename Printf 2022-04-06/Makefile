# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 20:25:58 by vagevorg          #+#    #+#              #
#    Updated: 2022/04/08 21:51:29 by vagevorg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC		=	CC

CFLAGS	=	-Wall -Wextra -Werror

RM		=	-rm -f

SOURCE	=	$(wildcard *.c)

OBJECT	=	$(SOURCE:.c=.o)

%.o:%.c
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJECT)
			ar rcs $(NAME) $(OBJECT)

clean:
			$(RM) $(OBJECT)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
