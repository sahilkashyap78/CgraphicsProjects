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
	long *rotatingpositionX; // to store the position of x for rotation of points
	long *rotatingpositionY; // to store the position of y for rotation of points
	long double *initialangle;     //initial angle from which the rotation gets started
	long *positionrecordX;  //record the position of x during rotation and vertical movement
	long *positionrecordY; //record the position of y during rotation and vertical movement
	long *verticalpositionX;   // to store the position of x for vertical movement
	long *verticalpositionY;   // to store the position of y for vertical movement
	bool isRotating=true;   //to check the system is in rotation mode or not
	bool isMoving=false;    //to check the system is in moving mode or not
	bool toggleRotation=false;  // to toggle the rotation between clock and anti-clock direction
	bool toggleMoving=false;    // to toggle the movement between up and down direction
    long double onerad =0.17444;
	int points;
	int width =GetSystemMetrics(SM_CXSCREEN);//to get the width of the screen
	int height =GetSystemMetrics(SM_CYSCREEN);//to get the height of the screen
	int centerX = width/2; // to get the x coordinate of the center
	int centerY =height/2; // to get the y coordinate of the center
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
		rotatingpositionX = (long*)malloc(points*sizeof(long));
		rotatingpositionY= (long*)malloc(points*sizeof(long));
		initialangle = (long double*)malloc(points*sizeof(long double));
        positionrecordX = (long*)malloc(points*sizeof(long));
        positionrecordY = (long*)malloc(points*sizeof(long));
        verticalpositionX= (long*)malloc(points*sizeof(long));
        verticalpositionY= (long*)malloc(points*sizeof(long));



	}


 //function to store the random value of x and y in our dynamic arrays and by using the formula of magnitude we have calculated the radius

	  // this value of x and y with our radius going to help us to instantiate our points randomly and thus rotate it


	void StoreValueRotation()
	{


	for(int index=0;index<points;index++)
	{
	rotatingpositionX[index]=(rand()%width)+1;
	rotatingpositionY[index]=(rand()%height)+1;
	long x= rotatingpositionX[index]-centerX;
	long y =rotatingpositionY[index]-centerY;
	radius[index]=sqrt(x*x+y*y);
	initialangle[index] =((rand()%360)+1)*(3.14/180);
	cout<<initialangle[index]<<endl;
	}



	}
// function overloading so that the x coordinate and y coordinate of rotation can takes the values of the vertical movement

	void StoreValueRotation(long *xposition,long *yposition)
	{


	for(int index=0;index<points;index++)
	{
	rotatingpositionX[index]=xposition[index];
	rotatingpositionY[index]=yposition[index];
	long x= rotatingpositionX[index]-centerX;
	long y =rotatingpositionY[index]-centerY;
	radius[index]=sqrt(x*x+y*y);
	initialangle[index] =((rand()%360)+1)*onerad;
	}



	}



//function to store the values of x and y for vertical movement that it takes from the rotation movement that are continously recording in the position record coordinates


	void StoreValueVertical()
	{
	 for(int index=0;index<points;index++)
	{

        verticalpositionX[index] = positionrecordX[index];
        verticalpositionY[index] =positionrecordY[index];

		}


	}


	//function for the Vertical Movement mechanism

	void VerticalMovement(bool toggle)
	{

	    StoreValueVertical(); //this function stores the current values of x and y from which we have to start moving vertically.
       long height_index=0;  //height flag for moving in vertical direction

	    while(1)
        {
            height_index++;

                if(height_index==height)
                {
                    height_index=0;
                }

		    cleardevice();
		    VerticalInstantiatePoints(toggle,height_index); //to instantiate the point


InputManager(); //check the inputs

        }

	}



 //Function for instantiating the points in the vertical movement

   void VerticalInstantiatePoints(bool toggle,int heightflag)
   {


     for(int point_index=0;point_index<points;point_index++)
            {
                long xposition = verticalpositionX[point_index];
                long yposition;
                if(toggle==false)
                {

                yposition =(verticalpositionY[point_index]+heightflag);

                }else if((toggle==true)){


                yposition =(verticalpositionY[point_index]-heightflag);


                }
                positionrecordY[point_index]=yposition;

                putpixel(xposition,yposition,5);

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
		    StoreValueRotation(positionrecordX,positionrecordY);
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

    for(long double angle=0;angle<=360;angle++)    // angle loop
		{
        long double radangle =angle*onerad;

		delay(100);//for slight delay
		cleardevice();
        CreateCenter(); //for center point


	 for(int index=0;index<points;index++)            // points loop
	   {

           RotatingInstantiatePoints(index,radangle,toggle);     //diplay points randomly


	   }
        InputManager();


	       }




}

	}

    //////////////////////////Instantiate Points/////////////////////////////////


    void RotatingInstantiatePoints(int index,long double angle,bool toggle)
    {
	 // now in order to rotate this points we use formula x= rsin(angle) and y = rcos(angle) according to our center point
	     //and in each update we increment our angle thus can follow the circular path according to the center i.e (320,235)

            long anglex;
            long angley;

            if(toggle==false)
            {
                anglex=radius[index]*cos((angle+initialangle[index]));
                angley=radius[index]*sin((angle+initialangle[index]));
            }else if(toggle==true)
            {
                anglex=radius[index]*cos((initialangle[index]-angle));
                angley=radius[index]*sin((initialangle[index]-angle));
            }

		long x=centerX+anglex; //initial points for xis 320
		long y=centerY+angley; //initial point for y is 235

        positionrecordX[index]=x;
        positionrecordY[index]=y;
        int color =5;   // for random colors of the points

		putpixel(x,y,color);  //for creation of the points

    }

      //Deallocating the memory///////////////////////////////////////////

      void DeallocateMemory()
      {
	       free(radius);
	       free(rotatingpositionX);
	       free(rotatingpositionY);
	       free(initialangle);
	       free(positionrecordX);
            free(positionrecordY);
	        free(verticalpositionX);
	        free(verticalpositionY);

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
	r.StoreValueRotation();   //for storing the values in our dynamic arrays
    r.RotatePoints(r.toggleRotation);//initially the rotation mechanism starts.
    r.DeallocateMemory();// for deallocating the memory
    getch();

}
