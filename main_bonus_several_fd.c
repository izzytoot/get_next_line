#include <stdio.h>
#include "get_next_line.h"


int	main(int ac, char **av)
{
	int	fd;
	char	*next_line;
	int	i;
	
	if (ac < 2)
	{
		printf("Error");
        return 1;
	}
	i = 1;
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd == -1) 
    	{
       		printf("Error opening file.\n");
			close(fd);
    	}
		else
		{
			printf("File %d:\n\n", i);
			while((next_line = get_next_line(fd)))
			{
				printf("%s", next_line);
				free(next_line);
			}
			close(fd);
		}
		i++;
		printf("\n\n");
	}
	return (0);
}
