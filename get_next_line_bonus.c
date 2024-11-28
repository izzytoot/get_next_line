/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:30:46 by icunha-t          #+#    #+#             */
/*   Updated: 2024/11/28 14:23:55 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	*list[4096];
	char			*next_line;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_new_list(list, fd);
	if (list[fd] == NULL)
		return (NULL);
	next_line = ft_get_line(list[fd]);
	ft_polish_list(&list[fd]);
	return (next_line);
}

void	ft_new_list(t_list **list, int fd)
{
	int		nb_chars;
	char	*buffer;

	while (!ft_newline(list[fd]))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return ;
		nb_chars = read(fd, buffer, BUFFER_SIZE);
		if (nb_chars == -1)
		{
			free (buffer);
			ft_dealloc(list, NULL, NULL);
			*list = NULL;
			return ;
		}
		if (!nb_chars)
		{
			free (buffer);
			return ;
		}
		buffer[nb_chars] = '\0';
		ft_put_buffer_in_list(list, buffer, fd);
	}
}

void	ft_put_buffer_in_list(t_list **list, char *buffer, int fd)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(list[fd]);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		list[fd] = new_node;
	else
		last_node->next = new_node;
	new_node->str_buff = buffer;
	new_node->next = NULL;
}

char	*ft_get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	str_len = len_new_line(list);
	next_str = malloc(sizeof(char) * (str_len + 1));
	if (next_str == NULL)
		return (NULL);
	ft_copy_str(list, next_str);
	return (next_str);
}

void	ft_polish_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buffer;

	buffer = malloc(sizeof(t_list) * (BUFFER_SIZE + 1));
	clean_node = malloc(sizeof(t_list));
	if (buffer == NULL || clean_node == NULL)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->str_buff[i] && (last_node->str_buff[i] != '\n'))
		++i;
	while (last_node->str_buff[i] && (last_node->str_buff[++i]))
		buffer[j++] = last_node->str_buff[i];
	buffer[j] = '\0';
	clean_node->str_buff = buffer;
	clean_node->next = NULL;
	ft_dealloc(list, clean_node, buffer);
}
