/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:35:01 by javperez          #+#    #+#             */
/*   Updated: 2023/10/15 19:43:31 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

/**
 * Función que pille una string
 * y que vaya haciendo strjoins de bloques
 * en bloques de BUFFER_SIZE
*/

char *check_new_line(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (str);
		i++;
	}
	return (NULL);
}

int	main(void)
{
	char *str = "Hola que\ntal";

	printf("%s\n", check_new_line(str));
}