#include <iostream>
#include <time.h>
#include <math.h>
#include <cstdlib>
#include <stdio.h>
#include <vector>

using namespace std;

void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
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

            quickSort(arreglo,0,arraySize-1);

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
