#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft/libft.h"

int	main()
{
	char		buf[4 + 1];
	ssize_t		size;
	int			fd;
	int			i;

	fd = open("wtf.txt", O_RDONLY);
	size = read(fd, buf, 4);
	buf[size] = 0;
	while (buf[i])
	{
		ft_putstr(ft_itoa(buf[i]));
		ft_putchar('\n');
		i++;
	}
	return (1);
}