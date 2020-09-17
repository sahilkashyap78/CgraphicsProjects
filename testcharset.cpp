#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<iostream>
#include <unordered_map>
#include<set>
using namespace std;

int main()
{

//char c[2]="2";
//int i =c[0]-'0';
int gdriver=DETECT,gmode;

initgraph(&gdriver,&gmode,"");

char c=2+'0';
char *d =&c;
//char d[2]=c;
settextstyle(1,0,5);
outtextxy(50,50,d);


getch();
closegraph();



}
