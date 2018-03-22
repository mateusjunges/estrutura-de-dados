#define TAM 10
#include<stdio.h>
#include <conio.h>

int lista[TAM];
int tamanho=0;

void insereLista(int valor){
    int i;
    if(tamanho == TAM-1){
        printf("\nLista cheia!");
        return;
    }
    for(i=tamanho; i>=0 && lista[i-1] > valor; i--){
        lista[i] = lista[i-1];
    }
    lista[i]=valor;
    printf("\nValor Inserido!");
    tamanho++;

}

void removeLista(int valor){
    int i, j;
    for(i=0; i<tamanho && valor >=lista[i]; i++){
        if(lista[i]==valor){
            for(j=i; j<tamanho-1; j++){
                lista[j]=lista[j+1];
            }
            tamanho--;
            printf("\nRemovido com sucesso!");
            return;
        }
    }
    printf("Não Encontrado!");
}

void buscaLista(int valor){
    int i=0;
    while(i <= tamanho){
        if(lista[i]==valor){
            printf("\nA posicao de %d na lista e: %d ",valor, i);
        }
        i++;
    }
    if(i > tamanho){
        printf("\nO elemento %d nao esta na lista", valor);
    }
}

void imprime(){
    int i=0;
    if(tamanho == 0){
        printf("\nLista vazia");
        return;
    }
    while(i<=tamanho-1){
        printf("\n%do elemento da lista: %d",i+1,lista[i]);
        i++;
    }
}

void recuperaLista(int posicao){
    if(posicao > tamanho-1 || posicao<0){
        printf("Posicao invalida!");
    }else{
        printf("\nNa posicao %d esta o elemento %d", posicao, lista[posicao]);
    }
}

main(){
    insereLista(10);
    removeLista(50);
    buscaLista(20);
    imprime();
    recuperaLista(0);
}
