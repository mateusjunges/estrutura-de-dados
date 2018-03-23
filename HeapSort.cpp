#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


void troca(int &v1, int &v2)
{
    int aux;
    aux=v1;
    v1=v2;
    v2=aux;
}

void heapify(int v[], int TAM, int tamHeap, int atual)
{
    int esq=2*atual+1;
    int dir=2*atual+2;
    int maior;

    if(esq<tamHeap && v[esq]>v[atual])
        maior=esq;
    else
        maior=atual;
    if(dir<tamHeap && v[dir]>v[maior])
        maior=dir;
    if(maior!=atual)
    {
        troca(v[atual], v[maior]);
        heapify(v,TAM,tamHeap,maior);
    }
}

void buildHeap(int v[], int TAM)
{
    int tamHeap=TAM;
    for(int i=(TAM/2)-1; i>=0;i--)
        heapify(v,TAM,tamHeap,i);
}

void heapSort(int v[], int TAM)
{
    int tamHeap = TAM;
    buildHeap(v, TAM);
    for(int i=TAM-1; i>=1; i--)
    {
        troca(v[0],v[i]);
        tamHeap--;
        heapify(v, TAM, tamHeap, 0);
    }
}
