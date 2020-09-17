#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>



class RandomRotation{
public:
	/////////////VARIABLES////////////////////////////////
	long *radius;
	long *randx;
	long *randy;
	long *initialangle;
	int points;
	int width =GetSystemMetrics(SM_CXSCREEN);
	int height =GetSystemMetrics(SM_CYSCREEN);
	int centerX = width/2;
	int centerY =height/2;
	///////////////////////////////////////////////////////////



	//////////////////////////FUNCTIONS////////////////////////////////

	    //function for centercreation
	void CreateCenter()
	{
	 int randomcolor =(rand()%14)+1;
	 setcolor(randomcolor);
	 setfillstyle(SOLID_FILL,randomcolor);
	 circle(centerX,centerY,3);
	 floodfill(centerX,centerY,randomcolor);
	}

	//////////////////////////////////////////////////////////////

	       //function for terminating the program by pressing the x
	void TerminateProgram()
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
			exit(0);
	}
	}


 ///////////////////////////////////////////////////////////////////
	       //fuction to set the no. of points to be rotatted randomly

	void SetPoints()
	 {
	 printf("How many points do you want ?");
	 scanf("%d",&points);

	 }

    /////////////////////////////////////////////////////////////////

	   // after getting the points we have to allocate the memory using this function
	void AllocateMemory()
	{
		radius = (long*)malloc(points*sizeof(long));
		randx = (long*)malloc(points*sizeof(long));
		randy = (long*)malloc(points*sizeof(long));
		initialangle = (long*)malloc(points*sizeof(long));

	}


   /////////////////////////////////////////////////////////////////////


	  //function to store the random value of x and y in our dynamic arrays and by using the formula of magnitude we have calculated the radius

	  // this value of x and y with our radius going to help us to instantiate our points randomly and thus rotate it

	void StoreValue()
	{


	for(int index=0;index<points;index++)
	{
	randx[index]=(rand()%width)+1;
	randy[index]=(rand()%height)+1;
	long x= randx[index]-centerX;
	long y =randy[index]-centerY;
	radius[index]=sqrt(x*x+y*y);
	initialangle[index] =(rand()%360)+1;
	}



	}

// //////////////////////////////////////////////////////////////////////









	// function to Rotate our points according to the given angle

	void RotatePoints()
	{

	for(int angle=1;angle<=360;angle++)    // angle loop
		{
		delay(100);//for slight delay
		cleardevice();
	       CreateCenter(); //for center point


	 for(int index=0;index<points;index++)            // points loop
	   {
	   InstantiatePoints(index,angle);     //diplay points randomly


	   }

	   TerminateProgram();

	       }
	}

    //////////////////////////Instantiate Points/////////////////////////////////


    void InstantiatePoints(int index,int angle)
    {
	 // now in order to rotate this points we use formula x= rsin(angle) and y = rcos(angle) according to our center point
	     //and in each update we increment our angle thus can follow the circular path according to the center i.e (320,235)

		long anglex=radius[index]*cos((angle+initialangle[index])*3.14/180);
		long angley=radius[index]*sin((angle+initialangle[index])*3.14/180);
		long x=centerX+anglex; //initial points for xis 320
		long y=centerY+angley; //initial point for y is 235

		int color =5;   // for random colors of the points

		putpixel(x,y,color);  //for creation of the points

    }



      /////////////////////Deallocating the memory///////////////////////////////////////////

      void DeallocateMemory()
      {
	       free(radius);
	       free(randx);
	       free(randy);
	       free(initialangle);
      }

    //////////////////////////////////////////////////////////////////////




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
	r.StoreValue();   //for storing the values in our dynamic arrays



		while(1){        //infinite loop

	       r.RotatePoints();//update points according to the angle

			}
 r.DeallocateMemory();
getch();

}
