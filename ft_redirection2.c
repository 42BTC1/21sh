/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimarkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:27:28 by vimarkov          #+#    #+#             */
/*   Updated: 2018/05/28 16:37:52 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include "ft_21sh.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

int			ft_first_redir(char **board, char *name, char *opn_err, char *opn_dir)
{
	pid_t pid;
	int fd;
	int old_fd;
	char **flag;
	char **cut;
	int i;
	fd = 0;

	old_fd = 1;
	i = 0;
	pid = 0;
	pid = fork();
	flag = ft_flag(board);
	cut = ft_cut_tab(board, flag);
	if (pid == 0)
	{
		while(board[i])
		{
			if (ft_strequ(board[i], ">") == 1)
			{
				opn_dir = ft_strdup(board[i + 1]);
				fd = open(opn_dir, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
				dup2(fd, 1);
			}
			if (ft_strequ(board[i], ">>") == 1)
			{
				opn_dir = ft_strdup(board[i + 1]);
				fd = open(opn_dir, O_CREAT | O_APPEND | O_WRONLY, 0666);
				dup2(fd, old_fd);
				ft_putnbr(i);
			}
			if (ft_strequ(board[i], "2>") == 1)
			{
				opn_err = ft_strdup(board[i + 1]);
				fd = open(opn_err, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
				dup2(fd, 2);
			}
			if (ft_strequ(board[i], "2>>") == 1)
			{
				opn_err = ft_strdup(board[i + 1]);
				fd = open(opn_err, O_CREAT | O_APPEND | O_WRONLY, 0666);
				dup2(fd, 2);
			}
			if (ft_strequ(board[i], "2>&1") == 1)
				dup2(fd, 2);
			i++;
		}
		if (ft_strequ(board[i], "|") == 1)
		{
			//ft_run_exec();
			exit(1);
		}
		else
		{
			if (execve(name, cut, NULL) == -1)
				return (-1);
			return (0);
		}
	}
	wait(&pid);
	return (0);
}

int			ft_sec_redir(char **board, char *name, char *opn_dir)
{
	char **cut;
	char **put;
	char **flag;
	int fd;
	t_dlist *history;
	char *line;
	pid_t pid;
	
	pid = 0;
	history = NULL;
	put = NULL;
	flag = NULL;
	
	flag = ft_flag(board);
	cut = ft_cut_tab(board, flag);
	fd = ft_open(board, flag, &opn_dir, NULL);
	if (ft_output2(flag) == 0)
		pid = fork();
	if (ft_output2(flag) == 1)
	{
		while (1)
		{
			ft_putstr("> ");
			line = which_khey(history);
			ft_putchar('\n');
			if(ft_strequ(line, opn_dir) == 0)
				put = ft_realloc_for_re(put, line);
			if(ft_strequ(line, opn_dir) == 1)
				break;
			if (line)
				ft_strdel(&line);
		}
		int pp[2];
		pipe(pp);
		if(put)
		{
			while(*put)
			{
				write(pp[1], *put, ft_strlen(*put));
				write(pp[1], "\n", 1);
				put++;
			}
			pid = fork();
			if (pid == 0)
			{
				close(pp[1]);
				dup2(pp[0], 0);
				if (ft_output(flag) == 4)
				{
					//ft_run_exec();
					exit(1);
				}
				if (execve(name, cut, NULL) == -1)
					return (-1);
				return (0);
			}
			close(pp[0]);
			close(pp[1]);
			wait(NULL);
		}
	}
	else if (pid == 0)
	{
		dup2(fd, 0);
		if (ft_output(flag) == 4)
		{
			//ft_run_exec();
			exit(1);
		}
		else
			if (execve(name, cut, NULL) == -1)
				return (-1);
		return(0);
	}
	wait(&pid);
	return (0);
}
