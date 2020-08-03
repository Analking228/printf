#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft/libft.h"

int	main()
{
	char		buf[26];
	ssize_t		size;
	int			fd;
	int			i;

	fd = open("wtf.txt", O_RDONLY);
	size = read(fd, buf, 25);
	buf[25] = 0;
	while (buf[i])
	{
		ft_putstr(ft_itoa(buf[i]));
		ft_putchar(' ');
		if (buf[i] == '\n')
			ft_putchar('\n');
		i++;
	}
	return (1);
}