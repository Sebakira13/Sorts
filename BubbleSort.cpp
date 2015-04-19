#include <iostream>
#include <time.h>
#include <math.h>
#include <cstdlib>
#include <stdio.h>
#include <vector>

using namespace std;

 double BubbleSort(int arreglo[],int n)
{
    clock_t t1,t2;
    t1=clock();
    double difference, seconds, tiempo;
    int temp;
    for(int i=0; i<n; i++)
   {
         for(int j=i; j<n; j++)
         {
                   if(arreglo[j]>arreglo[i])
                       {
                        temp=arreglo[j];
                        arreglo[j]=arreglo[i];
                        arreglo[i]=temp;
                       }
         }
   }
    t2=clock();
    difference= (((float)t2)-((float)t1));
    seconds = difference/1000;

    //for(int i=0;i<n;i++)
    //{
    //    cout<<arreglo[i]<<endl;
    //}

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
        arreglo[i]=rand();
    }

    cout <<j+1 <<".- "<< BubbleSort(arreglo, n) << endl;
    }

}
