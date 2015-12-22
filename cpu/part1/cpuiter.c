#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <rdtsc.h>


int main(int argc, char* argv[]) {
    
	if(argc < 2) {
		printf ("usage : ./program 1000000\n");
		exit(0);
	}

	int loops = atoi(argv[1]);
    unsigned long long start, end;
    start = rdtsc();
    volatile int i;
    for (i = 0; i < loops; ++i) {}
    end = rdtsc();
	unsigned long long total = end - start;
    printf ("CPU iteration total time and average time: %llu  %llu\n", total, total/loops);
}

