#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rdtsc.h"
#include <time.h>

blksize_t getBlockSize(int fd) {
    struct stat buf;
    fstat(fd, &buf);
    return buf.st_blksize;
}

size_t getFileSize(int fd) {
    struct stat buf;
    fstat(fd, &buf);
    return buf.st_size;
}

int main(int argc, char* argv[]) {
    char* filename;
    int loops = 100;
    if (argc != 2) {
        perror("usage : ./program filename \n");
        exit(0);
    }
    
    filename = argv[1];
    srand(time(NULL));
    int nBlocks;
    
    unsigned long long start, end, total;
    total = 0;
    
    int i = 0;
    
    for (;i < loops; i++) {
        
        int fd = open(filename, O_RDONLY);
        fcntl(fd, F_NOCACHE, 1);
        
        size_t size = getFileSize(fd);
        blksize_t blockSize = getBlockSize(fd);
        nBlocks = size/blockSize;
        
        char* buf = (char*)malloc(size);
        int j = 0;
        for(;j < nBlocks;j++) {
            int pos = rand() % nBlocks;
            int offset = pos*blockSize;
            start = rdtsc();
            pread(fd, buf, blockSize, offset);
            end = rdtsc();
            total += (end - start);
        }
        
        close(fd);
        free(buf);
    }
    
    printf("Cycles per block : %llu\n", total/(loops*nBlocks));
}