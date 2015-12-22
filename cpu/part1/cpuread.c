#include <stdio.h>
#include <stdlib.h>
#include "rdtsc.h"

int main(int argc, char* argv[]) {
	
	if(argc < 2) {
		printf("usage : ./program 1000000\n");
		exit(0);
	}

	int loops = atoi(argv[1]);

	unsigned long long total = 0;

	int i = 0;
	for (; i < loops; i++) {
		unsigned long long start, end;
		start = rdtsc();
		end = rdtsc();
		total += (end - start);
	}

	printf("CPU reading rdtsc average time :%llu  %llu\n", total, total/loops);
}
