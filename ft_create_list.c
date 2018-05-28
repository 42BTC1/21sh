/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:44:15 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/24 16:12:05 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"
#include "libft/includes/libft.h"

char	**ft_create_board(char *line)
{
	int		i;
	int		flag;
	char	**board;
	
	board = NULL;
	flag = 0;
	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i])
	{
		while (line[i] && line[i] != ';')
		{
			if ((line[i] == '"' || line[i] == ''') && flag == 0)
				flag = 1;	
			else if ((line[i] == '"' || line[i] == ''') && flag == 1)
				flag == 0
			i++;
		}
		if (((line[i] == ';' && flag == 0) || !line[i])
			board = ft_realloc_for_setenv(x, ft_strndup(line, i));
		i++;
	}
	return (board);
}
