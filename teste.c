/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:36:46 by icunha-t          #+#    #+#             */
/*   Updated: 2024/11/22 17:53:47 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int	fd;
	fd = open("textfile.txt", O_RDWR | O_CREAT | O_APPEND);
	printf("fd of file is %d", fd);
	write (fd, "hello", 5);
	dup2(1, fd);
	return (0);
}