all: cpu mem fs
.PHONY:all

cpu : cpu1 cpu2 cpu3 cpu4 cpu5

mem : mem1 mem2 mem3

fs : fs1 fs2

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

mem2 : 
	gcc -Iinclude -o mem2.1.out mem/part2/rambandwith.c;mv mem2.1.out build

mem3 : 
	gcc -Iinclude -o mem3.1.out mem/part3/pagefault.c;mv mem3.1.out build

fs1 : 
	gcc -Iinclude -o fs1.1.out fs/part1/file_cache.c;mv fs1.1.out build

fs2 : 
	gcc -Iinclude -o fs2.1.out fs/part2/seq_read.c;mv fs2.1.out build
	gcc -Iinclude -o fs2.2.out fs/part2/ran_read.c;mv fs2.2.out build

clean :
	rm ./build/*.out
