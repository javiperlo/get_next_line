#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"
#include <stdlib.h>

int check_next_line(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		if (str[i] == '\n')
			return (0);
		else
			return (1);
	return (1);
}

void miFuncion() {
    // Declarar una variable de tipo string estática
    static char miString[256] = "Hola, mundo!";
	
	char *otraString = " Adios Mundo!";
    printf("Contenido del string: %s\n", miString);
	sleep(1);
	printf("Comprobando que la string no tenga un \\n\n");
	sleep(1);
	printf("En el caso de no tenerlo, se hará un strjoin a la cadena miString\n");
	sleep(1);
	printf("\n");
	sleep (1);

	if (check_next_line(miString) == 1)
	{
		printf("No hay Salto de linea en esta string, añado otra: \n\n");
		printf("Este es el resultado: \n");
		sleep(1);
		printf("%s\n", ft_strjoin(miString, otraString));
	}
	else
		printf("Se ha detectado un salto de linea.\n");
	
    // Modificar la variable en cada llamada
    //strcat(miString, " Esto ha sido modificado.");
}

int main() {
    miFuncion();  // Llama a la función por primera vez
    //miFuncion();  // Llama a la función por segunda vez

    return 0;
}
