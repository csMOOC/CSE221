#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "rdtsc.h"

int main(int argc , char *argv[])
{      
	if(argc != 4) {
		perror("usage : ./client ip port size \n");
		return -1;
	}

	int port = atoi(argv[2]);
    int size = atoi(argv[3]);

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

	if (connect(sockfd,(struct sockaddr *)&server,sizeof(server)) < 0) {
		perror("ERROR connecting");
		return -1;
	}

    // Computing round trip time
    char *msg = (char*)malloc(size);
    unsigned long long start,end,diff;

    start = rdtsc();
    recv(sockfd, &msg, size, MSG_WAITALL);
    end = rdtsc();
    diff = end - start;

    close(sockfd);

    printf ("PEAK bandwidth is : %f MB/s \n", (size/(1024*1.0*1024)) * (2.3e8 / diff) );
    
	return 0;
}
