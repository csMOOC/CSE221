#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <rdtsc.h>
#include <pthread.h>

int pipefd[2];

void *func(void *tid) {
    unsigned long long end;
    end = rdtsc();
    write(pipefd[1], &end, sizeof(end));
    pthread_exit(NULL);
}

int
main(int argc, char * argv[])
{
    if(argc < 2) {
        printf("usage : ./program 100");
        exit(0);
    }
    
    int loops = atoi(argv[1]);
    
    int i = 0;
    unsigned long long total = 0;
    
    pipe(pipefd);
    
    for(;i < loops;i++) {
        
        long l;
        pthread_t thread;
        pthread_create(&thread, NULL, func, (void *)l);
        
        unsigned long long start, end, diff;
        start = rdtsc();
        read(pipefd[0], &end, sizeof(end));
        diff = end - start;
        total += diff;
        
        pthread_join(thread, NULL);
    }
    
    
    printf("thread context switch : %llu cycles; Total : %llu \n", total/loops, total);
    return 0;
}