#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include "ft_21sh.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

int			ft_pipe_exec(char ***cmd, char **str)
{
	int   p[2];
	pid_t pid;
	int   fd_in;
	fd_in = 0;
	while (*cmd != NULL)
	{
		pipe(p);
		if ((pid = fork()) == -1)
		{
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			dup2(fd_in, 0);
			if (*(cmd + 1) != NULL)
				dup2(p[1], 1);
			close(p[0]);
			if(execve(*str, *cmd, NULL) == -1)
				return (ft_error("21sh: command not found: ", *str));
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
			close(p[1]);
			fd_in = p[0];
			cmd++;
			str++;
		}
	}
	return (0);
}

int		ft_strlen_pipe(char **board)
{
	int i;

	i = 0;
	while (board[i] && ft_strequ(board[i], "|") == 0)
		i++;
	return (i);
}

char ***ft_triple_tab(char **board)
{
	int n;
	int i;
	char ***ret;
	int o;

	ret = NULL;
	o = 0;
	n = 0;
	i = 0;
	while(board[i])
	{
		if (ft_strequ(board[i], "|") == 1)
			n++;
		i++;
	}
	if(!(ret = (char***)malloc(sizeof(char**) * (n + 2))))
		return (NULL);
	i = 0;
	n = 0;
	while (board[i])
	{
		if (!(ret[n] = (char**)malloc(sizeof(char*) * (ft_strlen_pipe(board + i) + 1))))
			return (NULL);
		ret[n] = NULL;
		while (board[i] && ft_strequ(board[i], "|") == 0)
		{
			ret[n] = ft_realloc_for_re(ret[n], board[i++]);
		}
		if (board[i] && ft_strequ(board[i], "|") == 1)
			i++;
		n++;
	}
	ret[n] = NULL;
	return (ret);
}

void			ft_run_exec(char **board, char **env)
{
	int i;
	char ***pipe;
	char **name;
	char	**tableau;
	char	**last_tab;

	last_tab = NULL;
	tableau = NULL;
	i = 0;
	pipe = ft_triple_tab(board);
	name = ft_allocate(env);
	if (!pipe || !name)
		return ;
	while (pipe[i])
	{
		tableau = ft_realloc_for_re(tableau, ft_allocate_parsing(name, pipe[i]));
		i++;
	}
	if (!(last_tab = (char**)malloc(sizeof(char*) * (i + 1))))
			return ;
	i = -1;
	while (tableau[++i])
		last_tab[i] = ft_souder(tableau[i], pipe[i][0], "/");
	last_tab[i] = NULL;
	ft_pipe_exec(pipe, last_tab);
}
