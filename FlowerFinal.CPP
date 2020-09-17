#include<stdio.h>
#include<conio.h>
#include<graphics.h>




void FlowerCenter()
{

     setcolor(BLACK);
     setfillstyle(SOLID_FILL,BLACK);
     circle(200,230,15);
     floodfill(200,230,BLACK);
     setcolor(GREEN);
     arc(400,230,180,270,200);


}


// in this fuction x1 and y1 are the the center point of first arc ,firstangle1 is starting angle of first arc and firstangle2 is ending angle of first arc
//x2 and y2 are the the center point of second arc ,secondangle1 is starting angle of second arc and firstangle2 is ending angle of second arc
//radius is common for both the arcs

void Petal(int x1,int y1,int firstangle1,int firstangle2,int x2,int y2,int secondangle1,int secondangle2,int radius)
{
        arc(x1,y1,firstangle1,firstangle2,radius);
        arc(x2,y2,secondangle1,secondangle2,radius);
        int midx=(x1+x2)/2;
        int midy=(y1+y2)/2;
        floodfill(midx,midy,YELLOW);




}





int main()
{
        int gdriver = DETECT,gmode;
         int x,y;
        initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
         setcolor(YELLOW);


         setfillstyle(SOLID_FILL,YELLOW);

         //PETAL 1 IS COMBINATION OF ARC 180TO360 AND 270 TO 90
         Petal(200,130,180,360,100,230,270,90,100);

         //petal 2 180to360 and 90 to 270 combinatio
        Petal(200,130,180,360,300,230,90,270,100);

        //petal 3 combination of arcs 0 to 180 AND 270 TO 90
        Petal(200,330,0,180,100,230,270,90,100);

        //PETEAL 4 IS COMBINATION OFARC 0 TO 180 AND 90 TO 270
        Petal(200,330,0,180,300,230,90,270,100);

        //center of flower
        FlowerCenter();

         getch();
         closegraph();
}
