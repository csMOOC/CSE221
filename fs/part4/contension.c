#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rdtsc.h"

int fileindex = 0;

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

int *proc_create(int n) {
    int *childs = malloc(sizeof *childs * n);
    
    //printf("The parent process id: %d\n", getpid());
    for (int i = 0; i < n; i++) {
        int pid = fork();
        if (pid < 0) {
            perror("Fork Failed!");
            exit(1);
        } else if (pid == 0) {
            return NULL;
        } else {
            childs[i] = pid;
            fileindex = i+1;
            //printf("The child process ID is: %d\n", pid);
        }
    }
    
    return childs;
}

int main(int argc, char* argv[]) {
    
    if(argc < 2) {
        perror("usage : ./program 9\n The argument is in[0,14] \n");
        exit(0);
    }
    
    int nProcess = atoi(argv[1]);
    
    char* filenames[15];
    
    int loops = 100;
    
    filenames[0] = "./data/contension1.dat";
    filenames[1] = "./data/contension2.dat";
    filenames[2] = "./data/contension3.dat";
    filenames[3] = "./data/contension4.dat";
    filenames[4] = "./data/contension5.dat";
    filenames[5] = "./data/contension6.dat";
    filenames[6] = "./data/contension7.dat";
    filenames[7] = "./data/contension8.dat";
    filenames[8] = "./data/contension9.dat";
    filenames[9] = "./data/contension10.dat";
    filenames[10] = "./data/contension11.dat";
    filenames[11] = "./data/contension12.dat";
    filenames[12] = "./data/contension13.dat";
    filenames[13] = "./data/contension14.dat";
    filenames[14] = "./data/contension15.dat";

    
    int *childs = proc_create(nProcess);
    
    
    
    int nBlocks;
    
    unsigned long long start, end, total;
    
    total = 0;
    
    int i = 0;
    
    for (;i < loops; i++) {
        
        int fd = open(filenames[fileindex], O_RDONLY);
        fcntl(fd, F_NOCACHE, 1);
        
        size_t size = getFileSize(fd);
        blksize_t blockSize = getBlockSize(fd);
        nBlocks = size/blockSize;
        
        char* buf = (char*)malloc(size);
        
        int j = 0;
        
        start = rdtsc();
        for(;j < nBlocks;j++) {
            read(fd, buf, blockSize);
        }
        end = rdtsc();
        total += end - start;
        
        close(fd);
        free(buf);
    }
    
    printf("Cycles per block : %llu\n", total/(loops*nBlocks));
    
    return 0;
    
}
