#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libft/libft.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd)
{
	char *line;
	char buff[BUFFER_SIZE + 1];
	int i;
	char *aux;
	//static char *sobrante_despues_del_salto;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	read(fd, buff, BUFFER_SIZE);
	line = (char *)malloc((ft_strlen(buff) * sizeof(char)) + 1);
	while (!ft_strchr(buff, '\n') && *buff != '\0')
	{
		line = ft_strjoin(line, buff);
		read(fd, buff, BUFFER_SIZE);
	}
	aux = (char *)malloc((ft_strlen(buff) * sizeof(char)) + 1);
	while (buff[i] != '\n')
	{
		aux[i] = buff[i];
		i++;
	}
	//sobrante_despues_del_salto = 
	ft_substr(buff, i++, ft_strlen(buff)); //Ya me almacena el malloc!!!! Letsgoo
	line = ft_strjoin(line, aux);
	return (line);
}

int	main(void)
{
	int	fd;
	int	i;
	char *line;

	i = 1;
	fd = open("txt_files/file", O_RDONLY);
	while (i < 2)
	{
		line = get_next_line(fd);
		printf("Linea [%d]: %s\n", i, line);
		close (fd);
		i ++;
	}
	return (0);
}