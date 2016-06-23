# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oexall <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/20 08:38:50 by oexall            #+#    #+#              #
#    Updated: 2016/06/23 16:28:42 by oexall           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c execute.c builtins_one.c error.c loop.c
BI_SRC = ./builtins/cd.c \
		 ./builtins/setenv.c \
		 ./builtins/unsetenv.c
U_SRC = ./utils/getenv.c \
		./utils/putenv.c \
		./utils/updateenv.c \
		./utils/duptab.c \
		./utils/deltab.c
M_SRC = $(SRC) $(BI_SRC) $(U_SRC)

CC = gcc -o
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
	norminette $(M_SRC) minishell.h
	@echo "End of Norm"
