
clear all; close all; clc;
title('average cycles per process')

x1=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15];
y1=[229003,253880,209028,240578,432147,438801,459831,415745,474147,491004,515341,515871,536629,568728,590147];

h = plot(x1,y1,'o-','MarkerSize',2,'Color',[1 0 0])
axis([1,15,0,800000]) % axis([xmin,xmax,ymin,ymax])


xlabel('number of processes')

ylabel('cycles')
