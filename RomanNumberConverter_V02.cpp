#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<iostream>
#include<map>
#include<string.h>
#define Endvalue 9999
#define length 13
using namespace std;

class RomanNumberConvertor
{

private:
    int width =GetSystemMetrics(SM_CXSCREEN); //width of screen
    int height =GetSystemMetrics(SM_CYSCREEN);  //height of screen
    int keyArray[13]={1,4,5,9,10,40,50,90,100,400,500,900,1000};  //keys
    char valueArray[13][10] ={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"}; //values of keys
    long Number=0;//  number on which operation performs
    char Numberchar[10]; // for displaying the  number on graphics screen
    char RomanNumber[100]=" "; // is used to display the roman number that gets converted by performing operation on the  number
    enum State{
    DecimalState,RomanState
    };
    State currentstate;
public:
    RomanNumberConvertor()
    {
        currentstate =DecimalState;
    }
    //  function used for outtextxy
    void InstantiateText(int x,int y,char *text)
    {
     outtextxy(x,y,text);
    }
    void SetValuesToZero()
    {
        Number=0;
        strcpy(RomanNumber," ");
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
        InstantiateText((width/4)-100,(height/4)-75,"ROMAN NUMBER CONVERTOR");
        ColouredRectangle(width/4,height/4,(width/2+width)/2,((height/2+height)/2)-150,RED);
    }

    // function to diplay the multiple outetextxy
    void TextGroup(int x,int y, char *text1,char *text2)
    {
        setcolor(WHITE);
        InstantiateText(x,y,text1);
        InstantiateText(x,y+150,text2);
    }


// to create the user interface
    void UserInterface()
    {
        char labeltext1[100],labeltext2[100],textboxtext1[100],textboxtext2[100],Statetext[100];//for diplaying the values according to the currentstate.
        if(currentstate==RomanState)
        {
            strcpy(labeltext1,"Decimal Number");
            strcpy(labeltext2,"Roman Number");
            strcpy(textboxtext1,Numberchar);
            strcpy(textboxtext2,RomanNumber);
            strcpy(Statetext,"Decimal Number");
        }
        else if(currentstate==DecimalState)
        {
            strcpy(labeltext1,"RomanNumber");
            strcpy(labeltext2,"DecimalNumber");
            strcpy(textboxtext1,RomanNumber);
            strcpy(textboxtext2,Numberchar);
            strcpy(Statetext,"Roman Number");
        }
          CreateBackground();
          settextstyle(1,0,3);
          TextGroup((width/4)+25,(height/4)+25,labeltext1,labeltext2);
          TextBox((width/4)+400,(height/4)+15,(width/4)+800,(height/4)+60);
          TextBox((width/4)+400,(height/4)+165,(width/4)+800,(height/4)+205);
          settextstyle(3,0,1);
          TextGroup((width/4)+410,(height/4)+27,textboxtext1,textboxtext2);
          InformationBox((width/4)+15,(height/4)+325,(width/4)+200,(height/4)+425,(width/4)+25,(height/4)+335,"Press G","To Convert",Statetext);
          InformationBox((width/4)+600,(height/4)+325,(width/4)+735,(height/4)+425,(width/4)+610,(height/4)+335,"Press X","To Terminate","Program");

    }
    //function to convert the  number into roman number
    void RomanConversion()
    {
        int endvalue =keyArray[length-1];//the last value to compare with in the keyarray
        int totalkeys =length;
        cout<<"Enter the Number you want to convert"<<endl;
        cin>>Number;
        if(Number<=0|| Number>Endvalue)
        {
            cout<<"Enter the Valid Number!!!"<<endl;
            RomanConversion();
        }
        else
        {
                sprintf(Numberchar,"%d",Number);
                while(Number>0)
                {
                    int counter=0;  //to get the index of our keys and values
                    if(Number>=endvalue)
                    {
                        counter =totalkeys;  //points to the last key in the array
                    }
                    else
                    {
                        while(Number>=keyArray[counter])
                        {
                            counter++;
                        }
                    }

                    int value =Number/keyArray[counter-1];
                    for(int index=0;index<value;index++)
                    {
                            strcat(RomanNumber,valueArray[counter-1]);
                    }

                    Number =Number%keyArray[counter-1];

                }
        }

    }


//function to convert roman number to the decimal number
    void DecimalCoversion()
    {
        cout<<"Enter The Roman Number You want to Convert: "<<endl;
        cin>>RomanNumber;
        for(int index =0;RomanNumber[index]!='\0';index++)
        {
            int pointer =0;  // TO GET THE POINTER TO THAT NUMBER CORRESPONDING TO THE ROMAN NUMBER
            static int RomanValueHolder=0;
            while(valueArray[pointer][0]!=RomanNumber[index])  //until we get the matcing roman number
            {
                pointer++;
            }
            if(keyArray[pointer]>RomanValueHolder)
            {
                Number+=(keyArray[pointer]-RomanValueHolder); //add the keyarray corresponding to the valuearray.
                Number-=RomanValueHolder;
                RomanValueHolder=keyArray[pointer];
            }
            else if(keyArray[pointer]<=RomanValueHolder)
            {
                Number+=keyArray[pointer];
                RomanValueHolder =keyArray[pointer];
            }
        }
        sprintf(Numberchar,"%d",Number); //conversion of number to numberchar

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
                 cleardevice();
                 SetValuesToZero();
                 if(currentstate==RomanState)
                 {
                        currentstate=DecimalState;
                        DecimalCoversion();

                 }
                 else if(currentstate==DecimalState)
                 {

                        currentstate=RomanState;
                        RomanConversion();

                 }
                 UserInterface();
            }
            else if(ch=='x'||ch=='X')
            {
                    exit(0);
            }
        }

    }

};

int main()
{
    int gDriver=DETECT,gMode;
    initgraph(&gDriver,&gMode,"");
    RomanNumberConvertor r;
    r.DecimalCoversion();
    r.UserInterface();
    r.InputManager();
    getch();
    closegraph();
}
