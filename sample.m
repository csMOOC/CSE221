clear all; close all; clc;

title('binary multiplication')



x1=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16];
y1=[0.002,0.002,0.002,0.002,0.002,0.002,0.002,0.002,0.003,0.007,0.021,0.074,0.271,1.07,4.297,17.063];

h = plot(x1,y1,'o-','MarkerSize',2,'Color',[1 0 0])
set(h,'DisplayName','Brute Force');
hold on
x2=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16];
y2=[0.002,0.002,0.002,0.002,0.002,0.003,0.005,0.011,0.025,0.079,0.219,0.653,1.801,5.643,18.160,51.328];

h2=plot(x2,y2,'o-','MarkerSize',2)
set(h2,'DisplayName','Karatsuba');

xlabel('n')

ylabel('running time(s)')

