#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#ifndef BUFFER
# define BUFFER 6
#endif

#define JUMP  "\033[31m\\n\033[0m"
#define begin "\033[32m[\033[0m"
#define end "\033[32m] \033[0m"

void write_buffer(char *str)
{
    int i = 0;
    write(1, begin, strlen(begin));
    while (str[i])
    {
        if (str[i] == '\n')
             write(1, JUMP, strlen(JUMP));
        else
            write(1, &str[i], 1);
        i++;
    }
    write(1, end, strlen(end));
}

int main(void)
{
    int fd = open("txt_files/miArchivoCorto",  O_RDONLY);
    char buffer[BUFFER + 1];

    while (!strchr(buffer, '\n')) //Mientras que no se encuentre el \n dentro de la string.
    {
        read(fd, &buffer, BUFFER); 
		/* lee hasta BUFFER bytes del archivo referenciado por el descriptor de archivo 'fd'
		y almacena esos datos en el búfer llamado 'buffer'*/
        write_buffer(buffer); //Escribe el buffer
    }
    return (0);
}