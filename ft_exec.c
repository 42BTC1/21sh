#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include "ft_21sh.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

int			ft_pipe_exec(char ***cmd)
{
	int   p[2];
	pid_t pid;
	int   fd_in;
	fd_in = 0;
	char *str = ft_strdup("/bin/ls");
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
			execve(str, *cmd, NULL);
			exit(EXIT_FAILURE);
		}
		else
		{
			str = ft_strdup("/bin/cat");
			wait(NULL);
			close(p[1]);
			fd_in = p[0];
			cmd++;
		}
	}
	return (0);
}

void			ft_run_exec(char ***ret)
{
//	int i;
///	char *ls[] = {"ls", NULL};
//	char *cat[] = {"cat", "-e", NULL};
//	char **cmd[] = {ls, cat, NULL};
//	i = 0;
	ft_putendl("PASS");
	ft_pipe_exec(ret);
}
