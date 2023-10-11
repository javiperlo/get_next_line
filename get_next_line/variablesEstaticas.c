/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variablesEstaticas.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:09:25 by javperez          #+#    #+#             */
/*   Updated: 2023/10/11 20:21:02 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int	fd;
	char buf[256];
	int nr_bytes;
	
	nr_bytes = 0;
	printf("Nr_bytes --> %d\n", nr_bytes);
	fd = open("miArchivo", O_RDONLY);
	while ((nr_bytes = read(fd, buf, 5)))
	{
		buf[nr_bytes] = '\0';
		printf("buf --> %s\n", buf);
	}
	close(fd);
}