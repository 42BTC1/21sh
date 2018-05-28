/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environnement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:37:28 by viclucas          #+#    #+#             */
/*   Updated: 2018/04/12 18:59:47 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_21sh.h"
#include <stdlib.h>

int			ft_verif(char *s, char *s2)
{
	int i;
	int o;

	o = 0;
	i = 0;
	while (s[i])
		i++;
	i--;
	if (s[i] == '=')
	{
		o = i + 1;
		if (s2[o] == '=')
			return (0);
		return (-1);
	}
	return (0);
}

char		**ft_unset_env(char **board, char **env)
{
	int		i;
	int		o;

	o = 0;
	i = 1;
	if (!board[1])
	{
		ft_error("usage: unsetenv [variable ...]", NULL);
		return (env);
	}
	while (board[i])
	{
		while (env[o])
		{
			if (ft_strnequ(board[i], env[o], ft_strlen(board[i])) == 1 &&
					ft_verif(board[1], env[o]) == 0)
				env = ft_realloc_for_unset(env, o);
			else
				o++;
		}
		o = 0;
		i++;
	}
	return (env);
}

char		**ft_set_env(char **board, char **env)
{
	int		i;
	int		o;
	char	*entry;

	o = 0;
	i = 1;
	if (!board[1] || !board[2] || board[3])
	{
		ft_error("usage: setenv [variable] [argument]", NULL);
		return (env);
	}
	while (env[o++])
	{
		if (ft_strnequ(board[1], env[o], ft_strlen(board[1])) == 1 &&
				ft_verif(board[1], env[o]) == 0)
		{
			ft_strdel(&env[o]);
			env[o] = ft_souder(board[1], board[2], "=");
			return (env);
		}
	}
	entry = ft_souder(board[1], board[2], "=");
	env = ft_realloc_for_setenv(env, entry);
	free(entry);
	return (env);
}
