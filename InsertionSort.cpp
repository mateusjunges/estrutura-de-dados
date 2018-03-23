#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void troca(int &a, int &b)
{
    int c;
    c=a;
    a=b;
    b=c;
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
