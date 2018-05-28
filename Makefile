# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viclucas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/24 14:01:50 by viclucas          #+#    #+#              #
#    Updated: 2018/05/28 20:38:05 by viclucas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = 21sh

TERM_PATH = ./term/

SRC =	main.c   ft_access.c \
		ft_21sh.c \
		ft_execute_cmd.c \
	  	ft_environnement.c \
		ft_fcts_environnement.c \
		ft_allocate.c\
	 	ft_check_env.c \
		ft_cd.c \
		ft_open.c \
		ft_redirection.c \
		ft_redirection2.c \
		ft_parseur.c \
		ft_exec.c \
		ft_check_char.c \
		term/ft_term_gestion.c \
		term/ft_termcaps.c \
	 	term/ft_term_stockage.c \
		term/ft_term_history.c \
		term/ft_term_basic.c \
		term/ft_term_extend.c \
	  	term/ft_term_jump.c \
		term/ft_term_cpy.c \
		term/ft_term_tools.c \
		term/ft_term_signaux.c \
		parsing/ft_first_line_check.c \
		parsing/ft_pars_redirection.c \
		parsing/ft_allocate_tokens.c \
		parsing/ft_parsing.c \
		parsing/ft_put_the_blancks.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ) $(OBJ_T)
	@make -C libft/
	@gcc $(OBJ) -o $(NAME) -L libft/ -lft -lncurses -fsanitize=address 

all: $(NAME)

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) 
	@make -C libft/ fclean

re: fclean $(NAME)
