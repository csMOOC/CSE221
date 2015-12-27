clear all; close all; clc;

title('read cycles per MB')



x1=[3000,3100,3200,3300,3400,3500,3600,3700,3800,3900,4000];
y1=[610,614,598,622,1965,5498,5572,5503,5673,5657,5598];

h = plot(x1,y1,'o-','MarkerSize',2,'Color',[1 0 0])
set(h,'DisplayName','read cycles per MB');


xlabel('File Size(MB)')

ylabel('cycles')