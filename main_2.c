#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	line = get_next_line(fd);
	if (line == NULL)
		printf("NULL\n");
	else
	{
		printf("ERREUR : %s\n", line);
		free(line);
	}
	return (0);
}