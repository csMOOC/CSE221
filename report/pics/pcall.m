clear all; close all; clc;

title('procedure call overhead')



x1=[0,1,2,3,4,5,6,7];
y1=[2.1, 2.3, 2.7, 3.6, 4.3, 5.0, 5.9, 8.1];

h = plot(x1,y1,'o-','MarkerSize',2,'Color',[1 0 0])
set(h,'DisplayName','procedure call overhead');


xlabel('num of args')

ylabel('cycles')
