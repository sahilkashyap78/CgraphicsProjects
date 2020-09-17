#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
#include<windows.h>
class RandomPoints
{
    public:
        int points;
        int width =GetSystemMetrics(SM_CXSCREEN);  //for width of the screen
        int height =GetSystemMetrics(SM_CYSCREEN); // for height of the screen
    void InstantiatePoints()  //takes no. of points in argument

    {
        for(int index=0;index<points;index++)
        {
        int x =(rand()%width)+1; //takes the random valuse of x
        int y=(rand()%height)+1; //takes the random values of y
        int randomcolor =(rand()%14)+1;  //takes the random color
        putpixel(x,y,randomcolor); //instantiate the point according to thr x and y values
        }
    }
    void SetPoints()
    {
        printf("Enter the Number of points to be printed ?");   //take points
        scanf("%d",&points);
        while(points<=0)    // while points are < or = 0 then we have to renenter the points
        {
        SetPoints();
        }
    }

};

int main()
{
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
RandomPoints pointsobject;
pointsobject.SetPoints();
pointsobject.InstantiatePoints();  //function for instantiating random points
getch();
closegraph();
}
