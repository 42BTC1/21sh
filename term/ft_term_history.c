/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:00:23 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/14 19:23:25 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_21sh.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"

t_dlist		*ft_lst_new(t_dlist *history, char *line)
{
	t_dlist *new;

	if (!line)
		return (history);
	if (!(new = (t_dlist*)malloc(sizeof(t_dlist*))))
		return (NULL);
	new->content = ft_strdup(line);
	new->next = NULL;
	if (history)
		new->next = history;
	return (new);
}

int			ft_lstlen(t_dlist *tmp)
{
	t_dlist *tmp2;
	int		i;

	i = 0;
	tmp2 = tmp;
	while (tmp2)
	{
		i++;
		tmp2 = tmp2->next;
	}
	return (i);
}

char		*ft_arrow_down(t_storage *x, t_dlist *tmp, char *line)
{
	int i;

	if (x->value > 0)
		x->value--;
	i = (*x).value;
	while (tmp && i)
	{
		tmp = tmp->next;
		i--;
	}
	if (tmp && tmp->content)
	{
		ft_putstr(tmp->content);
		x->pos = ft_strlen(tmp->content);
		x->nb_char = x->pos;
		if (line)
			ft_strdel(&line);
		return (ft_strdup(tmp->content));
	}
	return (line);
}

char		*ft_arrow_up(t_storage *x, t_dlist *tmp, char *line)
{
	int i;

	if (x->value < ft_lstlen(tmp) - 1 && x->bolean == 1)
		x->value++;
	i = (*x).value;
	while (tmp && i)
	{
		tmp = tmp->next;
		i--;
	}
	if (tmp && tmp->content)
	{
		ft_putstr(tmp->content);
		x->pos = ft_strlen(tmp->content);
		x->nb_char = x->pos;
		if (line)
			ft_strdel(&line);
		return (ft_strdup(tmp->content));
	}
	return (line);
}

char		*ft_history_arrow(t_dlist *p, t_storage *x,
		char *line, char *buffer)
{
	t_dlist *tmp;
	int		c;

	if (!p)
		return (line);
	tmp = p;
	if (buffer[2] == 65)
		c = 65;
	else
		c = 66;
	buffer[2] = 72;
	ft_home_end(x, buffer);
	buffer[2] = c;
	ft_clean_lines(((x->nb_char) / x->length), x);
	if (buffer[2] == 66 && x->value == 0)
		return (ft_error_hist(x, line, buffer));
	else if (buffer[2] == 65)
		line = ft_arrow_up(x, tmp, line);
	else if (buffer[2] == 66)
		line = ft_arrow_down(x, tmp, line);
	x->bolean = 1;
	return (line);
}
