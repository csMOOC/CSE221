#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "rdtsc.h"

int main(int argc , char *argv[])
{      
	if(argc != 3) {
		perror("usage : ./client ip port \n");
		return -1;
	}

	int port = atoi(argv[2]);

    struct sockaddr_in server;
    server.sin_addr.s_addr =inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons( port );
    int sockfd;
    
    // Create socket
    sockfd = socket(AF_INET , SOCK_STREAM , 0);
    if (sockfd == -1) {
        perror("Error: fails to create socket");
		return -1;
	}
    
    unsigned long long start,end,diff;
    
    start = rdtsc();

	if (connect(sockfd,(struct sockaddr *)&server,sizeof(server)) < 0) {
		perror("ERROR connecting");
		return -1;
	}

    end = rdtsc();
    
    diff = end - start;
    
    printf ("connection establish cycle is : %llu\n", diff);
    
    // start = rdtsc();

    // close(sockfd);
    
    // end = rdtsc();
    
    // diff = end - start;

    // printf ("connection down cycle is : %llu\n", diff);
    
	return 0;
}
