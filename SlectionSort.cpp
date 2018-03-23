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

void selectionSort(int v[], int TAM)
{
    int atual;
    for(int i=0;i<TAM-1;i++)
    {
        atual=i;
        for(int j=i+1;j<TAM;j++){
            if(v[atual]>v[j])
            {
                atual=j;
            }
        }
        troca(v[i],v[atual]);
    }
}
