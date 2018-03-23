#include <iostream>

const int TAM = 5;

int pilha[TAM];
int topo=-1;

using namespace std;

void push(int n)
{
    if(topo==TAM-1)
        cout << "Pilha cheia" << endl;
    else
    {
        topo++;
        pilha[topo]=n;
    }
}

bool vazia()
{
    if(topo==-1)
        return true;
    else
        return false;
}

void pop()
{
    if(!vazia()) topo--;
    else cout << "Pilha está vazia" << endl;
}

void topoPilha()
{
    cout << "Elemento do topo: " << pilha[topo] << endl;
}
