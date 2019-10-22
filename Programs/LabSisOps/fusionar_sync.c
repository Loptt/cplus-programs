#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>  /* open() */
#include <sys/stat.h>   /* open() */
#include <fcntl.h>      /* open() */
#include <unistd.h>     /* read() y write() , close() */

char buffer[BUFSIZ]; /*Buffer para manipular datos. */

int main(int argc, char *argv[])
{
    int fd_origen; int fd_destino; int nbytes;
    int i;

    /*Analisis de los argumentos de la linea de comandos*/
    if (argc != 4) {
        fprintf(stderr, "Forma de uso: %s origen destino \n", argv[0]);
        exit(-1);
    }

    /* Apertura o creacion de archivos en modo solo escritura. */
    /* Abrir en modo solo Lectura (O_WRONLY). */
    /* Si el archivo existe entonces truncar a cero bytes (O_TRUNC)*/
    /* El archivo es creado en caso de que no exista (O_CREAT). */
    /* El modo que se crea es 0666. */
    if ((fd_destino = open(argv[3], O_WRONLY | O_TRUNC | O_CREAT | O_SYNC, 0666)) == -1) {
        fprintf(stderr, "Error al crear el archivo de salida \n");
        perror(argv[3]);
        exit(-1);
    }

    for (int i = 1; i < 3; i++)
    {

        /*Apertura del archivo 1 en modo solo lectura (O_RDONLY). */
        if ((fd_origen = open(argv[i], O_RDONLY | O_SYNC)) == -1) {
            fprintf(stderr, "Error al abrir el archivo de entrada: %s ¥n", argv[1]);
            perror(argv[i]);
            exit(-1);
        }

        /* copiamos el archivo 1 en el archivo destino. */
        while ((nbytes = read(fd_origen, buffer, sizeof buffer)) > 0)
            write(fd_destino, buffer, nbytes);
        close(fd_origen);
    }

    close(fd_destino);
}
