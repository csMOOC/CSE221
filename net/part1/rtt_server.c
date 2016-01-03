#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h> 
#include <netinet/in.h>
#include <stdlib.h>

int main(int argc , char *argv[])
{
	if(argc != 2) {
		perror("usage : ./server port\n");
		return -1;
	}

	int loops = 1000;

	int port = atoi(argv[1]);

    int server_sock , client_sock , client_len;
    struct sockaddr_in server , client;
    
    client_len = sizeof(struct sockaddr_in);
    
	//Create socket
    server_sock = socket(AF_INET , SOCK_STREAM , 0);
    if (server_sock == -1) {
        printf("Error: fails to create socket");
		return -1;
	}
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( port );
     
    //Bind
    if(bind(server_sock,(struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("Error: fails to bind");
        return 1;
    }
     
    //Listen
    listen(server_sock , 3);
     
    //Accept incoming connection
    puts("Waiting   ...  \n");
    char msg;

    //accept connection from an incoming client
    while(1)
    {
    	client_sock = accept(server_sock, (struct sockaddr *)&client, (socklen_t*)&client_len);
    	
		if (client_sock < 0) {
            perror("Error: fails to accept");
            return -1;
    	}

		int j = 0;
        for (; j < loops; ++j) {
            recv(client_sock, &msg, 1, 0);
            send(client_sock, &msg, 1, 0);
        }
    }

    puts("Finish calculating \n");
     
    return 0;
}
