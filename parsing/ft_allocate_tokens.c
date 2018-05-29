/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:45:59 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/29 18:58:48 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_21sh.h"
#include "../libft/includes/libft.h"

char	**ft_allocate_tokens(void)
{
	char **board;

	if (!(board = (char**)malloc(sizeof(char*) * 9)))
		return (NULL);
	board[0] = ft_strdup("<");
	board[1] = ft_strdup(">");
	board[2] = ft_strdup(";");
	board[3] = ft_strdup("|");
	board[4] = ft_strdup("<<");
	board[5] = ft_strdup(">>");
	board[6] = ft_strdup("2>");
	board[8] = ft_strdup("2>>");
	board[7] = ft_strdup("2>&1");
	board[9] = 0;
	return (board);
}
