#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<windows.h>
#include<iostream>
#include<string.h>
using namespace std;
class House{

    public:
     bool Light = false;  // to toggle light
    int groundfloorcolor=0;//to assign the color to the ground floor
    int firstfloorcolor=0;//to assign the color to the first floor
    // colors codes for assigning the color
    const int black=0;
    const int red=4;
    const int yellow=14;
    void SwitchBox()   //will create two boxes one at  bottom-left and one at bottom-right
    {
        //ground floor switch box
        TextBorder(0,690,200,750);   // create a border around our text
        outtextxy(5,700,"Press A");
        outtextxy(5,720,"Switch On/Off");
        outtextxy(5,735,"Lights of Ground Floor");
        //first floor switch box
        TextBorder(1248,690,1448,750);// create a border around our text
        outtextxy(1250,700,"Press Z");
        outtextxy(1250,720,"Switch On/Off");
        outtextxy(1250,735,"Lights of Ground Floor");
    }

    void TextBorder(int x1,int y1,int x2,int y2)// create a border around our text
    {
        setcolor(RED);
        rectangle(x1,y1,x2,y2);
        setcolor(WHITE);
    }

    void ManageDisplay(int color)  // function to manage the activity on display
    {
        ToggleLight(color);
        SwitchBox();
    }

    void InputManager()  // controls the input of the user
    {
        char ch;
        int color=0;
        while(ch!=27)
        {
            ch=getch();

            if(ch=='a'||ch=='A')
            {
                 color=yellow;
            }
            else if(ch=='z'||ch=='Z')
            {
                    color=red;
            }
            ManageDisplay(color);
        }

    }

    void ToggleLight(int color)  //toggle lights between On and OFF
    {

        if(Light==false)
        {
            cleardevice();
            if(color==yellow)
            {
                groundfloorcolor=yellow;
            }
            else if(color==red)
            {
                firstfloorcolor=red;

            }
        Light=true;
        Home();
      }
      else if(Light==true)
      {
        cleardevice();
        if(color==yellow)
        {
            groundfloorcolor =black;

        }
        else if(color==red)
        {
            firstfloorcolor =black;
        }
        Light=false;
        Home();
     }
  }

    void DrawColouredRectangle(int x1,int y1,int x2,int y2,int rectcolor)   // makes a coloured rectangle at the any given position
    {
        setfillstyle(SOLID_FILL,rectcolor);
        rectangle(x1,y1,x2,y2);
        floodfill(x1+2,y1+2,WHITE);
    }
    void DrawUpperFloorWalls()
    {
        //sidelines
         setcolor(RED);
         setfillstyle(SOLID_FILL,5);
         rectangle(510,194,998,344);
         floodfill(520,200,RED);
    }
    void DrawUpperFloorCircle()
    {
        setcolor(WHITE);
        setfillstyle(SOLID_FILL,BLUE);
        circle(764,144,20);
        floodfill(764,144,WHITE);

    }
    void DrawUpperFloorWindow()
    {
         setcolor(WHITE);
         DrawColouredRectangle(570,224,670,294,firstfloorcolor);
        //lowebasepfwindow
        DrawColouredRectangle(560,294,680,304,6);
        DrawColouredRectangle(820,224,920,294,firstfloorcolor);
        //lower base of 2 window
        DrawColouredRectangle(810,294,930,304,6);
    }
    void DrawUpperFloorRooftop()
    {
         line(510,194,764,94);
         line(998,194,764,94);
          //upper rooftop
         line(375,224,510,224);
         line(998,224,1153,224);
         line(375,224,764,44);
         line(1153,224,764,44);
         for(int colorindex=1;colorindex<=50;colorindex++)//to create no of lines for rooftop
         {
            setcolor(RED);
            line(375,224,764,44+colorindex);
            line(1153,224,764,44+colorindex);
        }
        for(int colorindex=1;colorindex<=160;colorindex++)//to create no. of lines for rooftop
        {
            setcolor(RED);
            line(764,94,375+colorindex,224);
            line(764,94,998+colorindex,224);
        }

    }
    void DrawGroundFloorRooftop()
    {
        setcolor(WHITE);
        DrawColouredRectangle(390,414,1138,424,6);
        line(375,414,1153,414);
        line(375,414,470,344);
        line(1153,414,1038,344);
        line(470,344,1038,344);
        for(int colorindex=1;colorindex<570;colorindex++) //to create no. of lines between the lower rooftaops
        {
            setcolor(BROWN);
            line(375+colorindex,414,470+colorindex,344);
        }
        for(int colorindex=1;colorindex<210;colorindex++)//to create no. of lines between the lower rooftaops
        {
            setcolor(BROWN);
            line(1153-colorindex,414,1038-colorindex,344);
        }
    }
     void DrawGroundFloorWalls()
     {
            setcolor(WHITE);
          // walls of ground floor
           setfillstyle(SOLID_FILL,5);
           line(470,424,470,624);
           line(1038,424,1038,624);
           floodfill(475,430,WHITE);
         //middlie lines in ground floor
           setcolor(WHITE);
           setfillstyle(SOLID_FILL,BROWN);
           line(764,424,764,624);
           line(754,424,754,624);
           floodfill(759,524,WHITE);
     }
      void DrawGroundFloorWindowsAndDoor()
      {
        //lower base
        setcolor(WHITE);
        DrawColouredRectangle(400,624,1128,678,2);
        //door
        DrawColouredRectangle(500,460,600,624,6);
        //doorwindow
        DrawColouredRectangle(510,470,590,540,groundfloorcolor);
        //main window
        DrawColouredRectangle(810,470,1000,540,groundfloorcolor);
                //lower base
        DrawColouredRectangle(800,540,1010,560,6);
        //side pillars of house
        DrawColouredRectangle(400,424,420,624,6);
        DrawColouredRectangle(1108,424,1128,624,6);
      }
    void UpperFloor()
    {
        DrawUpperFloorWalls();
        DrawUpperFloorRooftop();
        DrawUpperFloorCircle();
        DrawUpperFloorWindow();

    }
    void GroundFloor()
    {
        DrawGroundFloorWindowsAndDoor();
        DrawGroundFloorRooftop();
        DrawGroundFloorWalls();
    }
    void Home()
    {
        GroundFloor();// ground floor
        UpperFloor();//upper floor
    }
};

int main()
{
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
House h;
h.SwitchBox();
h.Home();
h.InputManager();
getch();
closegraph();
}
