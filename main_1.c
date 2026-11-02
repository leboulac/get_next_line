#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(0);
	}
	return (0);
}

/* exemple = printf 'Bonjour\n42\nfin\n' | ./gnl */