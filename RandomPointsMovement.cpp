#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<iostream>
using namespace std;


/*

 Initially when our main method gets called the rotation mechanism stars and after that,
 we can move to vertical mechanism or can toggle the rotation or vertical movement.


PREESS A IN THE PROGRAM TO TOGGLE THE ROTATION BETWEEN CLOCK AND ANTI-CLOCK DIRECTION.
SIMILARLY PREESING A CAN TOGGLE THE VERTICAL MOVEMENT BETWEEN UP AND DOWN DIRECTION.

PRESS B TO TRANSFER THE MECHANISM FROM ROTATION TO VETICAL MOVEMENT.

PRESS C TO TRASNFER THE MECHANISM FROM VERTICAL MOVEMENT TO ROTATION.


*/
class RandomRotation{
public:
	/////////////VARIABLES////////////////////////////////
	long *radius;            // to store the radius in  order to rotate the points

	long double *angle;     //initial angle from which the rotation gets started
	long *positionX;  //record the position of x during rotation and vertical movement
	long *positionY; //record the position of y during rotation and vertical movement
	bool isRotating=true;   //to check the system is in rotation mode or not
	bool isMoving=false;    //to check the system is in moving mode or not
	bool toggleRotation=false;  // to toggle the rotation between clock and anti-clock direction
	bool toggleMoving=false;    // to toggle the movement between up and down direction
    const long double onerad =0.017444;
    int points;
	int width =GetSystemMetrics(SM_CXSCREEN);//to get the width of the screen
	int height =GetSystemMetrics(SM_CYSCREEN);//to get the height of the screen
	int centerX = width/2; // to get the x coordinate of the center
	int centerY =height/2; // to get the y coordinate of the center
enum{
anticlockwiserotation,clockwiserottion,verticalup,verticaldown

}currentstate;

	///////////////////////////////////////////////////////////


	//////////////////////////FUNCTIONS////////////////////////////////

	    //function for center creation
	void CreateCenter()
	{
	 int randomcolor =(rand()%14)+1;
	 setcolor(randomcolor);
	 setfillstyle(SOLID_FILL,randomcolor);
	 circle(centerX,centerY,3);
	 floodfill(centerX,centerY,randomcolor);
	}

    //function to set the no. of points.
	void SetPoints()
	 {
	 printf("How many points do you want ?");
	 scanf("%d",&points);

	 }

    // after getting the points we have to allocate the memory using this function
	void AllocateMemory()
	{
		radius = (long*)malloc(points*sizeof(long));
		angle = (long double*)malloc(points*sizeof(long double));
        positionX = (long*)malloc(points*sizeof(long));
        positionY = (long*)malloc(points*sizeof(long));

	}


 //function to store the random value of x and y in our dynamic arrays and by using the formula of magnitude we have calculated the radius

	  // this value of x and y with our radius going to help us to instantiate our points randomly and thus rotate it


	void StoreInitialValues()
	{


	for(int index=0;index<points;index++)
	{
	radius[index]=(rand()%width)+1;
	angle[index] =(((rand()%360)+1))*onerad;

	positionX[index]=radius[index]*cos(angle[index]);
	positionY[index]=radius[index]*sin(angle[index]);
	long x= positionX[index]-centerX;
	long y =positionY[index]-centerY;

	}



	}
// x coordinate and y coordinate of rotation can takes the values of the vertical movement

	void StoreValueRotation(long xposition,long yposition,int index)
	{

	long  x= xposition-centerX;
	long  y =yposition-centerY;
	radius[index]=sqrt(x*x+y*y);
	angle[index] =(atan2(y,x));

	}






	//function for the Vertical Movement mechanism

	void VerticalMovement(bool toggle)
	{


while(1)
      {

                for(int height_index=0;height_index<=height;height_index++)
            {

            cleardevice();
            CreateCenter(); //for center point

                for(int point_index=0;point_index<=points;point_index++)

                {
                      VerticalInstantiatePoints(toggle,height_index,point_index); //to instantiate the point


                }
                InputManager();

            }
      }

	}



 //Function for instantiating the points in the vertical movement

