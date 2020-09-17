#include<iostream>

using namespace std;

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
	
}




void shiftnegative(int a[],int len)
{
	int x=0;
	int y=0;
	int b[len];
	for(int i=0;i<len;i++)
	{
		if(a[i]<0)
		{
			b[x]=a[i];
			x++;
		}
	}

for(int i=0;i<len;i++)
	{
		if(a[i]>0)
		{
			b[x]=a[i];
			x++;
		}
	}

for(int i=0;i<len;i++)
	{
		a[i]=b[i];
	}


}


void diplay(int a[],int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<a[i]<<endl;
	}
}


int main()
{
	
	
	int a[100]={-6,3,-8,10,5,-7,-9,12,-4,2};
	
	shiftnegative(a,10);
	
	diplay(a,10);
	
}
