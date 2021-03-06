/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:11:00 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/02 17:16:23 by vimarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_db(char **board)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (board[i] == '\0')
		return ;
	while (board[i])
	{
		while (board[i][j])
		{
			ft_putchar(board[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
}
