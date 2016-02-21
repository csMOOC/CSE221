#include "rdtsc.h"
#include "stdlib.h"
#include "stdio.h"
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
    
    if(argc < 2) {
        printf("usage : ./program 1000");
        exit(0);
    }
    
    unsigned long long overhead = 133221;
    
    int loops = atoi(argv[1]);
    unsigned long long total = 0;
    unsigned long long start, end;
    
    int i = 0;
    
    for (; i < loops; i++) {
        
        start = rdtsc();
        pid_t pid = fork();
        
        if (pid == -1) {
            printf("fork failed!\n");
            exit(-1);
        }
        
        if (pid == 0) {
            exit(-1);
        } else {
            wait(NULL);
            end = rdtsc();
            unsigned long long diff = end - start;
            total += (diff - 2*overhead);
        }
    }

    printf("fork task creation : %llu cycles; Total : %llu \n", total/loops, total);

    return 0;
}
