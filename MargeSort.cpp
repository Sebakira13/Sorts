#include <iostream>
#include <time.h>
#include <math.h>
#include <cstdlib>
#include <stdio.h>
#include <vector>

using namespace std;



void merge(int a[], const int low, const int mid, const int high)
{
	// Variables declaration.
	int * b = new int[high+1-low];
	int h,i,j,k;
	h=low;
	i=0;
	j=mid+1;

	while((h<=mid)&&(j<=high))
	{
		if(a[h]<=a[j])
		{
			b[i]=a[h];
			h++;
		}
		else
		{
			b[i]=a[j];
			j++;
		}
		i++;
	}

	if(h>mid)
	{
		for(k=j;k<=high;k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	else
	{
		for(k=h;k<=mid;k++)
		{
			b[i]=a[k];
			i++;
		}
	}

	for(k=0;k<=high-low;k++)
	{
		a[k+low]=b[k];
	}
	delete[] b;

}

void merge_sort( int a[], const int low, const int high )
{
	int mid;
	if( low < high )
	{
		mid = ( low + high ) / 2;
		merge_sort( a, low, mid );
		merge_sort( a, mid + 1, high );
		merge( a, low, mid, high );
	}
}

int main()
{
for(int j=0;j<20;j++)
{
    int arraySize=1000000;
    int * arreglo = NULL;
    arreglo = new int [arraySize];
	for(int i=0;i<arraySize;i++)
        {
            arreglo[i]=rand();
        }


    clock_t t1,t2;
    t1=clock();
    double difference, seconds, tiempo;

	merge_sort(arreglo, 0, (arraySize-1) );

    t2=clock();
    difference= (((float)t2)-((float)t1));
    seconds = difference/1000;
    cout<<j+1<<".- "<<seconds<<endl;

    //for(int i=0;i<arraySize;i++)
    //{
    //    cout<<arreglo[i]<<endl;
    //}
    delete arreglo;
}

    return 0;


}
