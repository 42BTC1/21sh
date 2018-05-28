/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_cpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:19:19 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/28 15:03:28 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_21sh.h"
#include "../libft/includes/libft.h"


char	*ft_cut(t_storage *x, char *line)
{
	int tmp;

	if (x->pos < x->check)
	{
		tmp = x->check - x->pos;
		while (tmp--)
			line = ft_back_delete(x, line);
	}
	else if (x->pos > x->check)
	{
		tmp = x->pos - x->check;	
		while (tmp--)
			line = ft_delete_basic_char(line, x);
	}
	return (line);
}

char	*ft_get_cpy(t_storage *x, char *buffer, char *line)
{
	if (x->check == -1)
	{
		x->check = x->pos;
		return (line);
	}
	if (x->pos == x->check)
	{
		x->check = -1;
		return (line);
	}
	if (x->buffer_cpy)
		ft_strdel(&x->buffer_cpy);
	if (x->check < x->pos)
		x->buffer_cpy = ft_strndup(line + x->check, x->pos - x->check + 1);
	else if (x->check > x->pos)
		x->buffer_cpy = ft_strndup(line + x->pos, x->check - x->pos);
	if (buffer[1] == -119)
		line = ft_cut(x, line);
		x->check = -1;
		return (line);
}

char	*ft_past_buffer(t_storage *x, char *line)
{
	int i;

	i = 0;
	if (!x->buffer_cpy)
		return (line);
	//ft_putstr(x->buffer_cpy);
	line = ft_basic_char(line, x, x->buffer_cpy);
	x->check = -1;
	return (line);
}
