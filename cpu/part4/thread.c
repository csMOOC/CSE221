#include "rdtsc.h"
#include "stdlib.h"
#include "stdio.h"
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>

void *func(void *tid) {pthread_exit(NULL);}

int main(int argc, char **argv) {
    
    if(argc < 2) {
        printf("usage : ./program 1000");
        exit(0);
    }
    
    int loops = atoi(argv[1]);
    unsigned long long total = 0;
    
    int i = 0;

    for (; i < loops; i++) {
        unsigned long long start, end;
        
        long p;
        pthread_t thread;
        start = rdtsc();
        pthread_create(&thread, NULL, func, (void *)p);
        end = rdtsc();
        total += (end - start);
        
        pthread_join(thread, NULL);
    }


    printf("pthread task creation : %llu cycles; Total : %llu \n", total/loops, total);

    return 0;
}
