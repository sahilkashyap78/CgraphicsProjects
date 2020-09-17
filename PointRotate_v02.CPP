#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#define angletoradian 0.017444
#define Pointscolor 5
#include<iostream>
using namespace std;
class RandomRotation{
public:

	long *radius;
	long *PositionX;
	long *PositionY;
	long *angle;
	int points;
	int width =GetSystemMetrics(SM_CXSCREEN);
	int height =GetSystemMetrics(SM_CYSCREEN);
	int CenterX = width/2;
	int CenterY =height/2;
	    //function for centercreation
	void CreateCenter()
	{
	 int randomcolor =(rand()%14)+1;
	 setcolor(randomcolor);
	 setfillstyle(SOLID_FILL,randomcolor);
	 circle(CenterX,CenterY,3);
	 floodfill(CenterX,CenterY,randomcolor);
	}

    //function for terminating the program by pressing the x
	void InputManager()
	{
        //press x to terminate the program
        char choice;
        if (kbhit())
        {
            choice = getch();
        }
        switch(choice)
        {
            case 'x':
            case 'X':
                DeallocateMemory();
                exit(0);
        }
	}
       //fuction to set the no. of points to be rotatted randomly
	void SetPoints()
	 {
         printf("How many points do you want ?");
         scanf("%d",&points);
         while(points<0)
         {
             SetPoints();
         }

	 }
	   // after getting the points we have to allocate the memory using this function
	void AllocateMemory()
	{
		radius = (long*)malloc(points*sizeof(long));
		PositionX = (long*)malloc(points*sizeof(long));
		PositionY = (long*)malloc(points*sizeof(long));
		angle = (long*)malloc(points*sizeof(long));

	}
//function to store the random value of x and y in our dynamic arrays and by using the formula of magnitude we have calculated the radius
// this value of x and y with our radius going to help us to instantiate our points randomly and thus rotate it
	void StoreValue()
	{
        for(int index=0;index<points;index++)
        {
            PositionX[index]=(rand()%width)+1;
            PositionY[index]=(rand()%height)+1;
            long x= PositionX[index]-CenterX;
            long y =PositionY[index]-CenterY;
            radius[index]=sqrt(x*x+y*y);
            angle[index] =(rand()%360)+1;
        }
	}

// function to Rotate our points according to the given angle
	void RotatePoints()
	{
	    for(int angle_index=1;angle_index<=360;angle_index++)    // angle loop
		{
            delay(100);//for slight delay
            cleardevice();
            CreateCenter(); //for center point
            for(int index=0;index<points;index++)            // points loop
                {
                    long anglex=radius[index]*cos((angle_index+angle[index])*angletoradian);
                    long angley=radius[index]*sin((angle_index+angle[index])*angletoradian);
                    long x=CenterX+anglex; //initial points for xis 320
                    long y=CenterY+angley; //initial point for y is 235
                    putpixel(x,y,Pointscolor);  //for creation of the points

                }
		}
	}

    void DeallocateMemory()
    {
        free(radius);
        free(PositionX);
        free(PositionY);
        free(angle);
    }


};
int main()
{
	int gDrive = DETECT,gMode;
	initgraph(&gDrive,&gMode,"C://TURBOC3//BGI");
	RandomRotation r;
    r.SetPoints();//for setting the points number
	r.AllocateMemory(); // for allocation of memory
	r.StoreValue();   //for storing the values in our dynamic arrays
    r.RotatePoints();
    getch();
    closegraph();
}
