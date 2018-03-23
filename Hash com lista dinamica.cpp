#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int TAM = 10;
const int NUMVEZES = 5;

struct no
{
    int dado;
    struct no *prox;
};
struct no *vetorHash[TAM];
int chave;

void preencheVetor(struct no * v[])
{
    for(int i=0; i < TAM; i++)
        v[i]=NULL;
}

int h(int chave)
{
    return chave%TAM;
}


void insere(int chave)
{
    int pos  = h(chave);
    struct no *aux;
    aux = new(struct no);
    aux->dado=chave;
    aux->prox=vetorHash[pos];
    vetorHash[pos]=aux;
}

int busca(int chave)
{
    int pos  = h(chave);
    struct no *atual=vetorHash[pos];
    int col;

    while(1)
    {
        if(atual==NULL)
            break;
        else
            if(atual->dado!=chave){
                atual=atual->prox;
                col++;
            }
            else
                break;
    }
    if(atual!=NULL && atual->dado==chave)
    {
        cout << "Achou " << endl << "Colisoes " << col << endl;
        return col;
    }
    cout << "Não achou" << endl << "Colisoes " << col << endl;
    return col;
}

void deleta(int chave)
{
    int pos  = h(chave);
    struct no *atual=vetorHash[pos];
    struct no *anterior=NULL;

    while(1)
    {
        if(atual==NULL)
            return;
        else
            if(atual->dado!=chave){
                anterior=atual;
                atual=atual->prox;
            }
            else
            {
                if(anterior==NULL)
                    vetorHash[pos]=atual->prox;
                else
                    anterior->prox=atual->prox;
                delete(atual);
                return;
            }
    }
}
