/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:56:04 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/29 17:25:34 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_21sh.h"
#include <stdlib.h>

char		**ft_check_pwd(char **env)
{
	int		i;
	char	*buf;
	char	*tmp;

	i = 0;
	buf = NULL;
	if ((buf = getcwd(buf, 0)) == NULL)
		return (NULL);
	while (env[i])
	{
		if (ft_strnequ(env[i], "PWD=", 4) == 1)
		{
			ft_strdel(&env[i]);
			env[i] = ft_strjoin("PWD=", buf);
			ft_strdel(&buf);
			return (env);
		}
		i++;
	}
	tmp = ft_strjoin("PWD=", buf);
	env = ft_realloc_for_setenv(env, tmp);
	ft_strdel(&tmp);
	ft_strdel(&buf);
	return (env);
}

char		**ft_check_old(char **env)
{
	int		i;
	char	*buf;
	char	*test;

	i = 0;
	buf = NULL;
	if ((buf = getcwd(buf, 0)) == NULL)
		return (NULL);
	while (env[i])
	{
		if (ft_strnequ(env[i], "OLDPWD=", 7) == 1)
		{
			ft_strdel(&env[i]);
			env[i] = ft_strjoin("OLDPWD=", buf);
			ft_strdel(&buf);
			return (env);
		}
		i++;
	}
	test = ft_strjoin("OLDPWD=", buf);
	env = ft_realloc_for_setenv(env, test);
	free(test);
	ft_strdel(&buf);
	return (env);
}

char		**ft_get_into_env(char **env, char *s)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (ft_strnequ(env[i], "OLDPWD=", 4) == 1)
		{
			ft_strdel(&env[i]);
			env[i] = ft_strdup(s);
			return (env);
		}
		i++;
	}
	return (ft_realloc_for_setenv(env, s));
}
