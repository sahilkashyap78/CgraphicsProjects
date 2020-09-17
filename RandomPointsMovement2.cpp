#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<iostream>
#define oneradian 0.017444
#define pointradius 3
#define totalcolors 14
#define degree_360 360
#define MinHeight 0
#define delay_100 100
#define pointscolor 5
using namespace std;

class RandomRotation{

     private:
        long *radius;            // to store the radius in  order to rotate the points
        long double *angle;     //initial angle from which the rotation gets started
        long *positionX;  //record the position of x during rotation and vertical movement
        long *positionY; //record the position of y during rotation and vertical movement
        int points;
        int width =GetSystemMetrics(SM_CXSCREEN);//to get the width of the screen
        int height =GetSystemMetrics(SM_CYSCREEN);//to get the height of the screen
        int centerX = width/2; // to get the x coordinate of the center
        int centerY =height/2; // to get the y coordinate of the center
        long heightdiffrence=0; //will get incremented or decremented in the y position to move up or down
    public:
        enum State{
        anticlockwiserotation,clockwiserotation,verticalup,verticaldown

        }; // to find out in which state our program is currently running
        State currentstate;
	    //function for center creation
	void CreateCenter()
	{
         int randomcolor =(rand()%totalcolors)+1;
         setcolor(randomcolor);
         setfillstyle(SOLID_FILL,randomcolor);
         circle(centerX,centerY,pointradius);
         floodfill(centerX,centerY,randomcolor);
	}

    //function to set the no. of points.
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
		angle = (long double*)malloc(points*sizeof(long double));
        positionX = (long*)malloc(points*sizeof(long));
        positionY = (long*)malloc(points*sizeof(long));

	}

	void StoreInitialRotationValues()
	{
        for(int index=0;index<points;index++)
        {
            radius[index]=(rand()%width)+1;
            angle[index] =(((rand()%degree_360)+1))*oneradian;
            positionX[index]=radius[index]*cos(angle[index]);
            positionY[index]=radius[index]*sin(angle[index]);

        }
	}

//function is used to retrieve the values from vertical movement and thus calculates the initial angle from which our rotation will get started
	void TransferVerticalValueToRotation(long xposition,long yposition,int index)
	{
        long  x= xposition-centerX;
        long  y =yposition-centerY;
        radius[index]=sqrt(x*x+y*y);
        angle[index] =(atan2(y,x));
	}

	void VerticalMovement()
	{
        for(int point_index=0;point_index<=points;point_index++)
            {
                if(heightdiffrence>height)
                {
                    heightdiffrence=MinHeight;
                }
                long yposition;
                if(currentstate == verticaldown)
                    {
                        yposition =(positionY[point_index]+heightdiffrence);
                    }
                else if(currentstate == verticalup)
                    {
                        yposition =(positionY[point_index]-heightdiffrence);
                    }
                TransferVerticalValueToRotation(positionX[point_index],yposition,point_index); //pass the location information to the function which calculates the angle.
                putpixel(positionX[point_index],yposition,pointscolor);
                heightdiffrence++;
            }
	}

//function for managing the input

	void InputManager()
	{
	   char choice;
            if (kbhit())
            {
                choice = getch();
            }
        switch(choice)
        {
            case 'b':
            case 'B':
                    if(currentstate==verticaldown||currentstate==verticalup)
                    {
                        return;
                    }
                    currentstate =verticaldown;

                    break;
            case 'c':
            case 'C':
                    if(currentstate==anticlockwiserotation||currentstate==clockwiserotation)
                    {
                        return;
                    }
                    currentstate=clockwiserotation;

                    break;
            case 'a':
            case 'A':
                    ToggleManager(); //for toggling the rotation or vertical movement

                    break;
            case 'x':
            case 'X':
                    DeallocateMemory();// for deallocating the memory
                    exit(0);
        }
	}


//function to manage the toggle mechanism
    void ToggleManager()
    {
        if(currentstate ==verticaldown||currentstate==verticalup)   //check that the system is the moving mode or not
                {
                    if(currentstate==verticalup) //for toggling the vertical movement between up and down direction
                    {
                        currentstate =verticaldown;
                    }
                    else
                    {
                        currentstate =verticalup;
                    }
                }
        else if(currentstate ==anticlockwiserotation||currentstate==clockwiserotation)  //check that the system is the rotating mode or not
                {
                    if(currentstate ==clockwiserotation)  //for toggling the rotation between clockwise and anticlockwise
                    {
                        currentstate =anticlockwiserotation;
                    }
                    else
                    {
                        currentstate =clockwiserotation;
                    }
                }
    }

	// function to Rotate our points according to the given angle

	void RotatePoints()
	{
        for(int index=0;index<points;index++)            // points loop
        {
            if(currentstate==clockwiserotation)
                {
                    angle[index]=angle[index]+oneradian;  //angle will be incremented by one radian
                }
            else if(currentstate==anticlockwiserotation)
                {
                    angle[index]=angle[index]-oneradian; //angle will be decremented by one radian
                }
            positionX[index]=centerX+radius[index]*cos(angle[index]); //position will be setted according to the angle
            positionY[index]=centerY+radius[index]*sin(angle[index]);
            putpixel(positionX[index],positionY[index],pointscolor);  //for creation of the points
        }
    }

    void DeallocateMemory()
    {
        free(radius);
        free(angle);
        free(positionX);
        free(positionY);
    }

    void Update()
    {
        while(1)
            {
                cleardevice();
                CreateCenter(); //for center point
                if(currentstate==anticlockwiserotation||currentstate==clockwiserotation)
                    {
                        RotatePoints();
                    }
                else if(currentstate==verticaldown||currentstate==verticalup)
                    {
                        VerticalMovement();
                    }
                InputManager();
                delay(delay_100);//for creating delay
                Update();
            }

    }

};

int main()
{
	int gDrive = DETECT,gMode;
	initgraph(&gDrive,&gMode,"C://TURBOC3//BGI");
	RandomRotation r;
    r.SetPoints();//for setting the points number
	r.AllocateMemory(); // for allocation of memory
	r.currentstate =r.clockwiserotation;//initially our state will be in rotation mode
	r.StoreInitialRotationValues();   //for storing the values in our dynamic arrays
    r.Update();
    getch();
    closegraph();
}
