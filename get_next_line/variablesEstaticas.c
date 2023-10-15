/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variablesEstaticas.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:09:25 by javperez          #+#    #+#             */
/*   Updated: 2023/10/15 20:34:04 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

char *get_next_line(int fd) {
    static char buffer[BUFFER_SIZE];
    static int position = 0;
    static int bytes_read = 0;
    char *line = NULL;
    int line_length = 0;

    while (1) {
        if (position >= bytes_read) {
            // Si hemos leído todos los datos en el búfer, leemos más datos.
            bytes_read = read(fd, buffer, BUFFER_SIZE);
            position = 0;

            if (bytes_read <= 0) {
                // Fin del archivo o error.
                if (line_length > 0) {
                    // Si hemos leído algo antes de llegar al final del archivo, devolvemos la línea.
                    return line;
                } else {
                    // No se ha leído nada o se ha producido un error, así que retornamos NULL.
                    return NULL;
                }
            }
        }

        // Buscamos un carácter de nueva línea en el búfer.
        char current_char = buffer[position++];
        if (current_char == '\n') {
            // Hemos encontrado una nueva línea, así que terminamos la línea y la devolvemos.
            if (line == NULL) {
                line = (char *)malloc(line_length + 1);
            } else {
                line = (char *)realloc(line, line_length + 1);
            }
            line[line_length] = '\0';
            return line;
        } else {
            // Agregamos el carácter al resultado parcial.
            if (line == NULL) {
                line = (char *)malloc(line_length + 1);
            } else {
                line = (char *)realloc(line, line_length + 1);
            }
            line[line_length++] = current_char;
        }
    }
}

int main() {
    int fd = open("miArchivoCorto", O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }

    char *line;
    int lines_printed = 0;

    while (lines_printed < 3 && (line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);
        free(line);
        lines_printed++;
    }

    close(fd);
    return 0;
}