#include<iostream>

using namespace std;

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
	
}



void rotateleft(int a[],int len,int d)
{
	
	int temp[len];
	
	for(int i=0;i<d;i++)
	{
		temp[i]=a[i];
	}
	int x=0;
	for(int i=d;i<len;i++)
	{
	a[x]=a[i];
	x++;
	}
	for(int i=0;i<d;i++)
	{
		a[x]=temp[i];
		x++;
	}
	
	
	
}



void rotateright(int a[],int len,int d)
{
	
	int temp[len];
	int x=len-d;
	for(int i=0;i<d;i++)
	{
		temp[i]=a[x];
		x++;		
	}
	int index=0;
	for(int i=d;i<len;i++)
	{
	temp[i]=a[index];
	index++;
	}
	for(int i=0;i<len;i++)
	{
		a[i]=temp[i];
		
	}
	
	
	
}




void shiftnegative(int a[],int len)
{
	int i=0;
	int j=len-1;
	
	while(i<j)
	{
	while(a[i]<0)
{
	i++;
		}
		
	
	while(a[j]>0)
{
	j--;
		}
	
		if(i<j)
		{
			swap(&a[i],&a[j]);
		}
		
				
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
	
//	shiftnegative(a,10);
	//rotateleft(a,10,2);
	rotateright(a,10,2);
	diplay(a,10);
	
}
