/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimarkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 19:28:41 by vimarkov          #+#    #+#             */
/*   Updated: 2018/05/29 18:32:01 by viclucas         ###   ########.fr       */
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
//Fonction aui check tout les caracteres speciauc (< > << >> ; |)

char	**ft_flag(char **board)
{
	int i;
	int j;
	int n;
	char **ret;

	j = 0;
	i = 0;
	n = 0;
	while(board[i])
	{
		if (ft_strcmp(board[i], ">") == 0)
			n++;
		else if (ft_strcmp(board[i], ">>") == 0)
			n++;
		else if (ft_strcmp(board[i], "<<") == 0)
			n++;
		else if (ft_strcmp(board[i], "<") == 0)
			n++;
		else if (ft_strcmp(board[i], "|") == 0)
			n++;
		else if (ft_strcmp(board[i], "2>") == 0)
			n++;
		else if (ft_strcmp(board[i], "2>&1") == 0)
			n++;
		else if (ft_strcmp(board[i], "2>>") == 0)
			n++;
		i++;
	}
	if(!(ret = (char**)malloc(sizeof(char*) * n + 1)))
		return NULL;
	i = 0;
	while(board[i])
	{
		if (ft_strequ(board[i], ">") == 1)
			ret[j++] = ft_strdup(">");
		else if (ft_strequ(board[i], ">>") == 1)
			ret[j++] = ft_strdup(">>");
		else if (ft_strequ(board[i], "<") == 1)
			ret[j++] = ft_strdup("<");
		else if (ft_strequ(board[i], "<<") == 1)
			ret[j++] = ft_strdup("<<");
		else if (ft_strequ(board[i], "|") == 1)
			ret[j++] = ft_strdup("|");
		else if (ft_strequ(board[i], "2>") == 1)
			ret[j++] = ft_strdup("2>");
		else if (ft_strequ(board[i], "2>&1") == 1)
			ret[j++] = ft_strdup("2>&1");
		else if (ft_strequ(board[i], "2>>") == 1)
			ret[j++] = ft_strdup("2>>");
		i++;
	}
	ret[j] = 0;
	return(ret);
}

int		ft_check_dup(char **board)
{
	int i;

	i = 0;
	while(board[i])
	{
		if(ft_strequ(board[i], ">") == 1)
			return (1);
		else if (ft_strequ(board[i], "2>") == 1)
			return (1);
		else if (ft_strequ(board[i], "2>&1") == 1)
			return (1);
		else if(ft_strequ(board[i], ">>") == 1)
			return (1);
		else if(ft_strequ(board[i], "2>>") == 1)
			return (1);
		else if(ft_strequ(board[i], "<") == 1)
			return (0);
		else if(ft_strequ(board[i], "<<") == 1)
			return (0);
		i++;
	}
	return (0);
}

char	**ft_cut_tab(char **board, char **flag)
{
	int i;
	int j;
	char **ret;

	i = 0;
	j = 0;
	while(board[i])
	{
		while(flag[j])
		{
			if(ft_strequ(board[i], flag[j]) == 1)
				break ;
			j++;
		}
		j = 0;
		i++;
	}
	if(!(ret = (char**)malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	i = 0;
	j = 0;
	while(board[i])
	{
		ret[i] = ft_strdup(board[i]);
		while(flag[j])
		{
			if(ft_strcmp(board[i + 1], flag[j]) == 0)
			{
				ret[i + 1] = 0;
				return (ret);
			}
			j++;
		}
		j = 0;
		i++;
	}
	ret[i] = 0;
	return(ret);
}

int		ft_output2(char **flag)
{
	int i;

	i = 0;
	while(flag[i])
	{
		if(ft_strequ(flag[i], "<<") == 1)
			return (1);
		i++;
	}
	return (0);
}

int		ft_output3(char **flag)
{
	int i;

	i = 0;
	while(flag[i])
	{
		if(ft_strequ(flag[i], "2>") == 1)
			return (1);
		i++;
	}
	return (0);
}


int		ft_output(char **flag)
{
	int i;

	i = 0;
	while(flag[i])
	{
		if(ft_strequ(flag[i], "2>") == 1)
			return(1);
		if(ft_strequ(flag[i], "2>>") == 1)
			return(3);
		if(ft_strequ(flag[i], "2>&1") == 1)
			return(2);
		if(ft_strequ(flag[i], "|") == 1)
			return(4);
		i++;
	}
	return(0);
}

int		ft_redirection(char *name, char **board, char **env)
{
	char		*opn_dir;
	char		*opn_err;
	int i;
	//empecher l'affichage
	i = 0;
	opn_dir = NULL;
	opn_err = NULL;
	
	if (ft_run_exec(board, env) == 0)
		return (0);
	if(ft_check_dup(board) == 1)
		ft_first_redir(board, name, opn_err, opn_dir);
	if(ft_check_dup(board) == 0)
		ft_sec_redir(board, name, opn_dir);
	return (0);
}
