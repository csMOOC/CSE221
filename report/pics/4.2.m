
clear all; close all; clc;
title('read cycles per block')

x1=[2,3,4,5,6,7,8,9,10,11];
y1=[401481,475677,501356,670260,489722,397495,293712,300106,281106,287629];

h = plot(x1,y1,'o-','MarkerSize',2,'Color',[1 0 0])
set(h,'DisplayName','Sequential');
axis([2,11,0,1000000]) % axis([xmin,xmax,ymin,ymax])

hold on
x2=[2,3,4,5,6,7,8,9,10,11];
y2=[420067,393597,502322,405538,425528,426442,504624,492654,430804,426658];

h2=plot(x2,y2,'o-','MarkerSize',2)
set(h2,'DisplayName','Random');

xlabel('File Size(log)')

ylabel('cycles')
