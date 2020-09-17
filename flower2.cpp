#include<stdio.h>
#include<conio.h>
#include<graphics.h>









int main()
{
int gdriver = DETECT,gmode;
 int x,y;
initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
 setcolor(YELLOW);

int width =GetSystemMetrics(SM_CXSCREEN);
int height =GetSystemMetrics(SM_CYSCREEN);
 //PETAL 1 IS COMBINATION OF ARC 180TO360 AND 270 TO 90
 setfillstyle(SOLID_FILL,YELLOW);
 arc(200,130,180,360,100);
  arc(100,230,270,90,100);
 x=(200+100)/2;
 y=(130+230)/2;
floodfill(x,y,YELLOW);
 //petal 2 180to360 and 90 to 270 combinatio
  arc(200,130,180,360,100);
   arc(300,230,90,270,100);
  x=(200+300)/2;
 y=(130+230)/2;
floodfill(x,y,YELLOW);

//petal 3 combination of arcs 0 to 180 AND 270 TO 90


 arc(200,330,0,180,100);
 arc(100,230,270,90,100);
 x=(200+100)/2;
 y=(330+230)/2;
floodfill(x,y,YELLOW);

//PETEAL 4 IS COMBINATION OFARC 0 TO 180 AND 90 TO 270
 arc(200,330,0,180,100);
 arc(300,230,90,270,100);
 x=(200+300)/2;
 y=(330+230)/2;
floodfill(x,y,YELLOW);


//center of flower
  setcolor(BLACK);
 setfillstyle(SOLID_FILL,BLACK);
circle(200,230,15);
floodfill(201,230,BLACK);
  setcolor(GREEN);
 arc(400,230,180,270,200);
 getch();
}
