/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimarkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 11:39:41 by vimarkov          #+#    #+#             */
/*   Updated: 2018/05/29 18:54:26 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_21sh.h"
#include "libft/includes/libft.h"


char	**ft_remove_quotes(char **board)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (board[i])	
	{
		while (board[i][j])
		{
			if (board[i][j] == '"' || board[i][j] == '\'')
				board[i] = ft_delete_char_in_string(board[i], ft_strlen(board[i]), j);		
			j++;	
		}
		i++;
		j = 0;
	}
	return (board);
}


char	**ft_keep_board(char **board, char *line, int *i, int *o)
{
	if (line + *o)
		board = ft_realloc_for_re(board, ft_strndup(line + *o, *i - *o));
	*o = *o + (*i - *o);
	while (line[*i] == ';' || line[*i] == ' ')
	{
		*o += 1;
		*i += 1;
	}
	return (board);
}

char	**ft_create_board(char *line, char c, int number)
{
	t_tab	x;
	char	**board;

	board = NULL;
	ft_bzero(&x, sizeof(t_tab));
	x.i = (number > 0) ? 1 : 0;
	while (line[x.i] && line[x.i] == ' ')
		x.i++;
	x.o = x.i;
	while (line[x.i])
	{
		while (line[x.i] && line[x.i] != c)
			ft_quotes_check(&x, line[x.i++]);
		if ((line[x.i] == c && x.flag1 == 0 && x.flag2 == 0) ||
				line[x.i] == '\0')
			board = ft_keep_board(board, line, &x.i, &x.o);
		if (line[x.i] == c)
			x.i++;
	}
	return (board);
}

char	**ft_parseur(char *line, char **env, char **tokens)
{
	char	**board;
	char	**good_board;
	int		i;
	(void)tokens;

	i = 0;
	if (ft_very_first_check(line) == -1)
		return (env);
	board = ft_create_board(line, ';', -1);
	if (ft_parsing(board) == NULL)
		return (env);
	while (board[i])
	{
		good_board = ft_create_board(board[i], ' ', -1);
		if (good_board)
		{	
			//print_db(good_board);
			ft_remove_quotes(good_board);
			env = ft_find_option(line, env, good_board);
			ft_free_db_tab(good_board);
		}
		i++;
	}
	ft_free_db_tab(board);
	return (env);
}
