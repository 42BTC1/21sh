#include "libft/includes/libft.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>

int		main()
{
	char buffer[5];
	while (1)
	{
		read(0, buffer, 4);
		ft_putstr("buffer[0] = ");
		ft_putnbr(buffer[0]);
		ft_putchar('\n');
		ft_putstr("buffer[1] = ");
		ft_putnbr(buffer[1]);
		ft_putchar('\n');
		ft_putstr("buffer[2] = ");
		ft_putnbr(buffer[2]);
		ft_putchar('\n');
		ft_putstr("buffer[3] = ");
		ft_putnbr(buffer[3]);
		ft_putchar('\n');
	}
	return (0);
}
