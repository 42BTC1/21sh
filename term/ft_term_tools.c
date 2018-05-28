/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:09:59 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/14 19:57:26 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_21sh.h"
#include "../libft/includes/libft.h"

int		fct(int c)
{
	ft_putchar(c);
	return (0);
}

char	*ft_change_this_int(char c)
{
	char *ret;

	if (!(ret = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}

char	*ft_error_hist(t_storage *x, char *line, char *buffer)
{
	if (line)
		ft_strdel(&line);
	buffer[2] = 72;
	ft_home_end(x, buffer);
	buffer[2] = 65;
	ft_clean_lines(((x->nb_char) / x->length), x);
	x->value--;
	x->nb_char = 0;
	return (NULL);
}

void	ft_get_back(t_storage *x, int goal)
{
	char *s;
//	ft_putendl("\n");
//	ft_putnbr(x->pos);
//	ft_putendl("\n");
//	ft_putnbr(goal);
	while (x->pos > goal)
	{
		if (x->pos != 0 && (x->pos + 3) % x->length == 0)
			ft_put_cursor_up(x);
		else
		{
			if ((s = tgetstr("le", NULL)) == NULL)
				return ;
			tputs(s, 1, &fct);
		}
		x->pos--;
	}
}

void	ft_go_to(t_storage *x, int goal)
{
	char *s;
//	ft_putendl("\n");
//	ft_putnbr(x->pos);
//	ft_putnbr(goal);

	while (x->pos < goal)
	{
		if ((s = tgetstr("nd", NULL)) == NULL)
			return ;
		tputs(s, 1, &fct);
		x->pos++;
		if (x->pos != 0 && (x->pos + 3) % x->length == 0)
			ft_put_cursor_down(x);
	}
}

void	ft_move_to(t_storage *x, int goal)
{
	if (x->pos == goal || goal < 0)
		return ;
	if (x->pos > goal)
		ft_get_back(x, goal);
	if (x->pos < goal)
		ft_go_to(x, goal);
}