   void VerticalInstantiatePoints(bool toggle,int height_index,int point_index)
   {

            long xposition =positionX[point_index];
            long yposition;


                if(toggle==false)
                {

                yposition =(positionY[point_index]+height_index);

                }else if((toggle==true)){


                    yposition =(positionY[point_index]-height_index);


                }

                StoreValueRotation(xposition,yposition,point_index);
                putpixel(xposition,yposition,5);




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
		    if(isMoving=true&&isRotating==false)
            {
                return;
            }
		    isRotating=false;
		    isMoving=true;
			VerticalMovement(toggleMoving);

		case 'c':
		case 'C':
             if(isMoving=false&&isRotating==true)
            {
                return;
            }

		    isRotating=true;
		    isMoving=false;

			RotatePoints(toggleRotation);

        case 'a':
		case 'A':

                ToggleManager();

		case 'x':
		case 'X':
			     exit(0);


	}

	}


//function to manage the toggle mechanism
void ToggleManager()
{
         if(isMoving==true)   //check that the system is the moving mode or not
                {
                    if(toggleMoving==false)  //for toggling the rotation between clockwise and anticlockwise
                    {
                        toggleMoving=true;
                        VerticalMovement(toggleMoving);
                    }else{

                        toggleMoving=false;
                        VerticalMovement(toggleMoving);

                    }

                }else if(isRotating==true)  //check that the system is the rotating mode or not
                {

                    if(toggleRotation==false)  //for toggling the vertical movement between up and down direction
                    {
                        toggleRotation=true;
                        RotatePoints(toggleRotation);
                    }else{

                        toggleRotation=false;
                        RotatePoints(toggleRotation);

                    }



                }

}



	// function to Rotate our points according to the given angle

	void RotatePoints(int toggle)
	{
while(1)
{

    for(int angle_index=0;angle_index<=360;angle_index++)    // angle loop
		{
		    long double angleradian =angle_index*onerad;

		delay(30);//for slight delay
		cleardevice();
        CreateCenter(); //for center point


	 for(int index=0;index<points;index++)            // points loop
	   {

           RotatingInstantiatePoints(index,angleradian,toggle);     //diplay points randomly


	   }
        InputManager();


	       }




}

	}

    //////////////////////////Instantiate Points/////////////////////////////////


    void RotatingInstantiatePoints(int index,long double angle_index,bool toggle)
    {
	 // now in order to rotate this points we use formula x= rsin(angle) and y = rcos(angle) according to our center point
	     //and in each update we increment our angle thus can follow the circular path according to the center i.e (320,235)
            long anglex;
            long angley;
            if(toggle==false)
            {
                anglex=radius[index]*cos((angle_index+angle[index]));
                angley=radius[index]*sin((angle_index+angle[index]));
            }else if(toggle==true)
            {
                anglex=radius[index]*cos((angle[index]-angle_index));
                angley=radius[index]*sin((angle[index]-angle_index));
            }

		long x=centerX+anglex; //initial points for xis 320
		long y=centerY+angley; //initial point for y is 235

        positionX[index]=x;
        positionY[index]=y;
        int color =5;   // for random colors of the points

		putpixel(x,y,color);  //for creation of the points

    }

      //Deallocating the memory///////////////////////////////////////////

      void DeallocateMemory()
      {
	       free(radius);
	       free(angle);
	       free(positionX);
            free(positionY);


	              }



	              void Update()
	              {





	              }




};







int main()
{

	int gDrive = DETECT,gMode;
	initgraph(&gDrive,&gMode,"C://TURBOC3//BGI");
	RandomRotation r;
    r.SetPoints();//for setting the points number

    while(r.points<=0)   // if the points are 0 or less than 1
    {
        r.SetPoints();
    }
	r.CreateCenter();  //for center
	r.AllocateMemory(); // for allocation of memory
	r.StoreInitialValues();   //for storing the values in our dynamic arrays
    r.RotatePoints(r.toggleRotation);//initially the rotation mechanism starts.
    r.DeallocateMemory();// for deallocating the memory
    getch();

}
