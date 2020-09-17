#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<iostream>
using namespace std;


class RangedMultiples{

         public:
            int Firstnumber,Lastnumber; //firt number and last number of range;
            int Number;
     void SetRange()
     {
            cout<<"Enter the range followed by space between the two number: "<<endl;
            cin>>Firstnumber>>Lastnumber;
            cout<<"Enter the Number whose multiples have to found: "<<endl;
            cin>>Number;
            int range =(Lastnumber-Firstnumber);  //to calculate the range
            if(range<=0||Number<0) //if lastnumber is smaller than the first number
            {
                cleardevice();
                cout<<"Please Enter the valid Range or Valid Number "<<endl;
                  SetRange();

            }
    }


    void FindMultiples()
    {
        int FirstNumberCounter=0;//we increment this counter until we not find the corresponding equal or greater multiple than firstnumber
        int LastNumberCounter=0;//we increment this counter until we not find the corresponding equal or greater multiple than lastnumber
        int MultipleCounter=0;//to count the number of multiples
        while(Number*FirstNumberCounter<Firstnumber)
        {
            FirstNumberCounter++;

        }
        while(Number*LastNumberCounter<Lastnumber)
        {

            LastNumberCounter++;
        }
        if(Lastnumber%Number!=0)
        {
            LastNumberCounter--;
        }
        if(LastNumberCounter==FirstNumberCounter)
        {
            if(Firstnumber%Number==0)
            {
                cout<<"The multiples of given "<<Number<<" is only "<<Number*FirstNumberCounter;
                return;
            }
            else if(Lastnumber%Number==0)
            {
                cout<<"The multiples of given "<<Number<<" is only "<<Number*FirstNumberCounter;
                return;
            }
        }

         cout<<"The Multiples of the number "<<Number<<" are"<<endl;
         for(int index=FirstNumberCounter;index<=LastNumberCounter;index++)
         {
             MultipleCounter++;
             cout<<Number*index<<endl;
         }
         cout<<"The Total Number of Multiples are "<<MultipleCounter<<endl;

    }

};


int main()
{
    RangedMultiples r;
    r.SetRange();
    r.FindMultiples(); //function to calculate the number of multiples of the target numnber
    getch();
}
