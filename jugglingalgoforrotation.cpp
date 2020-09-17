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


int gcd(int a,int b)
{
	if(a==0)
	{
		return b;
	}
	else{
return gcd(b%a,a);
	}
	
	
}


void rotateright(int a[],int len,int d)
{
	
	int g=gcd(len,d);
//	cout<<g;
	for(int i=0;i<g;i++)
	{
	//	cout<<"loopcheck1";
		int j=(len+i)-d;
		int temp=a[(len+i)-d];
		
		while(1)
		{
			//cout<<"check1";
			int k=j-2;
		
			
			
		    if(j==i)
				break;
				
			//if(k<=0)
				//cout<<"condition check";
		    	//k=k+2;									
				
				
			a[j]=a[k];
			j=k;
		}
		//cout<<"check2";
		a[j]=temp;
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
	
	
	int a[100]={1,2,3,4,5,6,7,8,9,10};
	
//	shiftnegative(a,10);
	//rotateleft(a,10,2);
	rotateright(a,10,2);
	diplay(a,10);
	}
