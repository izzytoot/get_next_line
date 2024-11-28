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
		close(fd);
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


int main(void)
{
    int fd1, fd2;
    char *line;

    fd1 = open("textfile.txt", O_RDONLY);
    fd2 = open("shrek.txt", O_RDONLY);
    if (fd1 == -1 || fd2 == -1) 
	{
        perror("Failed to open files");
        return (1);
    }
    printf("Reading from file1.txt:\n");
    while ((line = get_next_line(fd1)) != NULL) {
        printf("%s", line);
        free(line); // Don't forget to free the memory allocated for each line
    }
    printf("\nReading from file2.txt:\n");
    while ((line = get_next_line(fd2)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd1);
    close(fd2);
    return 0;
}