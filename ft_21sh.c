/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_21sh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 12:48:04 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/29 18:48:23 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"
#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"

char	**ft_keep_searching(char **env, char **board)
{
	char	**tests;

	tests = NULL;
	if (ft_strequ("unsetenv", *board))
		env = ft_unset_env(board, env);
	else if (ft_strequ("setenv", *board) == 1)
		env = ft_set_env(board, env);
	else
	{
		tests = ft_tests_exec(tests, env, board);
		if (tests)
			ft_free_db_tab(tests);
	}
	return (env);
}

char	**ft_find_option(char *line, char **env, char **board)
{
	if (ft_strequ(line, "env"))
		print_db(env);
	else if (ft_strequ(board[0], "cd"))
		env = ft_cd(line, env, board);
	else if (ft_strequ(board[0], "echo") && ft_check_char(board) == 0)
		ft_echo(board);
	else
		env = ft_keep_searching(env, board);
	return (env);
}

void	ft_21sh(char **env)
{
	char	*line;
	char	**board;
	t_dlist *history;
	char	**tokens;

	tokens = NULL;
	history = NULL;
	board = NULL;
	line = NULL;
	tokens = ft_allocate_tokens();
	//signal(SIGINT, ); 
	while (1)
	{
		ft_putstr("$> ");
		line = which_khey(history);
		history = ft_lst_new(history, line);
		ft_putchar('\n');
		if (line)
		{
			env = ft_parseur(line, env, tokens);
			ft_strdel(&line);
		}
	}
	ft_free_db_tab(env);
}
