#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	buf[14];
	size_t	count;

	fd = open("txt.txt", O_RDONLY);
	if (fd == -1)
		return(0);
	count = read(fd, buf, 13);
	buf[count] = 0;
	write (1, buf, count);
	close (fd);
	return (0);
}