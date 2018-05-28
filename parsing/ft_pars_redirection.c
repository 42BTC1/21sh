//header

#include "../ft_21sh.h"
#include "../libft/includes/libft.h"

int		ft_parsing_redirection(char *s)
{
	struct stat		buf;

	lstat(s, &buf);
	if (access(s, F_OK) == -1)
		return ft_error("21sh: no such file or directory: ", s);
	if (S_ISDIR(buf.st_mode) == 1)
		return ft_error("21sh: is a directory: ", s);
	if (access(s, X_OK) == -1)
		return ft_error("21sh: permission denied: ", s);
	return (0);
}
