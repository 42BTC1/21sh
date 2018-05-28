/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonctions_gestion_de_ligne.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 14:57:20 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/14 19:57:20 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_21sh.h"
#include "../libft/includes/libft.h"

int		ft_error_term(char *s)
{
	if (!s)
		return (-1);
	ft_putstr_fd(s, 2);
	return (-1);
}

void	ft_home(t_storage *x)
{
	while (x->pos > 0)
	{
		if (x->pos > 1 && (x->pos + 3) % x->length == 0)
		{
			tputs(tgetstr("up", NULL), 1, &fct);
			x->pos = x->pos - x->length;
		}
		else
		{
			tputs(tgetstr("le", NULL), 1, &fct);
			x->pos--;
		}
	}
	while (x->pos < 0)
	{
		tputs(tgetstr("nd", NULL), 1, &fct);
		x->pos++;
	}
}

void	ft_home_end(t_storage *x, char *buffer)
{
	char	*s;
	int		i;

	i = 3;
	if (buffer[2] == 70 && x->pos != x->nb_char)
	{
		while (x->pos < x->nb_char)
		{
			if (x->pos > 1 && (x->pos + 3) % x->length == 0)
			{
				tputs(tgetstr("do", NULL), 1, &fct);
				tputs(tgetstr("cr", NULL), 1, &fct);
			}
			else if (!(s = tgetstr("nd", NULL)))
				return ;
			tputs(s, 1, &fct);
			x->pos++;
		}
		if ((x->pos + 3) % x->length == 0)
				tputs(tgetstr("do", NULL), 1, &fct);
	}
	else if (buffer[2] == 72 && x->pos != 0)
		ft_home(x);
}

int		ft_left(t_storage *x)
{
	int		i;
	char	*s;

	if ((x->pos + 3) % x->length == 0)
	{
		tputs(tgetstr("up", NULL), 1, &fct);
		i = x->length;
		while (i--)
			tputs(tgetstr("nd", NULL), 1, &fct);
		x->pos--;
		return (1);
	}
	if ((s = tgetstr("le", NULL)) == NULL)
		return (ft_error_term("This action is not supported\n"));
	tputs(s, 1, &fct);
	x->pos--;
	return (1);
}

int		ft_arrow(char *buffer, t_storage *x)
{
	char	*s;

	if (buffer[2] == 67 && x->pos < x->nb_char)
	{
		x->pos++;
		if ((x->pos + 3) % (x->length) == 0)
		{
			tputs(tgetstr("do", NULL), 1, &fct);
			tputs(tgetstr("cr", NULL), 1, &fct);
			return (1);
		}
		if ((s = tgetstr("nd", NULL)) == NULL)
			return (ft_error_term("This action is not supported\n"));
		tputs(s, 1, &fct);
		return (1);
	}
	if (buffer[2] == 68 && x->pos > 0)
		ft_left(x);
	return (0);
}
