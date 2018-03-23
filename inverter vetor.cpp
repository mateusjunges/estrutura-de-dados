#include <iostream>

#define TAM 10;

using namespace std;

int vetor1[TAM], vetor2[TAM];

int main()
{
    for(int i=0; i<TAM; i++)
        cin >> vetor1[i];
    for(int i=0; i<TAM; i++)
        vetor2[i] = vetor1[TAM -1 - i];
    for(int i=0; i<TAM; i++)
        cout << vetor2[i];

    return 0;
}
