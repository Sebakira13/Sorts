#include <iostream>
#include <time.h>
#include <math.h>
#include <cstdlib>
#include <stdio.h>
#include <vector>

using namespace std;

double selectSort(int arreglo[], int n)
{
    clock_t t1,t2;
    t1=clock();
    double difference, seconds, tiempo;
	int pos_min,temp;

	for (int i=0; i < n-1; i++)
	{
	    pos_min = i;

		for (int j=i+1; j < n; j++)
		{

		if (arreglo[j] < arreglo[pos_min])
                   pos_min=j;

		}
            if (pos_min != i)
            {
                 temp = arreglo[i];
                 arreglo[i] = arreglo[pos_min];
                 arreglo[pos_min] = temp;
            }
	}

	t2=clock();
    difference= (((float)t2)-((float)t1));
    seconds = difference/1000;

    return seconds;

}

int main()
{
    for(int j=0;j<20;j++)
    {
        int n=10000;
        int arreglo[n];
        for(int i=0;i<n;i++)
        {
            arreglo[i]=rand()%100000;
        }

    cout <<j+1 <<".- "<< selectSort(arreglo, n) << endl;
    }

}
