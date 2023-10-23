/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:24:54 by javperez          #+#    #+#             */
/*   Updated: 2023/10/21 14:18:15 by javperez         ###   ########.fr       */
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
	while (buff[i] != '\0')
	{
		if(buff[i] == '\n')
			return (1);
		i ++;
	}
	return (0);
}
char *split_and_join_words(int fd)
{
	ssize_t nr_bytes;
	char buff[BUFFER_SIZE];
	int i = 0;
	char *new_block;
	char *line;

	if (fd == -1)
		return (NULL);
	nr_bytes = read(fd, buff, BUFFER_SIZE);
	//printf("Se van a imprimir %ld bytes, y el buffer es: \n%s\n", nr_bytes,buff);
	new_block = ft_substr(buff, i, i + nr_bytes); //Cogemos en cada iteración, desde i hasta i + nr_bytes
	line = (char *)malloc((ft_strlen(new_block) * sizeof(char)) + 1); // Reserva espacio en memoria para cada grupo de palabras
	if (!line)
		return (NULL);
	i += nr_bytes; //E iteramos de nuevo para quedarnos con el siguiente trozo de BUFFER_SIZE
	check_next_line(new_block);
	return (line); 
}

int	main(void)
{
	int	fd;
	int	i;
	char *line;

	i = 0;
	fd = open("txt_files/miArchivoCorto", O_RDONLY);
	while (i < 1) //Implementar un while para que lea las lineas que queramos, en este caso: 1
	{
		line = split_and_join_words(fd);
		printf("Linea %d: %s\n", i, line);
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