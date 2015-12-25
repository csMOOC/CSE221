all: cpu mem
.PHONY:all

cpu : cpu1 cpu2 cpu3 cpu4 cpu5

mem : mem1

cpu1 : 
	gcc -Iinclude -o cpu1.1.out cpu/part1/cpuread.c;mv cpu1.1.out build
	gcc -Iinclude -o cpu1.2.out cpu/part1/cpuiter.c;mv cpu1.2.out build

cpu2 : 
	gcc -Iinclude -o cpu2.1.out cpu/part2/procedure_call.c;mv cpu2.1.out build

cpu3 : 
	gcc -Iinclude -o cpu3.1.out cpu/part3/system_call.c;mv cpu3.1.out build

cpu4 : 
	gcc -Iinclude -o cpu4.1.out cpu/part4/process.c;mv cpu4.1.out build
	gcc -Iinclude -o cpu4.2.out cpu/part4/thread.c;mv cpu4.2.out build

cpu5 : 
	gcc -Iinclude -o cpu5.1.out cpu/part5/process_cs.c;mv cpu5.1.out build
	gcc -Iinclude -o cpu5.2.out cpu/part5/thread_cs.c;mv cpu5.2.out build

mem1 : 
	gcc -Iinclude -o mem1.1.out mem/part1/ramacc.c;mv mem1.1.out build

clean :
	rm ./build/*
