#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>


 main()
{


initwindow(800,800);
printf("Enter the dots to be printed randomly:  \n");
int dots=0;
scanf("%d",&dots); //taking dots sum from the user
int index=0;

for(index;index<dots;index++)
{
int randx=rand()%700;//used for randomly taking x pixel upto 700
int randy=rand()%700;//used for randomly taking x pixel upto 700
line(randx,randy,randx,randy);//line is conerted into point by taking same x and y pixels



}




getch();

}
