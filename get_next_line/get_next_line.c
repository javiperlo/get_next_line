/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:24:54 by javperez          #+#    #+#             */
/*   Updated: 2023/10/13 21:56:45 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../libft/libft.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

int	is_new_line_in_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char buf[BUFFER_SIZE];
	ssize_t nr_bytes;
	static int		i;

	i = 0;
	nr_bytes = 0;
	if (fd == -1)
		return (NULL);
	else
	{
		nr_bytes = read(fd, buf, BUFFER_SIZE);
		//printf("El valor de nr_bytes es: %ld\n", nr_bytes);
		close(fd);
		if (nr_bytes == 0)
			return (NULL);
		else
		{
			//Analizar si hay un salto de linea en el buffer
			if (is_new_line_in_word(buf))
				printf("%s", buf);
			else
				printf("No hay un salto de linea en el buffer\n");
		}
	}
	return ("\nFIN");
}

int	main(void)
{
	int	fd;

	fd = open("miArchivoCorto", O_RDONLY);
	
	printf("%s", get_next_line(fd));
}