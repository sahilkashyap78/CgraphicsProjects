#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<windows.h>


int main()

{
    int gDrive=DETECT,gMode;
    initgraph(&gDrive,&gMode,"C://TURBOC3//BGI");


    line(600,100,600,600);
    line(800,100,800,600);
    line(400,250,1000,250);
    line(400,400,1000,400);


getch();
closegraph();



}
