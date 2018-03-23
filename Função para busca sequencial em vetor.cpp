void buscaSequencial(int valor){
   int i = 0;
    while(i < TAM){
        if(vetor[i] == valor){
            cout << endl << valor << " encontrado na posicao " << i << endl;
            return;
        }
        i++;
    }
    cout << endl << valor << " nao encontrado!" << endl;
