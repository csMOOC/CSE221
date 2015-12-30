
clear all; close all; clc;
title('read cycles per block')

x1=[3,4,5,6,7,8,9,10,11];
y1=[1060023,1037613,1155908,1127454,1134455,1105819,1085479,1089600,1074542];

h = plot(x1,y1,'o-','MarkerSize',2,'Color',[1 0 0])
set(h,'DisplayName','Sequential');
axis([3,11,800000,1400000]) % axis([xmin,xmax,ymin,ymax])

hold on
x2=[3,4,5,6,7,8,9,10,11];
y2=[1043427,1065662,1058558,1073499,1073262,1077349,1074041,1074543,1044684];

h2=plot(x2,y2,'o-','MarkerSize',2)
set(h2,'DisplayName','Random');

xlabel('File Size(log)')

ylabel('cycles')
