/*
* client2.c - a simple network client program.
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
 
int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Forma de uso: %s caracter \n", argv[0]);
        exit(-1);
    }
    int sockfd;
    int len;
    struct sockaddr_in address;
    int result;
    char mensaje[50];
    
    strcpy(mensaje, argv[1]);
 
/*  Create a socket for the client.  */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
 
/*  Name the socket, as agreed with the server.  */
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = 9734;
    len = sizeof(address);
 
/*  Now connect our socket to the server's socket.  */
    result = connect(sockfd, (struct sockaddr *)&address, len);
 
    if(result == -1) {
        perror("oops: client2");
        exit(1);
    }

    char respuesta[20];
 
/*  We can now read/write via sockfd.  */
    write(sockfd, mensaje, 50);
    read(sockfd, respuesta, 20);
    printf("Servidor: %s\n", respuesta);
    close(sockfd);
    return 0;
}
