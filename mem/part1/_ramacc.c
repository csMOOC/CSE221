#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <rdtsc.h>
#include <string.h>


# define MINARRAYSIZE 9
# define MAXARRAYSIZE 27

int main(int argc, char* argv[]) {
    
	if(argc < 2) {
		printf ("usage : ./program 100\n");
		exit(0);
	}

	unsigned long long loops = atoi(argv[1]);
    
    int	**array;
    void **p;
    int	size, stride, i;
    
    for (stride = 1; stride < (2<<10); stride=stride*2) {
        
        //store arrays
        //double b[100];
        //int j = 0;
        
        for (size = MINARRAYSIZE; size <= MAXARRAYSIZE; size++)
        {
            if (!(array = malloc(1 << size)))
            {
                fprintf(stderr, "Malloc failure\n");
                exit(1);
            }
            for (i = 0; i + 1 < (1 << size) / (stride * sizeof(*array)); i++)
                array[i * stride] = (int *)(array + ((i + 1) * stride));
            array[i * stride] = (int *)array;
            p = (void **)array;
            
            unsigned long long start, end;
            
            start = rdtsc();
            for (i = 0; i < loops; ++i)
                p = *p;
            end = rdtsc();
            
            double res =  (double)(end - start) / (double)loops;
            //b[j++] = res;
            
            printf("stride %d and size %d = %f\n", stride, size, res);
            free(array);
        }
        
        //int jj = 0;
        //printf("[");
        //for(;jj < j;jj++)
            //printf("%f,", b[jj]);
        //printf("]\n");
    }
    
}
    
    
    
