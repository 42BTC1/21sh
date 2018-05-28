/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimarkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 16:28:30 by vimarkov          #+#    #+#             */
/*   Updated: 2018/05/28 16:30:16 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_21sh.h"
#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"

int		ft_check_char(char **board)
{
	int i;

	i = 0;
	while(board[i])
	{
		if(ft_strequ(board[i], ">") == 1)
			return (1);
		else if(ft_strequ(board[i], "2>") == 1)
			return (1);
		else if(ft_strequ(board[i], ">>") == 1)
			return (1);
		else if(ft_strequ(board[i], "2>>") == 1)
			return (1);
		else if(ft_strequ(board[i], "<") == 1)
			return (1);
		else if(ft_strequ(board[i], "<<") == 1)
			return (1);
		else if(ft_strequ(board[i], "|") == 1)
			return (1);
		i++;
	}
	return (0);
}
