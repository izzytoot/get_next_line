/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:17:28 by icunha-t          #+#    #+#             */
/*   Updated: 2024/11/26 12:24:27 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	polish_list(t_list **list)
{
	t_list *last_node;
	t_list *clean_node;
	int	i;
	int	j;
	int	*buffer;
	
	buffer = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if(!buffer || !clean_node)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->str_buff[i] && last_node->str_buff[i] != '\n')
		++i;
	while (last_node->str_buff[i] && last_node->str_buff[++i])
		buffer[j++] = last_node->str_buff[i];
	buffer[j] = '\0';
	clean_node->str_buff = (char *)buffer;
	clean_node->next = NULL;
	dealloc(list, clean_node, (char *)buffer);
}
char	*get_line(t_list *list)
{
	int	str_len;
	char	*next_str;
	
	if (!list)
		return (NULL);
	str_len = len_new_line(list);
	next_str = malloc(str_len + 1);
	if (!next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	ft_put_buffer_in_list(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buff = buffer;
	new_node->next = NULL;
}
void	ft_new_list(t_list **list, int fd)
{
	int	read_chars;
	char	*buffer;
	
	while (!found_newline(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		read_chars = read(fd, buffer, BUFFER_SIZE);
		if (!read_chars)
		{
			free (buffer);
			return ;
		}
		buffer[read_chars] = '\0';
		ft_put_buffer_in_list(list, buffer);
	}
}
char	*get_next_line(int fd)
{
	static	t_list	*list = NULL;
	char	*next_line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_new_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = get_line(list);
	polish_list(&list);
	return (next_line);
}

int	main(void)
{
	int	fd;
	char	*line;
	int	lines;
	
	lines = 1;
	fd = open("textfile.txt", O_RDONLY);
	if (fd == -1)
		{
			printf("Error opening file.");
			return (1);
		}

	while ((line = get_next_line(fd)) != NULL)
		printf("%d->%s\n", lines++, line);
	close(fd);
	return(0);
}