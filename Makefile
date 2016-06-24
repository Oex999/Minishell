# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oexall <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/20 08:38:50 by oexall            #+#    #+#              #
#    Updated: 2016/06/24 15:47:53 by oexall           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c execute.c error.c loop.c ft_split.c
BI_SRC = ./builtins/cd.c \
		 ./builtins/setenv.c \
		 ./builtins/unsetenv.c \
		 ./builtins/echo.c
U_SRC = ./utils/getenv.c \
		./utils/putenv.c \
		./utils/updateenv.c \
		./utils/duptab.c \
		./utils/deltab.c \
		./utils/ft_pathto.c
M_SRC = $(SRC) $(BI_SRC) $(U_SRC)

CC = gcc -g -o
CFLAGS = -Wall -Werror -Wall
LIBFT = -L ./libft/ -lft

all: $(NAME)

$(NAME):
	@clear
	@echo "Compiling libft..."
	@make -C libft fclean
	@make -C libft
	@echo "Compiled libft"
	@echo "Compiling $(NAME) Binary"
	@$(CC) $(NAME) $(CLFAGS) $(M_SRC) $(LIBFT)
	@echo "Compiled $(NAME)"

quick:
	@clear
	@echo "Compiling $(NAME) Binary"
	@$(CC) $(NAME) $(CLFAGS) $(M_SRC) $(LIBFT)
	@echo "Compiled $(NAME)"

clean:
	@echo "Cleaning"
	@make -C libft clean

fclean: clean
	@echo "Full clean"
	@make -C libft fclean
	@rm -rf $(NAME)

re: fclean all

me:
	@echo "Creating Author File"
	@rm -Rf author
	@echo ${LOGNAME} > author
	@echo "Done..."
	cat -e author

norm:
	@echo "Starting Norminette"
	norminette $(M_SRC) includes/minishell.h includes/errors.h
	@echo "End of Norm"
