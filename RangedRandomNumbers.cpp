#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<windows.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;


class RandomRangedNumber
{

public:
     int firstnumber;   //to store the first number of range
     int lastnumber;  // to store the last number of range
    int width =GetSystemMetrics(SM_CXSCREEN); //width of screen
    int height =GetSystemMetrics(SM_CYSCREEN);  //height of screen
    int *randomnumberarray;  // dynamic array for storing the random numbers b/w the range.
    int arraysize;        //size of the dynamic array based on the user given range
    char firstnumbercharachter[10]; // used to display our first number of range on screen using outtextxy
    char lastnumbercharachter[10];  // used to display our last number of range on screen using outtextxy
    char randomnumbercharachter[10]; // used to display our random numbers on screen using outtextxy
    int lastindex;

    //enum for defining the state of the program
enum State {
   StartingState,Endstate
}currentstate;



//  function used for outtextxy
void InstantiateText(int x,int y,char *text)
{

 outtextxy(x,y,text);

}



//function for displaying the textboxes on the screen.
void TextBox(int x1,int y1,int x2,int y2)
{


setcolor(WHITE);
setfillstyle(SOLID_FILL,BLACK);
rectangle(x1,y1,x2,y2);
floodfill(x1+5,y1+5,WHITE);





}



// function to display the information boxes which helps to terminate the program and also helps to get the random number
void InformationBox(int boxX1,int boxY1,int boxX2,int boxY2,int textX,int textY,char *text1,char *text2,char *text3 )
{

TextBox(boxX1,boxY1,boxX2,boxY2);
setcolor(WHITE);
settextstyle(3,0,1);
outtextxy(textX,textY,text1);
outtextxy(textX,textY+30,text2);
outtextxy(textX,textY+55,text3);

}

//function to display the coloured rectangle
void ColouredRectangle(int x1,int y1,int x2,int y2 ,int color)
{

            setcolor(color);
            setfillstyle(SOLID_FILL,color);
            rectangle(x1,y1,x2,y2);
            floodfill(x1+2,y1+2,color);



}



//background of our interface
void CreateBackground()
{

              ColouredRectangle(0,0,width,height,YELLOW);
              setcolor(WHITE);
              settextstyle(1,0,5);
              InstantiateText((width/4)-100,(height/4)-75,"RANDOM NUMBER GENERATOR");
              ColouredRectangle(width/4,height/4,(width/2+width)/2,(height/2+height)/2,RED);

}


// function to diplay the multiple outetextxy
void TextGroup(int x,int y, char *text1,char *text2,char *text3)
{
    setcolor(WHITE);
    InstantiateText(x,y,text1);
    InstantiateText(x,y+100,text2);
    InstantiateText(x,y+200,text3);




}


// to create the user interface
    void UserInterface(char *firstcharachter,char * secondcharchter,char *randomcharachter)

    {


          CreateBackground();
          settextstyle(1,0,3);
          TextGroup((width/4)+25,(height/4)+25,"FirstNumber","LastNumber","RandomNumber");

          TextBox((width/4)+400,(height/4)+15,(width/4)+600,(height/4)+60);
          TextBox((width/4)+400,(height/4)+115,(width/4)+600,(height/4)+160);
          TextBox((width/4)+400,(height/4)+215,(width/4)+600,(height/4)+260);

          settextstyle(3,0,1);
          TextGroup((width/4)+490,(height/4)+27,firstcharachter,secondcharchter,randomcharachter);

          InformationBox((width/4)+15,(height/4)+325,(width/4)+150,(height/4)+425,(width/4)+25,(height/4)+335,"Press G","To Generate","Next Number");
          InformationBox((width/4)+600,(height/4)+325,(width/4)+735,(height/4)+425,(width/4)+610,(height/4)+335,"Press X","To Terminate","Program");



        //InputManager();


    }



//function to set the range of the program initially
    void SetRange()
    {

        cout<<"Enter the first Number of range: ";
        cin>>firstnumber;
        cout<<"Enter the Last Number of range: ";
        cin>>lastnumber;

if(lastnumber<=firstnumber)
{
    SetRange();

}

        sprintf(firstnumbercharachter,"%d",firstnumber); // for conversion of the int to char
        sprintf(lastnumbercharachter,"%d",lastnumber);




        arraysize = (lastnumber-firstnumber)+1; // the size of our array based on the range of numbers
        lastindex=arraysize;
        randomnumberarray =(int*)malloc(arraysize*sizeof(int)); // allocation of memory

        RandomizeNumber();   // function to get the randomize number b/w the range



    }



    void RandomizeNumber()
    {
        //cout<<lastindex<<endl;

        if(currentstate==StartingState&&lastindex>=1) //check the current state
           {


                    int randomnumber =(rand()%lastindex);  //calculate the random number b/w range


                    int temp =randomnumberarray[randomnumber];

                            sprintf(randomnumbercharachter,"%d",temp);
                            randomnumberarray[randomnumber] =randomnumberarray[lastindex-1];
                            randomnumberarray[lastindex-1]=temp;
                            lastindex =lastindex-1;;

           }else if(lastindex==0)
                {

                            outtextxy((width/4)+200,(height/4)+450,"No more Random Numbers to generate");
                            currentstate=Endstate;


                }


    }




// input manager for the program
    void InputManager()
{

    char ch;
    while(ch!=27)
    {
    ch=getch();

        if(ch=='g'||ch=='G')
        {
         RandomizeNumber();
         UserInterface(firstnumbercharachter,lastnumbercharachter,randomnumbercharachter);


        }
         else if(ch=='x'||ch=='X')
        {   free(randomnumberarray);
            exit(0);

        }


        }

    }



};





int main()
{

int gdriver=DETECT,gmode;

initgraph(&gdriver,&gmode,"");

RandomRangedNumber r;
r.currentstate =r.StartingState;//initially our state is starting state
r.SetRange();
r.UserInterface(r.firstnumbercharachter,r.lastnumbercharachter,r.randomnumbercharachter);
r.InputManager();


getch();
closegraph();

}
