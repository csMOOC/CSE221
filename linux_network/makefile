all: net
.PHONY:all

net : net1 net2

net1 : 
	gcc -I../include -o rtt_server.out ./part1/rtt_server.c;
	gcc -I../include -o rtt_client.out ./part1/rtt_client.c;

net2 : 
	gcc -I../include -o bandwidth_server.out ./part2/bandwidth_server.c;
	gcc -I../include -o bandwidth_client.out ./part2/bandwidth_client.c;

clean :
	rm *.out
