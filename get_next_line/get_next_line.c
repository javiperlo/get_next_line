/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:24:54 by javperez          #+#    #+#             */
/*   Updated: 2023/10/20 17:30:13 by javperez         ###   ########.fr       */
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

char *split_and_join_words(int fd);

int check_next_line(char *buff)
{
	//int 	len;
	int		i;
	i = 0;
	//len = ft_strlen(buff);
	//static char	*line;
	//buff[len++] = '\0';
	while (buff[i] != '\0')
	{
		if(buff[i] == '\n')
			return (1);
		i ++;
	}
	//line = (char *)malloc(ft_strlen(buff) * sizeof(char) + 1); // Reserva espacio en memoria para cada grupo de palabras
	//printf("Se han almacenado %ld bytes de memoria\n", (ft_strlen(buff) * sizeof(char) + 1));
	//ft_strjoin(line, buff);
	//line = ft_strjoin()	
	return (0);
}

char *split_and_join_words(int fd)
{
	ssize_t nr_bytes;
	char buff[BUFFER_SIZE];
	int i = 0;
	char *new_block;
	static char *line;
	
	if (fd == -1)
		return (NULL);
	nr_bytes = read(fd, buff, BUFFER_SIZE);
	//printf("Se van a imprimir %ld bytes, y el buffer es: \n%s\n", nr_bytes,buff);
	new_block = ft_substr(buff, i, i + nr_bytes); //Cogemos en cada iteración, desde i hasta i + nr_bytes
	line = (char *)malloc((ft_strlen(new_block) * sizeof(char)) + 1); // Reserva espacio en memoria para cada grupo de palabras
	if (!line)
		return (NULL);
	i += nr_bytes; //E iteramos de nuevo para quedarnos con el siguiente trozo de BUFFER_SIZE
	if(check_next_line(new_block) == 0)
	{
		printf("%s",ft_strjoin(line, new_block));
		split_and_join_words(fd);
	}
	/*else
	{
		printf("\nTengo que hacer que splitee esa linea antes del salto de linea\n");
	}*/
	return (line); 
}

/*
char	*get_next_line(int fd)
{
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (0);
	
	return ("\n\nFIN");
}
*/
int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("miArchivoCorto", O_RDONLY);
	while (i < 1)
	{
		printf("%s", split_and_join_words(fd));  
		i++;
	}
	
	/**
	 * PRUEBASS
	*/
	/*
	char *line;
	line = "Hola";
	printf("%d\n", check_next_line(line));
	*/
}