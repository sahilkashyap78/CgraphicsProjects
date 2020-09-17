#include<iostream>
#include<math.h>


//FindMagnitude
//FindAddition
//FindDotProduc

using namespace std;


class vect2d
{
	public :
		int x;
		int y;
		
	
	
	vect2d()
	{
		x=1;
		y=1;
	}
	
	void setX(int x)
		{
			this->x=x;
		}
	
	void setY(int y)
	{
		this->y=y;
	}
	
	void setXY(int x,int y)
	{
		this->x=x;
		this->y=y;
	}
	
	double FindMagnitude()
	{
	double sum =x*x+y*y;
	return sqrt(sum);
		
	}
	
     void FindAddition(vect2d a,vect2d b)
	{
		
		x=a.x+b.x;
		y=a.y+b.y;
		
	}
	
	void DotProduct(vect2d a,vect2d b)
	{
		
		x=a.x*b.x;
		y=a.y*b.y;
		
		
	}
	
	void displayvector()
	{
		cout<<"the vector is:"<<" "<<x<<" i "<<y<<" j "<<endl;
	}
	
	
};




class vect3d:public vect2d
{
	
	public :
		int z;
		
		
		void setZ(int z)
		{
			this->z=z;
		}


	void displayvector()
	{
		cout<<"the vector is:"<<" "<<x<<" i "<<y<<" j "<<z<<" k "<<endl;
	}
	
	
	
	
	
	double FindMagnitude()
	{
	double sum =x*x+y*y+z*z;
	return sqrt(sum);
		
	}
	
     void FindAddition(vect3d a,vect3d b)
	{
		
		x=a.x+b.x;
		y=a.y+b.y;
		z=a.z+b.z;
	}
	
	void DotProduct(vect3d a,vect3d b)
	{
		
		x=a.x*b.x;
		y=a.y*b.y;
		z=a.z*b.z;
		
	}
	
	
	
	
	
	
	
};





int main()
{
	
	vect3d a;
	a.setXY(10,20);
	a.setZ(30);
	vect3d b;
	b.setXY(40,20);
	b.setZ(10);
	vect3d c;
	c.FindAddition(a,b);
	c.DotProduct(a,b);
	c.displayvector();
	/*vect2d a;
	vect2d b;
	a.setXY(10,20);
	b.setXY(20,10);
	vect2d c;
	c.DotProduct(a,b);
	c.FindAddition(a,b);
	c.displayvector();
	*/
	}
