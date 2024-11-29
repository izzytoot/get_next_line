#include <stdio.h>
#include "get_next_line.h"


int	main(void)
{
	int	fd1 = open("textfile.txt", O_RDONLY);
	int	fd2 = 0;
	char	*next_line;

	while((next_line = get_next_line(fd1)))
	{
		printf("%s", next_line);
		free(next_line);
	}
	close(fd1);
	while((next_line = get_next_line(fd2)))
	{
		printf("%s", next_line);
		free(next_line);
	}
	close(fd2);
	return (0);
}
