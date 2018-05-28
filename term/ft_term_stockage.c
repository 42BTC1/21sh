/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonctions_stockage.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:43:54 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/21 19:15:33 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_21sh.h"
#include "../libft/includes/libft.h"

char		*ft_add_char(char *c, char *s, int pos, int nb_char)
{
	char	*test;
	char	*test2;
	char	*ret;

	if (!s)
		return (c);
	test = ft_strndup(s, pos);
	if (nb_char > pos)
	{
		test2 = ft_strdup(s + pos);
		ret = ft_souder(test, test2, c);
		ft_strdel(&test2);
		ft_strdel(&test);
		ft_strdel(&s);
		return (ret);
	}
	test2 = ft_strjoin(test, c);
	ft_strdel(&test);
	ft_strdel(&s);
	return (test2);
}


int			ft_include_the_char(char *c, char *line, t_storage *x)
{
	char	*reprint;
	char	*s;
	int		save;
	int		i;

	i = 0;
	save = 0;
	reprint = ft_strdup(line + x->pos);
	ft_putstr(c);
	tputs(tgetstr("sc", NULL), 1, &fct);
	if (!reprint || reprint[0] == '\0')
		return (0);
	if (!(s = tgetstr("ce", NULL)))
		return (ft_error_term("this capacity is not supported"));
	tputs(s, 1, &fct);
	while (reprint[i])
	{
		if ((x->pos + 3 + ft_strlen(c) + i) % x->length == 0)
		{
			ft_put_cursor_down();
			save = 1;
		}
		ft_putchar(reprint[i]);
		i++;
	}
	return (save);

}

char		*ft_delete_char_in_string(char *s, int nb_char, int pos)
{
	char	*save;
	char	*back_up;
	char	*ret;

	if (!s || (pos == 0 && nb_char == 0))
		return (NULL);
	ret = ft_strndup(s, pos);
	if (nb_char > pos - 1)
	{
		back_up = ft_strdup(s + pos + 1);
		save = ft_strjoin(ret, back_up);
		ft_strdel(&back_up);
		ft_strdel(&ret);
		ft_strdel(&s);
		return (save);
	}
	ft_strdel(&s);
	return (ret);
}

int			ft_clean_lines(int i, t_storage *x)
{
	char	*s;

	(void)x;
	tputs(tgetstr("sc", NULL), 0, &fct);
//sleep(2);
	if (!(s = tgetstr("ce", NULL)))
		return (ft_error_term("This action is not supported\n"));
	tputs(s, 1, &fct);
//sleep(2);
	if (i > 0)
		tputs(tgetstr("do", NULL), 1, &fct);
//sleep(2);
	while (i > 0)
		{
			if (!(s = tgetstr("dl", NULL)))
				return (ft_error_term("This action is not supported\n"));
			tputs(s, 1, &fct);
			i--;
		}
		//tputs(tgetstr("up", NULL), 1, &fct);
	tputs(tgetstr("rc", NULL), 0, &fct);
	return (0);
}

int			ft_delete_char(t_storage *x, char *line)
{
	char	*s;

	if (x->nb_char + 3 < x->length || x->pos == x->nb_char)
	{
		if (!(s = tgetstr("le", NULL)))
			return (ft_error_term("This action is not supported\n"));
		tputs(s, 1, &fct);
		if (!(s = tgetstr("dc", NULL)))
			return (ft_error_term("This action is not supported\n"));
		tputs(s, 1, &fct);
		if (x->pos > 0 && (x->pos + 3) % x->length == 0)
			tputs(tgetstr("nd", NULL), 1, &fct);
		return (0);
	}
	else
	{
		if (x->pos > 0 && (x->pos + 3) % x->length != 0)
			tputs(tgetstr("le", NULL), 1, &fct);
		ft_clean_lines(((x->nb_char - x->pos + 3) / x->length) + 1, x);
		ft_putstr(line + x->pos);
		if (!(s = tgetstr("rc", NULL)))
			return (ft_error_term("This action is not supported\n"));
		tputs(s, 1, &fct);
		if (x->pos > 0 && (x->pos + 3) % x->length == 0)
			tputs(tgetstr("nd", NULL), 1, &fct);
		return (0);
	}
	return (0);
}
