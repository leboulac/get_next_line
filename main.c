#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd = 0;
	char *line;

	fd = open("test.txt", O_RDONLY);
	if(fd == -1)
	{
		printf("ERROR");
		return 1;
	}

	line = get_next_line(fd);
	while(line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("\n");
	return 0;
}