#include <stdio.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
	int	fd;
	char	*next_line;
	int	nb_lines = 1;
	
	if (ac != 2)
	{
		printf("Error");
        return 1;
	}
	fd = open(av[1], O_RDONLY);
    if (fd == -1) 
    {
        printf("Error opening file.\n");
		return (1);
    }
	while ((next_line = get_next_line(fd)) != NULL) 
    {
        printf("%d -> %s", nb_lines++, next_line);
        free(next_line);
    }
    close(fd);
    return 0;
}