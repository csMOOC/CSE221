#include "rdtsc.h"
#include "stdlib.h"
#include "stdio.h"

#pragma OPTIMIZE OFF

void __attribute__ ((noinline)) foo0() {}
void __attribute__ ((noinline)) foo1(int arg1) {}
void __attribute__ ((noinline)) foo2(int arg1, int arg2) {}
void __attribute__ ((noinline)) foo3(int arg1, int arg2, int arg3) {}
void __attribute__ ((noinline)) foo4(int arg1, int arg2, int arg3, int arg4) {}
void __attribute__ ((noinline)) foo5(int arg1, int arg2, int arg3, int arg4, int arg5) {}
void __attribute__ ((noinline)) foo6(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {}
void __attribute__ ((noinline)) foo7(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) {}

int loops;

void fun0() {
    int i = 0;
    unsigned long long total0 = 0;
    unsigned long long start, end;
    start = rdtsc();
    for(;i < loops;++i) {
        foo0();
    }
    end = rdtsc();
    total0 = end - start;
    printf("0 argument procedure call overhead is : %f cycles; Total : %llu \n", total0*1.0/loops, total0);
}

void fun1() {
    int i = 0;
    unsigned long long total0 = 0;
    unsigned long long start, end;
    volatile int a;
    start = rdtsc();
    for(;i < loops;++i) {
        foo1(a);
    }
    end = rdtsc();
    total0 = end - start;
    printf("1 argument procedure call overhead is : %f cycles; Total : %llu \n", total0*1.0/loops, total0);
}

void fun2() {
    int i = 0;
    unsigned long long total0 = 0;
    unsigned long long start, end;
    volatile int a,b;
    start = rdtsc();
    for(;i < loops;++i) {
        foo2(a,b);
    }
    end = rdtsc();
    total0 = end - start;
    printf("2 argument procedure call overhead is : %f cycles; Total : %llu \n", total0*1.0/loops, total0);
}

void fun3() {
    int i = 0;
    unsigned long long total0 = 0;
    unsigned long long start, end;
    volatile int a,b,c;
    start = rdtsc();
    for(;i < loops;++i) {
        foo3(a,b,c);
    }
    end = rdtsc();
    total0 = end - start;
    printf("3 argument procedure call overhead is : %f cycles; Total : %llu \n", total0*1.0/loops, total0);
}

void fun4() {
    int i = 0;
    unsigned long long total0 = 0;
    unsigned long long start, end;
    volatile int a,b,c,d;
    start = rdtsc();
    for(;i < loops;++i) {
        foo4(a,b,c,d);
    }
    end = rdtsc();
    total0 = end - start;
    printf("4 argument procedure call overhead is : %f cycles; Total : %llu \n", total0*1.0/loops, total0);
}

void fun5() {
    int i = 0;
    unsigned long long total0 = 0;
    unsigned long long start, end;
    volatile int a,b,c,d,e;
    start = rdtsc();
    for(;i < loops;++i) {
        foo5(a,b,c,d,e);
    }
    end = rdtsc();
    total0 = end - start;
    printf("5 argument procedure call overhead is : %f cycles; Total : %llu \n", total0*1.0/loops, total0);
}

void fun6() {
    int i = 0;
    unsigned long long total0 = 0;
    unsigned long long start, end;
    volatile int a,b,c,d,e,f;
    start = rdtsc();
    for(;i < loops;++i) {
        foo6(a,b,c,d,e,f);
    }
    end = rdtsc();
    total0 = end - start;
    printf("6 argument procedure call overhead is : %f cycles; Total : %llu \n", total0*1.0/loops, total0);
}


void fun7() {
    int i = 0;
    unsigned long long total0 = 0;
    unsigned long long start, end;
    volatile int a,b,c,d,e,f,g;
    start = rdtsc();
    for(;i < loops;++i) {
        foo7(a,b,c,d,e,f,g);
    }
    end = rdtsc();
    total0 = end - start;
    printf("7 argument procedure call overhead is : %f cycles; Total : %llu \n", total0*1.0/loops, total0);
}

int main(int argc, char **argv) {
    
    if(argc < 2) {
        printf("usage : ./program 1000000");
        exit(0);
    }
    
    loops = atoi(argv[1]);

    fun0();
    fun1();
    fun2();
    fun3();
    fun4();
    fun5();
    fun6();
    fun7();

    return 0;
}
