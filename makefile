all: cpu mem fs net
.PHONY:all

cpu : cpu1 cpu2 cpu3 cpu4 cpu5

mem : mem1 mem2 mem3

fs : fs1 fs2 fs3 fs4

net : net1 net2 net3

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
	gcc -Iinclude -o mem1.1.out mem/part1/_ramacc.c;mv mem1.1.out build

mem2 : 
	gcc -Iinclude -o mem2.1.out mem/part2/rambandwith.c;mv mem2.1.out build

mem3 : 
	gcc -Iinclude -o mem3.1.out mem/part3/pagefault.c;mv mem3.1.out build

net1 : 
	gcc -Iinclude -o rtt_server.out net/part1/rtt_server.c;mv rtt_server.out build
	gcc -Iinclude -o rtt_client.out net/part1/rtt_client.c;mv rtt_client.out build

net2 : 
	gcc -Iinclude -o bandwidth_server.out net/part2/bandwidth_server.c;mv bandwidth_server.out build
	gcc -Iinclude -o bandwidth_client.out net/part2/bandwidth_client.c;mv bandwidth_client.out build

net3 : 
	gcc -Iinclude -o conn_server.out net/part3/conn_server.c;mv conn_server.out build
	gcc -Iinclude -o conn_client.out net/part3/conn_client.c;mv conn_client.out build

fs1 : 
	gcc -Iinclude -o fs1.1.out fs/part1/file_cache.c;mv fs1.1.out build

fs2 : 
	gcc -Iinclude -o fs2.1.out fs/part2/seq_read.c;mv fs2.1.out build
	gcc -Iinclude -o fs2.2.out fs/part2/ran_read.c;mv fs2.2.out build

fs3 : 
	gcc -Iinclude -o fs3.1.out fs/part3/seq_read.c;mv fs3.1.out build
	gcc -Iinclude -o fs3.2.out fs/part3/ran_read.c;mv fs3.2.out build

fs4 : 
	gcc -Iinclude -o fs4.1.out fs/part4/contension.c;mv fs4.1.out build

clean :
	rm ./build/*.out
