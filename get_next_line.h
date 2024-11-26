/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:43:27 by icunha-t          #+#    #+#             */
/*   Updated: 2024/11/26 12:26:37 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	char			*str_buff;
	struct s_list	*next;
}				t_list;

int	found_newline(t_list *list);
t_list	*find_last_node(t_list *list);
char	*get_line(t_list *list);
void	copy_str(t_list *list, char *str);
int	len_new_line(t_list *list);
void	polish_list(t_list **list);
char	*get_next_line(int fd);
void	dealloc(t_list **list, t_list *clean_node, char *buffer);
void	ft_new_list(t_list **list, int fd);
void	ft_put_buffer_in_list(t_list **list, char *buffer);

#endif