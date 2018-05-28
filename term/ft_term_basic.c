/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 12:51:07 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/17 15:50:40 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_21sh.h"
#include "../libft/includes/libft.h"

char	*ft_delete_basic_char(char *line, t_storage *x)
{
	int i;

	if (x->pos == 0)
		return (line);
	if (x->pos > 1 && (x->pos + 3) % x->length == 0)
	{
		tputs(tgetstr("dl", NULL), 1, &fct);
		tputs(tgetstr("up", NULL), 1, &fct);
		i = x->length;
		while (i--)
			tputs(tgetstr("nd", NULL), 1, &fct);
	}
	if (ft_delete_char(x, line) == 0)
	{
		x->pos = x->pos - 1;
		x->nb_char = x->nb_char - 1;
		line = ft_delete_char_in_string(line, x->nb_char, x->pos);
	}
	return (line);
}

char	*ft_clean_buffer(char *s)
{
	int		i;
	char	*d;
	int		ret;

	ret = 0;
	i = 0;
	if (!(d = (char*)malloc(sizeof(char) * 5)))
		return (NULL);
	while (s[i])
	{
		if (ft_isprint(s[i]))
			d[ret++] = s[i];
		i++;
	}
	d[ret] = '\0';
	return (d);
}

char	*ft_include(t_storage *x, char *line, char *buffer)
{
	int save;
	int flag;

	save = x->nb_char - (x->nb_char - x->pos) + 1;
	flag = ft_include_the_char(buffer, line, x);
	//return (line);
	line = ft_add_char(buffer, line, x->pos, x->nb_char);
	x->pos += ft_strlen(buffer);
	x->nb_char += ft_strlen(buffer);
	if (flag == 0)
	{
		tputs(tgetstr("rc", NULL), 0, &fct);
	}
	else
	{
	x->pos = x->nb_char;
	if ((x->nb_char + 3) % x->length == 0)
		tputs(tgetstr("do", NULL), 0, &fct);
	ft_move_to(x, save);
	}
	return (line);	
}

char	*ft_basic_char(char *line, t_storage *x, char *buffer)
{
	int save;

	if (x->pos == x->nb_char)
	{
		save = x->pos;
		ft_putstr(buffer);
		line = ft_add_char(buffer, line, x->pos, x->nb_char);
		x->nb_char = x->nb_char + ft_strlen(buffer);
		x->pos = x->pos + ft_strlen(buffer);
		if (x->pos > 1 && (x->pos + 3) % x->length == 0)
			tputs(tgetstr("do", NULL), 0, &fct);
	}
	else
		line = ft_include(x, line, buffer);
	return (line);
}
