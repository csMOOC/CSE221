all: cpu
.PHONY:all

cpu : cpu1

cpu1 : 
	gcc -Iinclude -o cpu1.1.out cpu/part1/cpuread.c;mv cpu1.1.out build
	gcc -Iinclude -o cpu1.2.out cpu/part1/cpuiter.c;mv cpu1.2.out build




clean :
	rm ./build/*
