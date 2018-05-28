/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimarkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:49:17 by vimarkov          #+#    #+#             */
/*   Updated: 2018/05/28 19:46:17 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include "ft_21sh.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

int		ft_open(char **board, char **flag, char **opn_dir, char **opn_err)
{
	int i;
	int j;
	int fd;
	i = 0;
	j = 0;
	while(board[i])
	{
		while(flag[j])
		{
			if(ft_strequ(board[i], flag[j]) == 1)
			{
				//f(ft_strequ("|", flag[j]) == 1)
				//	j++;
				if(board[i + 1])
				{
					if(ft_strequ(flag[j], "2>") == 0)
					{
						*opn_dir = ft_strdup(board[i + 1]);
					}
					if(ft_strequ(flag[j], "2>") == 1 || ft_strequ(flag[j], "2>>") == 1)
						*opn_err = ft_strdup(board[i + 1]);
					if (ft_strequ(flag[j], ">") == 1 || ft_strequ(flag[j], "2>") == 1)
					{
						if ((ft_strequ(flag[j], ">") == 1))
							fd = open(*opn_dir, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
					}
					if (ft_strequ(flag[j], ">>") == 1 || ft_strequ(flag[j], "2>>") == 1)
					{
						fd = open(*opn_dir, O_CREAT | O_APPEND | O_WRONLY, 0666);
						return (fd);
					}
					if (ft_strequ(flag[j], "<") == 1)
					{
						fd = open(*opn_dir, O_RDONLY);
						return (fd);
					}
				}
				else if(ft_strequ(board[i], "2>&1") == 1 && !board[i + 1])
					return (fd);
				else
					return(ft_error("21sh: parse error near `\\n'", NULL));
			}
			j++;
		}
		j = 0;
		i++;
	}
	return(fd);
}
