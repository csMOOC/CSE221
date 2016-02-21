#include "rdtsc.h"
#include "stdlib.h"
#include "stdio.h"
#include <sys/types.h>
#include <unistd.h>

/*
int main(int argc, char **argv) {
    
    if(argc < 2) {
        printf("usage : ./program 1000000");
        exit(0);
    }
    
    int loops = atoi(argv[1]);

    int i = 0;
    unsigned long long total = 0;
    unsigned long long start, end;
    start = rdtsc();
    for(;i < loops;++i) {
        getppid();
    }
    end = rdtsc();
    total = end - start;
    printf("System call overhead is : %llu cycles; Total : %llu \n", total/loops, total);

    return 0;
}
*/

int main(int argc, char **argv) {
    
    if(argc < 2) {
        printf("usage : ./program 1000");
        exit(0);
    }
    
    int loops = atoi(argv[1]);
    unsigned long long total = 0;
    unsigned long long start, end;
    
    int i = 0;
    
    for (; i < loops; i++) {
        
        pid_t pid = fork();
        
        if (pid == -1) {
            printf("fork failed!\n");
            exit(-1);
        }
        
        if (pid == 0) {
            start = rdtsc();
            getpid();
            end = rdtsc();
            printf("System call overhead is : %llu cycles;\n", end - start);

            return 0;
        } else {
            wait(NULL);
        }
    }
    
    return 0;
}

