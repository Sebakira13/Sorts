#include <iostream>
#include <time.h>
#include <math.h>
#include <cstdlib>
#include <stdio.h>
#include <vector>

using namespace std;

class Nodo
{
    private:
        int elemento;
    public:
        Nodo *sig;
        Nodo(int elemento)
        {
            this->elemento=elemento;
            sig=NULL;
        }
    int getElemento()
    {
        return elemento;
    }
};

class ListaSimple
{
    private:
        Nodo* head;
    public:
        ListaSimple()
        {
            head=NULL;
        }

    bool vacio()
    {
        return (head==NULL);
    }

    void ingresarDatoInicio(int elemento)
    {
        Nodo* temp=new Nodo(elemento);
        if(vacio()==true)
        {
            head=temp;;
        }
        else
        {
            temp->sig=head;
            head=temp;
        }
    }
    void ingresarDatoFinal(int elemento)
    {
        Nodo* temp=new Nodo(elemento);

            if(vacio()==true)
            {
                head=temp;
            }
            else
            {
                Nodo* aux=head;
                while(aux->sig!=NULL)
                {
                    aux=aux->sig;
                }
            aux->sig=temp;
            }
    }

    void mostrarLista()
    {
        if(vacio()==true)
        {
            cout<<"No hay elemento en la lista"<<endl;
        }
        else
        {
            Nodo* aux=head;
            int i=1;
            cout<<"Los datos de la lista son los siguientes"<<endl;
            while(aux!=NULL)
            {
                cout<<"El elemento "<<i<<" de la lista es: "<<aux->getElemento()<<endl;
                aux=aux->sig;
                i++;
            }
        }
    }

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

    double ingresarOrdenado(int arreglo[],int largo)
    {
            merge_sort(arreglo, 0, (largo-1));
            for(int i=0;i<largo;i++)
            {
                ingresarDatoFinal(arreglo[i]);
            }
    }

    void ingresarArreglo(int arreglo[], int largo)
    {
        for(int i=0;i<largo;i++)
        {
            ingresarDatoInicio(arreglo[i]);
        }
    }
};
int main()
{
    for(int i=0;i<20;i++)
    {
        ListaSimple* l1=new ListaSimple();



        int largo=10000;
        int arreglo[largo];
        for(int j=0;j<largo;j++)
        {
            arreglo[j]=rand();
            l1->ingresarDatoFinal(arreglo[j]);
        }

        clock_t t1,t2;
        t1=clock();
        double difference, seconds, tiempo;



        l1->ingresarDatoFinal(1);
        //l1->ingresarDatoInicio(1);

        t2=clock();
        difference= (((float)t2)-((float)t1));
        seconds = difference/1000;


        cout <<i+1 <<".- "<< seconds << endl;
        delete l1;
    }
}
