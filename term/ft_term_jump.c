/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_jump.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:53:39 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/14 19:38:42 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_21sh.h"
#include "../libft/includes/libft.h"

void	ft_jump_line_up_extend(int *bolean, t_storage *x)
{
	int		tmp;
	char	*s;

	tmp = x->length - 1;
	while (tmp && x->pos > 1)
	{
		if (x->pos != 0 && (x->pos + 3) % x->length == 0)
		{
			ft_put_cursor_up(x);
			*bolean = 0;
		}
		if ((s = tgetstr("le", NULL)) == NULL)
			return ;
		tputs(s, 1, &fct);
		x->pos--;
		tmp--;
	}
	if (x->pos > 0)
		x->pos--;
}

void	ft_jump_line_up(t_storage *x)
{
	int		save;
	int		bolean;
	char	*s;

	if ((s = tgetstr("sc", NULL)) == NULL)
		return ;
	tputs(s, 1, &fct);
	bolean = 1;
	save = x->pos;
	ft_jump_line_up_extend(&bolean, x);
	if (bolean == 1)
	{
		if ((s = tgetstr("rc", NULL)) == NULL)
			return ;
		tputs(s, 1, &fct);
		x->pos = save;
	}
}

void	ft_jump_line_extend(int *bolean, t_storage *x)
{
	int		tmp;
	char	*s;

	tmp = x->length;
	if ((s = tgetstr("sc", NULL)) == NULL)
		return ;
	tputs(s, 1, &fct);
	while (tmp-- && x->pos < x->nb_char)
	{
		if ((s = tgetstr("nd", NULL)) == NULL)
			return ;
		tputs(s, 1, &fct);
		x->pos++;
		if ((x->pos + 3) % x->length == 0)
		{
			tputs(tgetstr("do", NULL), 1, &fct);
			*bolean = 0;
		}
	}
}

void	ft_jump_line(t_storage *x, char *buffer)
{
	int save;
	int	bolean;

	bolean = 1;
	save = x->pos;
	if (buffer[1] == 66)
	{
		ft_jump_line_extend(&bolean, x);
		if (bolean == 1)
		{
			tputs(tgetstr("rc", NULL), 1, &fct);
			x->pos = save;
		}
		return ;
	}
	ft_jump_line_up(x);
}
