/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:30:35 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/29 18:53:22 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_21sh.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		ft_check_it(char **board)
{
	if (access(*board, F_OK) == -1)
	{
		ft_error("21sh: command not found: ", *board);
		return (-1);
	}
	if (access(*board, X_OK) == -1)
	{
		ft_error("21sh: permission denied: ", *board);
		return (-1);
	}
	return (0);
}

int		ft_execution(char *name, char **env, char **board)
{
	pid_t		pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(name, board, env) == -1)
			return (-1);
		return (0);
	}
	else
		wait(&pid);
	return (0);
}

char	**ft_tests_exec(char **tests, char **env, char **board)
{
	char		*ret;
	char		*name;

	if (ft_check_str(*board, '/') == 1)
	{
		if (ft_check_it(board) == -1)
			return (NULL);
		ft_execution(*board, env, board);
		return (NULL);
	}
	tests = ft_allocate(env);
	if ((ret = ft_allocate_parsing(tests, board)) == NULL)
		return (tests);
	name = ft_sous_d(ret, *board);
	if (ft_check_char(board) == 1)
		ft_redirection(name, board, env);
	else if (ft_check_char(board) == 0)
	if (ft_execution(name, env, board) == -1)
	{
		ft_strdel(&name);
	//	ft_error("something bad happened during the execution of ", *board);
		return (tests);
	}
	ft_strdel(&name);
	return (tests);
}
