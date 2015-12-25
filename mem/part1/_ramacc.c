#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <rdtsc.h>
#include <string.h>


int main(int argc, char* argv[]) {
    
	if(argc < 2) {
		printf ("usage : ./program 100\n");
		exit(0);
	}

	unsigned long long loops = atoi(argv[1]);
    unsigned long long start, end;
    loops = 1000000;
    
    rdtsc();
    rdtsc();
    rdtsc();

    int stride = 1;
    
    for(;stride <= 12;stride++) {
        
        int arraysizestride = 13;
        
        for(;arraysizestride <= 24;arraysizestride++) {
        
            unsigned long long arraysize = 1 << arraysizestride;
            unsigned long long footlength = 1 << stride;
            
            int i = 0;
            unsigned long long total = 0;
            char *array = (char*)malloc(sizeof(char)*arraysize);
            memset(array, 0, arraysize);
            int pos = 0;
            
            unsigned long long start,end,diff;
            
            start = rdtsc();
            
            for(;i < loops;i++) {
                
                int k = array[pos];
                
                pos = (pos+footlength)%arraysize;
                
            }
            end = rdtsc();
            
            total += (end - start);
            free(array);
            
            printf ("RAM access time and average time(stride %d arraysize %d): %llu  %llu\n", stride, arraysizestride,total, total/loops);
        
        }
        
    }
    
    
    
    return 0;
    
}

