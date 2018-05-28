/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 12:49:53 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/23 18:29:16 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_21sh.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int			ft_access_exec(char *test, char *board)
{
	char			*name;

	name = ft_sous_d(test, board);
	if (access(name, X_OK) == -1)
	{
		ft_strdel(&name);
		ft_error("21sh: exetable has permission denied ", board);
		return (-1);
	}
	ft_strdel(&name);
	return (0);
}

void	ft_echo(char **board)
{
	int i;

	i = 1;
	while (board[i])
	{
		ft_putstr(board[i]);
		if (board[i + 1])
			ft_putchar(' ');
		else if (!board[i + 1])
			ft_putchar('\n');
		i++;
	}
}

int		ft_error(char *s1, char *name)
{
	if (!s1)
		return (-1);
	ft_putstr_fd(s1, 2);
	if (name)
		ft_putstr_fd(name, 2);
	ft_putchar_fd('\n', 2);
	return (-1);
}

char	*ft_acces(char *s)
{
	struct stat		buf;

	lstat(s, &buf);
	if (access(s, F_OK) == -1)
		return ("cd: no such file or directory: ");
	else if (access(s, X_OK) == -1)
	{
		lstat(s, &buf);
		if (S_ISDIR(buf.st_mode) != 1)
			return ("cd: not a directory: ");
		return ("cd: permission denied: ");
	}
	if (S_ISDIR(buf.st_mode) != 1)
		return ("cd: not a directory: ");
	return (NULL);
}
