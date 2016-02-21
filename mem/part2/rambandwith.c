#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "rdtsc.h"


int main(int argc, char* argv[]) {
    
    int input = 32; //32MB
    long long size = input * 1024 * 1024;
    long long *array = (long long*) malloc (size*sizeof(long long));
    memset (array, '1', size*8);
    
    unsigned long long total_read_time = 0;
    unsigned long long total_write_time = 0;
    unsigned long long start, end;
    long long halfsize = size/2;
    
    
    int loops = 1;
    int j = 0;
    
/*********************************************************************/
    
    int i = 0;
    
    start = rdtsc();

    for(;i < loops;i++) {
        int j = 0;
        for(;j < halfsize;j += 8) {
            char k1 = array[j];
            char k2 = array[j+halfsize];
            char k3 = array[j+1];
            char k4 = array[j+halfsize+1];
            char k5 = array[j+2];
            char k6 = array[j+halfsize+2];
            char k7 = array[j+3];
            char k8 = array[j+halfsize+3];
            char k9 = array[j+4];
            char k10 = array[j+halfsize+4];
            char k11 = array[j+5];
            char k12 = array[j+halfsize+5];
            char k13 = array[j+6];
            char k14 = array[j+halfsize+6];
            char k15 = array[j+7];
            char k16 = array[j+halfsize+7];
        }
    }
    
    end = rdtsc();
    total_read_time = end - start;

    printf ("RAM read bandwidth = %f MB/s\n", 8*loops*input/((double)(total_read_time) / 2.3e9));
  
/*********************************************************************/
    
    i = 0;
    
    start = rdtsc();
    
    for(;i < loops;i++) {
        int j = 0;
        for(;j < halfsize;j += 8) {
            array[j] = 1;
            array[j+halfsize] = 2;
            array[j+1] = 1;
            array[j+halfsize+1] = 2;
            array[j+2] = 1;
            array[j+halfsize+2] = 2;
            array[j+3] = 1;
            array[j+halfsize+3] = 2;
            array[j+4] = 1;
            array[j+halfsize+4] = 2;
            array[j+5] = 1;
            array[j+halfsize+5] = 2;
            array[j+6] = 1;
            array[j+halfsize+6] = 2;
            array[j+7] = 1;
            array[j+halfsize+7] = 2;
        }
    }
    
    end = rdtsc();
    total_write_time = end - start;
    
    printf ("RAM write bandwidth = %f MB/s\n", 8*loops*input/((double)(total_write_time) / 2.3e9));

/*********************************************************************/
    
    free (array);

    return 0;
}