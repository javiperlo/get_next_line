/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:54:01 by javperez          #+#    #+#             */
/*   Updated: 2023/10/26 12:24:22 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Esta función splitea la string devuelta de read_line() y solo
 * te saca hasta el salto de linea.
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char	*get_new_line(char *str)
{
	int		i;
	char	*cut_str;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	cut_str = (char *)malloc(sizeof(char) * (i + 2));
	if (!cut_str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		cut_str[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		cut_str[i] = str[i];
		i++;
	}
	cut_str[i] = '\0';
	return (cut_str);
}

/**
 * Esta función está retornando el valor sobrante de la linea en bruto
 * después del salto de línea.
*/

char	*new_line(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}

/*Esta función te pilla todo el texto almacenado en BUFFER_SIZE*/

char	*read_line(int fd, char *str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}
/*		GET_NEXT_LINE
		-------------
	Esta función va a devolver la línea a leer.
	Si se llama múltiples veces a la función,
	la función "memorizará" la posición anterior
	y leerá la siguiente.

	Declaramos una variable "line" -> Que va a ser
	la string que vamos a retornar.
	
	También declaramos una variable estática "str" 
	que se encargará de conservar la posición en la que
	se quedó anteriormente.

	En primer lugar verificamos que el diccionario a leer "fd"
	contenga algo. fd va a devolver un número mayor que 0 si 
	contiene contenido. Si no contiene devolverá -1. Por lo tanto,
	verificamos que si es < 1 y BUFFER_SIZE <= a 0, retorna NULL.

	A continuación asignamos a la variable estática, el valor bruto
	que se haya obtenido de la función read_line(fd).
	Verificamos que "str" contenga algo y de lo contrario, devolvemos
	NULL.

	Ahora almacenamos en la variable "line", **SOLO** hasta el \n
	para poder retornar el valor.

	Por último tenemos que actualizar la variable estática "str".
	Para ello utilizamos la función new_line(str), a la que le pasamos por
	argumento en la primera iteración el valor BRUTO obtenido de la función
	read_line. 

	Esta función va a iterar sobre la cadena y va a retornar el valor que hay
	después del salto de línea (\n).

	Entonces, cuando se vuelva a llamar a la función, "str", ya tendrá un valor
	estático. Que se añadirá con un ft_strjoin() al valor de str.
*/

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_line(fd, str);
	if (!str)
		return (NULL);
	line = get_new_line(str);
	str = new_line(str);
	return (line);
}
/*
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("txt_files/file", O_RDONLY); //Abrimos el diccionario
	i = 1;
	while (i < 5) //Aquí ponemos las lienas que queramos leer
	{
		line = get_next_line(fd1); //Almacenamos en "line", la 
		//variable almacenada de get_next_line(fd);
		printf("line [%02d]: %s", i, line); // Y la printeamos
		free(line); //Liberamos la memoria de "line", 
		//para poder almacenar otra cadena distinta.
		i++;
	}
	close(fd1); //Una vez hayamos terminado de leer las
	//lineas que queramos, cerramos el diccionario
	return (0);
}*/