/*
* server2.c - a simple network server program.
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
 
int main()
{
    int server_sockfd, client_sockfd;
    int server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    time_t curtime;
    struct tm *loc_time;
 
/*  Create an unnamed socket for the server.  */
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
 
/*  Name the socket.  */
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = 9734;
    server_len = sizeof(server_address);
    bind(server_sockfd, (struct sockaddr *)&server_address, server_len);
 
/*  Create a connection queue and wait for clients.  */
    listen(server_sockfd, 5);
    while(1) {
        char mensaje[50];
 
/*  Accept a connection.  */
        client_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd,
            (struct sockaddr *)&client_address, &client_len);
 
/*  We can now read/write to client on client_sockfd.  */
        read(client_sockfd, mensaje, 50);

        int addr1 = client_address.sin_addr.s_addr & 0xff;
        int addr2 = (client_address.sin_addr.s_addr >> 8) & 0xff;
        int addr3 = (client_address.sin_addr.s_addr >> 16) & 0xff;
        int addr4 = (client_address.sin_addr.s_addr >> 24) & 0xff;

        curtime = time (NULL);
        loc_time = localtime (&curtime);

        printf("%d.%d.%d.%d: \"%s\" %d/%d/%d a las %d:%d:%d\n", addr1, addr2, addr3, addr4, mensaje,
            loc_time->tm_mday, loc_time->tm_mon+1, loc_time->tm_year+1900, loc_time->tm_hour,
            loc_time->tm_min, loc_time->tm_sec);

        write(client_sockfd, "Recibido\0", 9);
        close(client_sockfd);
    }
}
