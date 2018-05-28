/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcaps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 11:35:26 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/28 16:24:57 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_21sh.h"
#include "../libft/includes/libft.h"
int			g_window;	

int			ft_get_length(void)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	return (w.ws_col);
}

int			ft_set_term(void)
{
	struct termios	term;
	char			*name;

	if (!(name = getenv("TERM")))
		return (ft_error_term("this terminal is not valid\n"));
	if (tgetent(NULL, name) <= 0)
		return (ft_error_term("the terminfo database could not be found.\n"));
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON | ECHO | ISIG);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}

int			ft_unset_term(void)
{
	struct termios term;

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag |= (ICANON | ECHO | ISIG);
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
	return (0);
}

char		*ft_extra_keys(char *line, char *buffer, t_storage *x)
{
	if (buffer[1] == -89 || buffer[1] == -119)
		line = ft_get_cpy(x, buffer, line);
	else if (buffer[1] == -120)
		line = ft_past_buffer(x, line);
	else if (buffer[1] == 67 || buffer[1] == 68)
		ft_jump_words(x, buffer, line);
	else if (buffer[1] == 66 || buffer[1] == 65)
		ft_jump_line(x, buffer);
	else if (buffer[0] == 127 && x->pos > 0)
		line = ft_delete_basic_char(line, x);
	else if (buffer[2] == 67 || buffer[2] == 68)
		ft_arrow(buffer, x);
	else if (buffer[2] == 70 || buffer[2] == 72)
		ft_home_end(x, buffer);
	else if (buffer[2] == 51)
		line = ft_back_delete(x, line);
	else if (buffer[0] >= 32 && buffer[0] < 127)
	{
		buffer = ft_clean_buffer(buffer);
		line = ft_basic_char(line, x, buffer);
	}
	return (line);
}

char		*which_khey(t_dlist *hist)
{
	t_storage	x;
	char		*line;
	char		buffer[5];
	int i;

	i = 0;
	g_window = 0;
	line = NULL;
	ft_bzero(&x, sizeof(t_storage));
	if (ft_set_term() == -1)
		return (NULL);
	tputs(tgetstr("ks", NULL), 1, &fct);
	ft_bzero(buffer, sizeof(buffer));
	x.length = ft_get_length();
	x.check = -1;
	while (1)
	{
		read(0, buffer, 4);
		signal(SIGWINCH, &ft_change_length);
		if (ft_signaux(g_window, &x, line) == -1)
			break;
		if (buffer[0] == 10)
		{
			ft_unset_term();
			return (line);
		}
		if (buffer[2] == 65 || buffer[2] == 66)
			line = ft_history_arrow(hist, &x, line, buffer);
		else
			line = ft_extra_keys(line, buffer, &x);
	//	if (buffer[0] == 9)
	//		printf("length = %d\npos = %d\nnb_char = %d\n", x.length, x.pos, x.nb_char);
		if (buffer[0] == 4)
		{
			ft_unset_term();
			exit(1);
		}
		if (buffer[0] == 3)
			return (NULL);
	
		ft_bzero(buffer, sizeof(buffer));
	}
	return (NULL);
}
