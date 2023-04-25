
NAME		= cub3d

CC			= cc

RM 			= rm -rf

FLAGS		= -g -ggdb3 -Wall -Wextra -Werror #-fsanitize=address 

LINKER		= -lft -L./Libft -lmlx -framework OpenGl -framework AppKit

MKDIR		= mkdir -p

OBJS_DIR	= objects

SRCS 		= $(wildcard *.c)

_OBJS 		= $(patsubst %.c, %.o, $(SRCS))

OBJS 		= $(patsubst %.o, $(OBJS_DIR)/%.o, $(_OBJS))

$(OBJS_DIR)/%.o: %.c
	@ $(MKDIR) $(OBJS_DIR)/parsing
	@$(CC) $(FLAGS) -c $< -o $@

all: lib $(NAME)

lib:
	@cd Libft && make

$(NAME): $(OBJS)
	@echo	"$(YELLOW)🌪️ $(NAME) Compiling...!$(DEFAULT)"
	@$(CC) $(FLAGS) $(OBJS) $(LINKER) -o $(NAME)
	@echo	"$(GREEN)✅$(NAME) created!$(DEFAULT)"


clean:
	@ $(RM) $(OBJS_DIR) Libft/*.o
	@ echo	"$(YELLOW)🧨Object files deleted!$(DEFAULT)"

fclean: clean
	@ $(RM) $(NAME) Libft/libft.a
	@echo	"$(RED)💣All deleted!$(DEFAULT)"

re: fclean all

norm:
	clear
	norminette $(SRCS) cub3d.h

wc:
	clear
	wc -l $(SRCS)

.PHONY: all clean fclean re readline norm wc lib


RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m