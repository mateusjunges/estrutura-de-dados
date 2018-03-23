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


void insertionSort(int v[], int TAM)
{
    int aux, i;
    bool achou;
    for(int j=1; j<TAM;j++)
    {
        aux=v[j];
        i=j-1;
        achou=false;
        while(!achou && i>=0)
        {
            if(v[i]>aux)
            {
                troca(v[i+1], v[i]);
                i--;
            }
            else
                achou=true;
        }
    }
}
