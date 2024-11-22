/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:17:28 by icunha-t          #+#    #+#             */
/*   Updated: 2024/11/22 17:43:28 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int	bytes_read;
	char	*cup_buffer;
	
	cup_buffer = ft_calloc (3 + 1, sizeof(char));
	if (!cup_buffer)
		return (NULL);
	bytes_read = read(fd, cup_buffer, 3);
	if (bytes_read <= 0)
		return (NULL);
	return (cup_buffer);
}
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int	fd;
	char	*line;
	int	count;

	count = 0;
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
		{
			printf("Error opening file");
			return (1);
		}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		count++;
		printf("[%d]:%s\n", count, line);
		free(line);
		line = NULL;
	}
	close(fd);
	return(0);
}