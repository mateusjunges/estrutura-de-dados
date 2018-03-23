
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

void mergeSort(int v[], int aux[], int inicio, int fim)
{
    int meio;
    int L, H;
    if(inicio < fim)
    {
        meio=(inicio+fim)/2;
        mergeSort(v, aux, inicio, meio);
        mergeSort(v, aux, meio+1, fim);
        L=inicio;
        H=meio+1;
        for(int i=inicio; i<=fim;i++)
        {
            if(L<=meio && (H>fim || v[L] < v[H])){
                aux[i]=v[L];
                L++;
            }
            else{
                aux[i]=v[H];
                H++;
            }
        }
        for(int i=inicio; i<=fim;i++)
        {
            v[i]=aux[i];
        }
    }
}
