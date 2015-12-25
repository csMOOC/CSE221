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
    
    rdtsc();
    rdtsc();
    rdtsc();

    int stride = 1;
    
    for(;stride <= 8;stride++) {
        
        int arraysizestride = 9;
        
        for(;arraysizestride <= 24;arraysizestride++) {
        
            unsigned long long arraysize = 1 << arraysizestride;
            unsigned long long footlength = 1 << stride;
            
            int i = 0;
            unsigned long long total = 0;
            
            for(;i < loops;i++) {
                int *array = (int*)malloc(sizeof(int)*arraysize);
                memset(array, 0, sizeof(int)*arraysize);
                int j = 0;
                unsigned long long start, end ,diff;
                start = rdtsc();
                for(;j < arraysize;j += footlength) {
                    int k = array[j];
                }
                end = rdtsc();
                diff = end - start;
                total += diff;
                free(array);
            }
            
            printf ("RAM access time and average time(stride %d arraysize %d): %llu  %llu\n", stride, arraysizestride,total, total/(loops * (arraysize/footlength)));
        
        }
        
    }
    
    
    
    return 0;
    
}

