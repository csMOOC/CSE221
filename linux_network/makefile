all: net
.PHONY:all

net : net1

net1 : 
	gcc -I../include -o rtt_server.out ./part1/rtt_server.c;
	gcc -I../include -o rtt_client.out ./part1/rtt_client.c;

clean :
	rm *.out
