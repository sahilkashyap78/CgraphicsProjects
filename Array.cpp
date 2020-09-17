#include<stdio.h>
#include<stdlib.h>
void append(struct Array *arr ,int element);
void DeleteElement(struct Array *arr,int index);
void popa(struct Array *arr);

void InsertElement(struct Array *arr,int index,int element);
void DispayArray(struct Array arr);

struct Array{
	int *A;
	int size;
	int length;
};



int main()
{
	
	struct Array arr;
	int i;
	
	printf("enter the size of the array: ");
	scanf("%d",&arr.size);
	
	arr.A= (int*)malloc(arr.size*sizeof(int));
	arr.length=0;
	
	int n;
	printf("enter the number of elements:");
	scanf("%d",&n);
	printf("enter the elements int the array!!");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr.A[i]);
	}
	
	arr.length=n;
	DispayArray(arr);
	DeleteElement(&arr,2);
	popa(&arr);
	DispayArray(arr);
	}

//for dispay of the arry
void DispayArray(struct Array arr)
{int i;
	printf("\nThe elements of the array is: ");
	for( i=0;i<arr.length;i++)
	{
		printf("\n%d",arr.A[i]);
	}
}


//for insertion in the array at particula indez



void InsertElement(struct Array *arr,int index,int element)
{
	
	int i =arr->length;
	while(i!=index)
	{
		arr->A[i]=arr->A[i-1];
		i--;
	}
	
	arr->A[index]=element;
	arr->length++;
	
}


//for insertion at the end

void append(struct Array *arr ,int element)
{
if(arr->length<arr->size)
{
	arr->A[arr->length++]=element;
}
	
}



//deletion from particular index

void DeleteElement(struct Array *arr,int index)
{
	if(arr->length>0)
{
	arr->length--;
	for(int i=index;i<arr->length;i++)
	{
		arr->A[i]=arr->A[i+1];
	}


}
}
//deletion from end

void popa(struct Array *arr)
{
	if(arr->length>0)
{
	arr->length--;
	


}
}

