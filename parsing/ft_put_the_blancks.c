/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_the_blancks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:41:02 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/21 19:43:45 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_21sh.h"
#include "../libft/includes/libft.h"

char	*ft_include_char(char *line, int pos)
{	
	char *ret;
	char *tmp;
	char *tableau;

	ret = ft_strndup(line, pos);
	tmp = ft_strdup(line + pos);
	tableau = ft_souder(ret, tmp, " ");
	if (ret)
		ft_strdel(&ret);
	if (tmp)
		ft_strdel(&tmp);
	return (tableau);
}

char	*ft_add_blanks(char *line, t_tab *x)
{
	line = ft_include_char(line, x->i);
	x->i += 2;
	if (line[x->i] == '>' || line[x->i] == '<')
		x->i += 1;
	if (line[x->i] == '>' || line[x->i] == '&')
		x->i += 1;
	if (line[x->i] == '1')
		x->i += 1;
	line = ft_include_char(line, x->i);
	return (line);
}

char	*ft_put_some_blanks(char *line)
{
	t_tab	x;

	ft_bzero(&x, sizeof(t_tab));
	while (line[x.i])
	{
		if (line[x.i] == '"' || line[x.i] == '\'')
			ft_quotes_check(&x, line[x.i]);
		if (x.flag1 == 0 && x.flag2 == 0 && 
			ft_tokens(line, x.i) == 1)
			line = ft_add_blanks(line, &x);
		x.i++;
	}
	return (line);
}
