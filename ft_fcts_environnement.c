/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fcts_environnement.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:49:01 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/24 18:16:20 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_21sh.h"
#include <stdlib.h>

char		**ft_realloc_for_setenv(char **env, char *board)
{
	char	**ret;
	int		i;
	int		o;

	o = 0;
	i = 0;
	while (env[i])
		i++;
	if (!(ret = (char**)malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	ret[i + 1] = 0;
	i = 0;
	while (env[i])
	{
		ret[i] = ft_strdup(env[i]);
		i++;
	}
	ret[i++] = ft_strdup(board);
	ft_free_db_tab(env);
	return (ret);
}

char		**ft_realloc_for_unset(char **env, int value)
{
	char	**ret;
	int		i;
	int		o;

	o = 0;
	i = 0;
	while (env[i])
		i++;
	if (!(ret = (char**)malloc(sizeof(char*) * i)))
		return (NULL);
	i = 0;
	while (i < value)
		ret[o++] = ft_strdup(env[i++]);
	if (env[i])
		i++;
	while (env[i])
		ret[o++] = ft_strdup(env[i++]);
	ret[o] = 0;
	ft_free_db_tab(env);
	return (ret);
}

char		**ft_realloc_for_re(char **env, char *board)
{
	char	**ret;
	int		i;
	int		o;

	o = 0;
	i = 0;
	
	if(!board)
		return (env);
	if (env)
	{
		while (env[i])
			i++;
	}
	if (!(ret = (char**)malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	ret[i + 1] = 0;
	i = 0;
	if (env)
	{
		while (env[i])
		{
			ret[i] = ft_strdup(env[i]);
			i++;
		}
	}
	if (board)
		ret[i++] = ft_strdup(board);
	ret[i] = NULL;
	if (env)
		ft_free_db_tab(env);
	return (ret);
}

char		**ft_realloc_for_exe(char **env, char *board, char **cpy)
{
	char	**join;
	int		i;
	int		o;

	o = 0;
	i = 0;

	if (cpy)
	{
		while (cpy[i])
			i++;
	}
	if (!(join = (char**)malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	i = 0;
	if (cpy)
	{
		while (cpy[i])
		{
			join[i] = ft_strdup(cpy[i]);
			i++;
		}
	}
	else
	{
		join[0] = ft_souder(env[0], board, " ");
		join[1] = 0;
		return (join);
	}
	join[i++] = ft_souder(env[0], board, " ");
	join[i] = NULL;
	ft_free_db_tab(cpy);
	return (join);
}

