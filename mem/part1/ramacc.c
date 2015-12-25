#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <rdtsc.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[]) {

    unsigned long long start, end;
    srand(time(NULL));

    int size = 6;
    unsigned long long loops = 1000000;
    
    for(;size < 27;size++) {
        
        unsigned long long arraysize = 1 << size;
        
        int i = 0;
        unsigned long long start, end, diff;
        unsigned long long total = 0;
        char *array = (char*)malloc( sizeof(char) * arraysize);
        memset(array,'a',arraysize);
        
        start = rdtsc();
        for(;i < loops;i++) {
            
            int pos = rand() % arraysize;
            
            char ch = array[pos];
        }
        end = rdtsc();
        
        total += (end - start);
        
        free(array);
        
        
        printf("array size : %d, RAM access cycle : %f\n", size, (total*1.0)/loops);
        
        //sleep(1);
    }
    
    
    
    return 0;
    
}

