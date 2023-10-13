/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:24:54 by javperez          #+#    #+#             */
/*   Updated: 2023/10/13 21:18:33 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 0
#endif

char	*get_next_line(int fd)
{
	char buf[BUFFER_SIZE];
	ssize_t nr_bytes;
	int		i;

	i = 0;
	nr_bytes = 0;
	if (fd == -1)
		return (NULL);
	else
	{
		nr_bytes = read(fd, buf, BUFFER_SIZE);
		close(fd);
		if (nr_bytes == 0)
			return (NULL);
		else
		{
			while (buf[i] != '\n')
			{
				write(1, &buf[i], 1);
				i++;
			}
		}
	}
	return (0);
}

int	main(void)
{
	int	fd;

	fd = open("miArchivoCorto", O_RDONLY);
	
	get_next_line(fd);
}