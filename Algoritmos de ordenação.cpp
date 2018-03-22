#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 40000

int A[TAM];
clock_t tempo1, tempo2;
int tam_heap = TAM;
int scratch[TAM];

int gera_vetor(){

    for(int i=0; i<TAM; i++){
        A[i]=rand();
    }
}

bubble_sort(){
 int pass = 1;
 bool sorted = false;
 int aux;

 while(sorted==false && pass < TAM){
    sorted=true;
       for(int i=0; i<=TAM-pass-1; i++){
        if (A[i] > A[i+1]){
            aux = A[i];
            A[i] = A[i+1];
            A[i+1]=aux;
            sorted =false;
        }
       }
       pass = pass + 1;
 }
}


int particao (int p, int r){
 int piv = A[p];
 int i= p - 1;
 int j= r + 1;
 int aux;
 while (true){
    do{
       j = j - 1;	// do..while
       }while (A[j] > piv);
       do{
         i = i + 1;	// do..while
         }while (A[i] < piv);
       if (i < j){
          aux = A[i];
          A[i] = A[j];
          A[j]=aux;
       }else {
            return j;
            }
    }
}

void quicksort(int p, int r){
    int q;
    if (p < r){
        q = particao (p, r);
         quicksort (p, q);
         quicksort (q+1, r);
    }
}

void heapify(int i){
int l;
int r;
int aux;
int max;
    l = 2*i+1;
    r = 2*i+2;

    if(l < tam_heap && A[l] > A[i]){
        max=l;
    }else{
        max=i;
    }
    if(r < tam_heap && A[r] > A[max]){
        max=r;
    }
    if(max != i){
        aux = A[i];
        A[i] = A[max];
        A[max] = aux;
        heapify(max);
    }
}

void build_heap(){
    tam_heap = TAM;
    for(int j=(TAM/2)-1; j>=0; j--){
        heapify(j);
    }
}

void heapsort(){
    int aux;
    build_heap();
    for(int k=TAM-1; k>=1; k--){
        aux = A[0];
        A[0] = A[k];
        A[k] = aux;
        tam_heap = tam_heap-1;
        heapify(0);
    }
}

void selection_sort(){
    int current;
    int aux;
    for(int i=0; i < TAM-2; i++){
        current = i;
        for(int k=i; k < TAM-1; k++){
            if(A[current] > A[k]){
                current = k;
            }
        }
        aux = A[i];
        A[i] = A[current];
        A[current]=aux;
    }
}

void insertion_sort(){
    for(int k=1; k < TAM-1; k++){
        int x = A[k];
        int i = k-1;
        bool found = false;
        while(!found && i>=0){
            if(A[i]>x){
                int aux = A[i+1];
                A[i+1]=A[i];
                A[i]=aux;
                    i--;
            }else{
                found=true;
            }
        }
    }
}

void mergesort(int lo, int hi){
    if(lo < hi){
        int mid = (lo+hi)/2;
        mergesort(lo, mid);
        mergesort(mid + 1, hi);
        int L = lo;
        int H = mid +1;
        for(int k = lo; k <=hi; k++){
            if(L <=mid && (H > hi || A[L] < A[H])){
                 scratch[k]= A[L];
                 L++;
            }else{
                scratch[k] = A[H];
                H++;
            }
        }
        for(int k = lo; k <=hi; k++){
            A[k] = scratch[k];
        }
    }
}



main(){
    gera_vetor();
    tempo1 = clock();
    mergesort(0, TAM-1);
    tempo2 = clock()-tempo1;
    printf("\n MergeSort: %f segundos",(float) tempo2/CLOCKS_PER_SEC);
    gera_vetor();
    tempo1 = clock();
    insertion_sort();
    tempo2 = clock()-tempo1;
    printf("\n InsertionSort: %f segundos",(float) tempo2/CLOCKS_PER_SEC);
    gera_vetor();
    tempo1 = clock();
    selection_sort();
    tempo2 = clock()-tempo1;
    printf("\n Selection: %f segundos",(float) tempo2/CLOCKS_PER_SEC);
    gera_vetor();
    tempo1 = clock();
    heapsort();
    tempo2 = clock()-tempo1;
    printf("\n HeapSort: %f segundos",(float) tempo2/CLOCKS_PER_SEC);
    gera_vetor();
    tempo1 = clock();
    bubble_sort();
    tempo2 = clock()-tempo1;
    printf("\n BubbleSort: %f segundos",(float) tempo2/CLOCKS_PER_SEC);
    gera_vetor();
    tempo1 = clock();
    quicksort(0,TAM-1);
    tempo2 = clock()-tempo1;
    printf("\n QuickSort: %f segundos",(float) tempo2/CLOCKS_PER_SEC);
   // for(int i =0; i<TAM; i++){
       // printf("\n %d", A[i]);
    //}
}
