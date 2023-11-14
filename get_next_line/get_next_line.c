/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:54:01 by javperez          #+#    #+#             */
/*   Updated: 2023/11/14 21:56:21 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * get_new_line - Extracts a line from the beginning of the provided string.
 *
 * This function takes a string as input and extracts the content from the beginning
 * until the first newline character '\n' or the end of the string is encountered.
 * It allocates memory for the extracted line and returns it as a new string.
 *
 * @param str - The string from which to extract the line
 * @return On success, the function returns the extracted line as a new string,
 *         including the newline character. If there's no newline character
 *         or in case of memory allocation failure, it returns NULL.
 */

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
 * new_line - Extracts the remainder of a string after the first newline character.
 *
 * This function takes a string and extracts the content after the first newline character.
 * It allocates memory for the extracted content and returns it as a new string.
 *
 * @param left_str - The string from which to extract the content after the first newline
 * @return On success, the function returns the content after the first newline character as a new string.
 *         If there's no newline character or in case of memory allocation failure, it returns NULL.
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
/**
 * read_line - Reads from a file descriptor and appends the content to the given string.
 *
 * This function reads from the specified file descriptor in chunks of BUFFER_SIZE,
 * appending the read content to the provided string until a newline character is encountered
 * or the end of the file is reached.
 *
 * @param fd - The file descriptor to read from
 * @param str - The string to which the read content will be appended
 * @return On success, the function returns the updated string with appended content.
 *         If an error occurs or the end of the file is reached, it returns NULL.
 */

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
			free (str);
			free (buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}
/**
 * get_next_line - Reads and returns the next line from a file descriptor.
 *
 * This function reads the content of the 
 * file descriptor passed as an argument,
 * returning a line each time it is called,
 * until the end of the file is reached.
 *
 * @param fd - The file descriptor to read from
 * @return On success, the function returns the 
 * 		   next line read from the file descriptor.
 *         When the end of the file is reached or in
 * 		   case of errors, it returns NULL.
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

	fd1 = open("txt_files/file1", O_RDONLY); //Abrimos el diccionario
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
