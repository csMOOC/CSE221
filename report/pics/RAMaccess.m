clear all; close all; clc;

title('RAM access cycle')



x1=[10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26];
y1=[1.116605, 1.864342, 0.687838, 1.736381, 1.449469, 1.104032, 0.939144, 0.683588, 1.151352,2.170154,5.495250, 8.461017,20.772894,41.281862,51.474217,59.474217,57.635278];

h = plot(x1,y1,'o-','MarkerSize',2,'Color',[1 0 0])
set(h,'DisplayName','RAM access cycle');


xlabel('array size(log)')

ylabel('average cycle')

