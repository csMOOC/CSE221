#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rdtsc.h"
#include <stdio.h>
#include <unistd.h>

int buffersize = 100*1024*1024;

size_t getFileSize(int fd) {
    struct stat buf;
    fstat(fd, &buf);
    return buf.st_size;
}

unsigned long long getReadTime(char* filename, size_t size) {
    unsigned long long start, end, diff;
    
    int fd = open(filename, O_RDONLY);
    char* buf = (char*)malloc(buffersize);
    int loops = size/buffersize;
    
    int r = 0;
    
    start = rdtsc();
    
    int i = 0;
    
    for(;i < loops;i++) {
        r = read(fd, buf, buffersize);
    }
    end = rdtsc();
    
    if(r < 0) perror("READ ERROR!\n");
    
    close(fd);
    
    diff = end - start;
    free(buf);
    return diff;
}

int main(int argc, char** argv) {
    char* filename;
    if (argc != 2) {
        printf("usage : ./program filename");
        exit(0);
    }
    
    filename = argv[1];
    
    int fd = open(filename, O_RDONLY);
    size_t size = getFileSize(fd);
    close(fd);
    
    unsigned long long time;
    
    int i = 0;
    for(;i < 10;i++) {
        time = getReadTime(filename, size);
        printf("%llu\n", time/(size/(1024)) );
    }
}
