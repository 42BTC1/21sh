/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:58:00 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/14 19:58:34 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_21sh.h"
#include "../libft/includes/libft.h"

int		ft_put_cursor_up(t_storage *x)
{
	char	*s;
	int		i;

	i = x->length;
	if (!(s = tgetstr("up", NULL)))
		return (ft_error("not able to do that", NULL));
	tputs(s, 1, &fct);
	while (i--)
	{
		if (!(s = tgetstr("nd", NULL)))
			return (ft_error("not able to do that", NULL));
		tputs(s, 1, &fct);
	}
	return (0);
}

int		ft_put_cursor_down(void)
{
	char	*s;

	if (!(s = tgetstr("do", NULL)))
		return (ft_error("not able to do that", NULL));
	tputs(s, 1, &fct);
	if (!(s = tgetstr("cr", NULL)))
		return (ft_error("not able to do that", NULL));
	tputs(s, 1, &fct);
	return (0);
}

char	*ft_back_delete(t_storage *x, char *line)
{
	int		o;
	char	*s;

	o = 0;
	if (x->nb_char == 0 || !line[x->pos])
		return (line);
	if ((x->nb_char + 3) > x->length)
	{
		ft_clean_lines(((x->nb_char - x->pos + 3) / x->length) + 1, x);
		ft_putstr(line + x->pos + 1);
	if (!(s = tgetstr("rc", NULL)))
		return (NULL);
	tputs(s, 1, &fct);

	}
	else
		tputs(tgetstr("dc", NULL), 1, &fct);
	line = ft_delete_char_in_string(line, x->nb_char, x->pos);
	x->nb_char--;
	return (line);
}

void	ft_jump_words_left(t_storage *x, char *line)
{
	char *s;

	while (x->pos > 0 && line[x->pos] != ' ')
	{
		if (x->pos > 0 && (x->pos + 3) % x->length == 0)
			ft_put_cursor_up(x);
		else
		{
			if (!(s = tgetstr("le", NULL)))
				return ;
			tputs(s, 1, &fct);
		}
		x->pos--;
	}
	while (x->pos > 0 && line[x->pos] <= 32)
	{
		if (x->pos > 0 && (x->pos + 3) % x->length == 0)
			ft_put_cursor_up(x);
		else
			tputs(tgetstr("le", NULL), 1, &fct);
		x->pos--;
	}
}

void	ft_jump_words(t_storage *x, char *buffer, char *line)
{
	char	*s;

	if (buffer[1] == 67 && x->nb_char > 0)
	{
		while (line[x->pos] && line[x->pos] > 32)
		{
			if (!(s = tgetstr("nd", NULL)))
				return ;
			tputs(s, 1, &fct);
			x->pos++;
			if (x->pos > 0 && (x->pos + 3) % x->length == 0)
				ft_put_cursor_down();
		}
		while (line[x->pos] && line[x->pos] <= 32)
		{
			if (!(s = tgetstr("nd", NULL)))
				return ;
			tputs(s, 1, &fct);
			x->pos++;
			if (x->pos > 0 && (x->pos + 3) % x->length == 0)
				ft_put_cursor_down();
		}
		return ;
	}
	ft_jump_words_left(x, line);
}
