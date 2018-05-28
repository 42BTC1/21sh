/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_signaux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 09:36:50 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/28 16:29:45 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_21sh.h"
#include "../libft/includes/libft.h"

void	ft_change_length(int nb)
{
	(void)nb;
	g_window = 1;
}

void		ft_reprint(t_storage *x, char *line)
{
	int i;
	i = x->nb_char + 3 / x->length;
	while (i--)
		tputs(tgetstr("dl", NULL), 1, &fct);
	ft_putstr(line);	
}

int			ft_signaux(int window, t_storage *x, char *line)
{
	if (window == 0)
		return (0);
	if (window == 1)
	{	
		window = 0;
		x->length = ft_get_length();
		ft_reprint(x, line);
	}
	return (0);
}
