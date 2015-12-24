all: cpu
.PHONY:all

cpu : cpu1 cpu2 cpu3

cpu1 : 
	gcc -Iinclude -o cpu1.1.out cpu/part1/cpuread.c;mv cpu1.1.out build
	gcc -Iinclude -o cpu1.2.out cpu/part1/cpuiter.c;mv cpu1.2.out build

cpu2 : 
	gcc -Iinclude -o cpu2.1.out cpu/part2/procedure_call.c;mv cpu2.1.out build

cpu3 : 
	gcc -Iinclude -o cpu3.1.out cpu/part3/system_call.c;mv cpu3.1.out build


clean :
	rm ./build/*
