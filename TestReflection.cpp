# include <graphics.h>
# include <iostream>
# include <conio.h>

# include <math.h>
#include<stdlib.h>

using namespace std;


class MirroredText{
public:
    long width = GetSystemMetrics(SM_CXSCREEN);
    long height = GetSystemMetrics(SM_CXSCREEN);
    char TextString[1000];
    char  *image;
    long imgsize;
    void CreatePartition()
    {

    line(width/2,0,width/2,height);
    }


 void GetString()
 {
     printf("Enter the string:");
     gets(TextString);


 }
void SetString()
{

    settextstyle(1,0,5);
    outtextxy(width/4,height/4,TextString);
    imgsize =imagesize((width/4)-10,(height/4)-10,(width/4)+240,(height/4)+60);
//imgsize=imagesize((width/4)+240,(height/4)+60,(width/4)-10,(height/4)-10);
    image =(char *)malloc(imgsize);


    getimage((width/4)-10,(height/4)-10,(width/4)+240,(height/4)+60,image);



//printimage(image,200,200,200,(((width/2)+width)/2)+200,(height/4)+60,(((width/2)+width)/2)-10,(height/4)-10);
//readimagefile("ska.bmp",100,100,500,500);
    putimage((((width/2)+width)/2)-10,(height/4)-10,image,XOR_PUT);



    }

};

int main()
{
    int gdriver=DETECT,gmode;

    initgraph(&gdriver,&gmode,"");
    MirroredText m;
    m.CreatePartition();
    m.GetString();
    m.SetString();





    getch();
    closegraph;

}
