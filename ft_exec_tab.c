/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:13:27 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/24 17:42:26 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"
#include "libft/includes/libft.h"

//boucler jusqua arriver a un pype en strjoin les deux trucs a chaque fois 

/*
char		*ft_souder_free(char *s1, char *middle, char *s2, int flag)
{
	char	*name;
	char	*ret;

	name = ft_strjoin(s1, middle);
	ret = ft_strjoin(name, s2);
	ft_strdel(&name);
	if (flag == 1)
		ft_strdel(&s2);
	else 
		ft_strdel(&s1);
	return (ret);
}

char		*ft_alloc_dim_back(char **board, int o)
{
	int		i;
	char	*ret;

	i = 0;
	while (board[i])
	{
		if (ft_strequ(board[i],  "|") == 1)
		{
			if (o == 0)
				break;
			o--;	
		}
		i++;
	}
	if (board[i + 1])
	{
		i++;
		ret = ft_strdup(board[i++]);
	}
//	while (board[i] && ft_tokens(board[i], 0, NULL) == 0)
//	{
//		ret = ft_souder_free(ret, " ", board[i], 0);
//		i++;
//	}
	return (ret);
}

char		*ft_alloc_dim_front(char **board, int o)
{
	int		i;
	char	*ret;

	i = 0;
	while (board[i])
	{
		if (ft_strequ(board[i],  "|") == 1)
		{
			if (o == 0)
				break;
			o--;	
		}
		i++;
	}
	i--;
	ret = ft_strdup(board[i--]);
	while (i >= 0 && ft_tokens(board[i], 0, NULL) == 0)
	{

	}
	return (ret);
}

char		***ft_scd_dim(char **board, int count)
{
	char	***ret;
	int		o;
	int nb;

	nb = 0;
	o = 0;
	if (!(ret = (char***)malloc(sizeof(char***) * (count + 1))))
		return (NULL);
	while (o < count)
	{
		if (!(ret[o] = (char**)malloc(sizeof(char**) * 3)))
			return (NULL);
		ret[o][0] = ft_alloc_dim_front(board, o);
		ret[o][1] = ft_alloc_dim_back(board, o);
		ft_putendl(ret[o][0]);
		ft_putendl(ret[o][1]);
		ret[o][2] = 0;
		o++;
	}
	ret[o] = 0;

	return (ret);
}

char		***ft_exec_tab(char **board)
{
	int			i;
	int			count;
	char		***ret;

	count = 0;
	i = 0;
	while (board[i])
	{
		if (ft_strequ(board[i], "|") == 1)
			count++;
		i++;
	}
	ret = ft_scd_dim(board, count);
	return (ret);
}
*/
