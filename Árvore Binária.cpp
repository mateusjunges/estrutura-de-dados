#include <iostream>

using namespace std;

struct no {
    int dado;
    struct no *esq;
    struct no *dir;
};
struct no *raiz = NULL;

void insere(int valor);
void insereArvoreSemRepetidos(int valor);
bool vazia();
void buscaArvore(int valor);
void em_ordem(struct no *atual);

int main() {
    insere(15);
    insere(20);
    insere(2);
    insere(-1);
    insere(-2);
    buscaArvore(-1);
    em_ordem(raiz);


    return 0;
}

void insere(int valor) {
    struct no *atual;
    struct no *anterior;
    struct no *aux;

    aux = new(struct no);
    aux->dado = valor;
    aux->esq = NULL;
    aux->dir = NULL;

    atual = raiz;

    if (atual == NULL) {
        raiz = aux;
        return;
    } else {
        while(atual != NULL) {
            anterior = atual;
            if(valor < atual-> dado) {
                atual = atual->esq;
            } else {
                atual = atual -> dir;
            }
        }
        if(valor < anterior -> dado) {
            anterior->esq = aux;
        } else {
            anterior->dir = aux;
        }
    }

}

void insereArvoreSemRepetidos(int valor) {
    struct no *atual;
    struct no *anterior;
    struct no *aux;

    aux = new(struct no);
    aux->dado = valor;
    aux->esq = NULL;
    aux->dir = NULL;

    atual = raiz;

    if (atual == NULL) {
        raiz = aux;
        return;
    } else {
        while(atual != NULL) {
            anterior = atual;
            if(valor<atual->dado) {
                atual = atual->esq;
            } else if(valor>atual->dado) {
                atual = atual->dir;
            } else {
                cout<<"Valor duplicado nao pode ser adicionado"<<endl;
                return;
            }
        }
        if(valor<anterior->dado) {
            anterior->esq = aux;
        } else {
            anterior->dir = aux;
        }
    }

}

bool vazia() {

    if(raiz==NULL)
        return true;

    else return false;

}

void em_ordem(struct no *atual) {
    if (atual!=NULL) {
        em_ordem(atual->esq);
        cout<<atual->dado<<endl;
        em_ordem(atual->dir);
    }
}

void buscaArvore(int valor) {

    struct no *atual;
    struct no *anterior;

    atual = raiz;
    if (atual == NULL) {
        cout<<"Arvore vazia!!!"<<endl;
        return;
    } else {
        while(atual != NULL) {
            anterior = atual;
            if(valor < atual -> dado) {
                atual = atual -> esq;
            } else if(valor > atual -> dado) {
                atual = atual -> dir;
            } else {

                cout<< "ACHEI: "<< atual -> dado << endl;
                return;
            }
        }
        cout<<"Elemento nao encontrado"<<endl;
    }
}
