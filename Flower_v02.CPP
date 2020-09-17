#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define flowercenterX 400
#define flowercenterY 230
#define flowerXposition11 200
#define flowerYposition11 130
#define flowerYposition12 330
#define flowerXposition21 100
#define flowerXposition22 300
#define flowerYposition21 230
#define degree_0 0
#define degree_90 90
#define degree_180 180
#define degree_270 270
#define degree_360 360
#define Arcradius 100
class Flower{
    public:
        void FlowerCenter()
        {
             setcolor(BLACK);
             setfillstyle(SOLID_FILL,BLACK);
             circle(flowerXposition11,flowerYposition21,15);
             floodfill(flowerXposition11,flowerYposition21,BLACK);
             setcolor(GREEN);
             arc(flowercenterX,flowercenterY,degree_180,degree_270,Arcradius*2);
        }

// in this fuction x1 and y1 are the the center point of first arc ,firstangle1 is starting angle of first arc and firstangle2 is ending angle of first arc
//x2 and y2 are the the center point of second arc ,secondangle1 is starting angle of second arc and firstangle2 is ending angle of second arc
//Arcradius is common for both the arcs
        void Petal(int x1,int y1,int firstangle1,int firstangle2,int x2,int y2,int secondangle1,int secondangle2,int radius)
        {
                arc(x1,y1,firstangle1,firstangle2,Arcradius);
                arc(x2,y2,secondangle1,secondangle2,Arcradius);
                int midx=(x1+x2)/2;
                int midy=(y1+y2)/2;
                floodfill(midx,midy,YELLOW);

        }
        void DrawFlower()
        {
             setcolor(YELLOW);
             setfillstyle(SOLID_FILL,YELLOW);
             Petal(flowerXposition11,flowerYposition11,degree_180,degree_360,flowerXposition21,flowerYposition21,degree_270,degree_90,Arcradius); //PETAL 1 IS COMBINATION OF ARC degree_180TOdegree_360 AND 270 TO 90
             Petal(flowerXposition11,flowerYposition11,degree_180,degree_360,flowerXposition22,flowerYposition21,degree_90,degree_270,Arcradius);//petal 2 degree_180todegree_360 and 90 to 270 combinatio
             Petal(flowerXposition11,flowerYposition12,degree_0,degree_180,flowerXposition21,flowerYposition21,degree_270,degree_90,Arcradius);//petal 3 combination of arcs 0 to degree_180 AND 270 TO 90
             Petal(flowerXposition11,flowerYposition12,degree_0,degree_180,flowerXposition22,flowerYposition21,degree_90,degree_270,Arcradius);//PETEAL 4 IS COMBINATION OFARC 0 TO degree_180 AND 90 TO 270
             FlowerCenter();//center of flower
        }
};

int main()
{
    int gdriver = DETECT,gmode;
    initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
    Flower flowerobject;
    flowerobject.DrawFlower();
    getch();
    closegraph();
}
