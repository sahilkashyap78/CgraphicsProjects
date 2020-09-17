#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<cstring>
#include<iostream>
using namespace std;

int main()
{
int alphabets;


    int gDriver=DETECT,gMode;
    initgraph(&gDriver,&gMode," ");

//settextstyle(8,2,5);
settextstyle(8,3,5);
    outtextxy(400,600,"L");
    getch();
    closegraph();
}
