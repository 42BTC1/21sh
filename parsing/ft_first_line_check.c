//header

#include "../ft_21sh.h"
#include "../libft/includes/libft.h"

void	ft_quotes_check(t_tab *x, char c)
{
	if ('"' == c)
		x->flag1 = (x->flag1 == 0) ? 1 : 0;
	if ('\'' == c)
		x->flag2 = (x->flag2 == 0) ? 1 : 0;
}

char	ft_next_char(char *line)
{
	int i;

	i = 0;
	if (!line || !line[0])
		return ('\0');
	while (line[i] && line[i] == ' ')
		i++;	
	return (line[i]);
}


int		ft_very_first_check(char *line)
{
	t_tab x;

	ft_bzero(&x, sizeof(t_tab));
	while (line[x.i])
	{
		if (line[x.i] == '"' || line[x.i] == '\'')
			ft_quotes_check(&x, line[x.i]);
		if (line[x.i] == ';' && x.flag1 == 0 && x.flag2 == 0)
			if (ft_next_char(line + x.i + 1) == ';')
				return (ft_error("21sh: syntax error near unexpected token `;;'", NULL));
		x.i++;
	}
	if (x.flag1 == 1 || x.flag2 == 1)
		return (ft_error("21sh: bad use of quotes", NULL));
	return (0);
}
