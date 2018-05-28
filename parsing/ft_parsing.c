/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:41:00 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/28 17:07:15 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_21sh.h"
#include "../libft/includes/libft.h"

int		ft_tokens(char *line, int i)
{
		char *tmp;

		if (line[i] == '|' || line[i] == '>' || line[i] == '<' || 
			line[i] == '2')
		{
				if (line[i] != '2')
						return (1);
				tmp = ft_strndup(line + i, 4);
				if (ft_strequ(tmp, "2>&1"))
				{	
					ft_strdel(&tmp);
					return (4);
				}
				ft_strdel(&tmp);
				if (line[i] == '2' && line[i + 1] == '>')
						return (2);
		}
		return (0);
}

int		ft_next_token(char *line, int i, int pipe)
{
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '>' || line[i] == '<' || 
			line[i] == '2' || line[i] == '|')
	{
			if (pipe == 1 && line[i] != '|')
				return (0);
			if (line[i] != '2')
					return (1);
			else if (line[i] == '2' && line[i + 1] == '>')
				return (1);
	}
	if (line[i] == '|' && pipe == 1)
		return (1);
	return (0);
}

int		ft_parsing_by_line(char *line)
{
		int i;
		int pipe;
		int o;

		pipe = 0;
		i = 0;
		if (line[i] == '|')
				return (ft_error("21sh: parse error near ", "`|'"));
		while (line[i])
		{
				if ((o = ft_tokens(line, i)) > 0)
				{
					if (line[i] == '|')
						pipe = 1;		
					i = i + o;
					if (line[i] && line[i] == '>')
						i++;
					if (ft_next_token(line, i, pipe) == 1)
						return (ft_error("21sh: syntax error near unexpected token", NULL));
				}
				pipe = 0;
				i++;
		}
		return (0);
}

char	**ft_parsing(char **board)
{
		int i;

		i = 0;
		while (board[i])
		{
				if (ft_parsing_by_line(board[i]) == -1)
						return (NULL);
				board[i] = ft_put_some_blanks(board[i]);
				i++;
		}
		return (board);
}
