all: net
.PHONY:all

net : net1 net2 net3

net1 : 
	gcc -I../include -o rtt_server.out ./part1/rtt_server.c;
	gcc -I../include -o rtt_client.out ./part1/rtt_client.c;

net2 : 
	gcc -I../include -o bandwidth_server.out ./part2/bandwidth_server.c;
	gcc -I../include -o bandwidth_client.out ./part2/bandwidth_client.c;

net3 : 
	gcc -I../include -o conn_server.out ./part3/conn_server.c;
	gcc -I../include -o conn_client.out ./part3/conn_client.c;

clean :
	rm *.out
