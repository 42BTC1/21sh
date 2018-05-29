/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:54:24 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/29 18:32:29 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"
#include "libft/includes/libft.h"
#include <dirent.h>
#include <unistd.h>

int			ft_search_exec(char *test, char *board)
{
	DIR				*dir;
	struct dirent	*g;

	dir = opendir(test);
	if (dir)
	{
		while ((g = readdir(dir)) != NULL)
		{
			if (ft_strequ(g->d_name, board))
			{
				closedir(dir);
				if (ft_access_exec(test, board) == -1)
					return (-2);
				return (0);
			}
		}
	}
	if (dir)
		closedir(dir);
	return (-1);
}

char		*ft_allocate_parsing(char **tests, char **board)
{
	int				i;
	int				find;
	int				access;

	find = -1;
	access = 0;
	i = 0;
	if (!tests)
	{
		ft_error("21sh: command not found: ", *board);
		return (NULL);
	}
	while (tests[i] && find != 0)
		find = ft_search_exec(tests[i++], *board);
	if (find == -1)
	{
		ft_error("21sh: command not found: ", *board);
		return (NULL);
	}
	else if (find == -2)
		return (NULL);
	return (tests[i - 1]);
}

char	**ft_allocate(char **env)
{
	int		i;
	char	**tests;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (env[i] == 0)
		return (NULL);
	else
		tests = ft_strsplit(&env[i][5], ':');
	return (tests);
}
