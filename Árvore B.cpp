1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
177
178
179
180
181
182
183
184
185
186
#include <cstdio>
#include <iostream>
#define ORDEM 300
#define MIN_OCUP (ORDEM-1)/2
#define MAX_CHAVES ORDEM-1
#include <cstdlib>

using namespace std;

struct no {
    int dado[ORDEM-1];
    struct no *filhos[ORDEM];
    int n_chaves;
};

int repetidoB=0;
int repetido=0;

struct no *raizB = NULL;

//Retorna a posição de uma chave em um determinado nó da árvore B
int encontra_chave_B(struct no *atual, int chave) {

    int i=0;

    while (i<atual->n_chaves && chave>atual->dado[i])
        i++;
    return i;
}

// Insere uma chave em um nó de uma árvore B
void insere_chave_B(struct no *atual, int chave, struct no *filhodir) {
    int i;

    for (i=atual->n_chaves ; i>0 && chave<atual->dado[i-1] ; i--) {
        atual->dado[i] = atual->dado[i-1];
        atual->filhos[i+1] = atual->filhos[i];
    }

    atual->dado[i] = chave;
    atual->filhos[i+1] = filhodir;
    atual->n_chaves++;

}

// Função auxiliar para inserir um valor em uma árvore B
struct no *insere(struct no *atual, int info, bool &h, int &info_retorno) {
    int i, pos,
        info_mediano, //auxiliar para armazenar a chave que ira subir para o pai
        pos_mediano;    //posicao do mediano;
    struct no *temp, *filho_dir; //ponteiro para o filho a direita da chave

    if (atual == NULL) {
        //O no anterior e o ideal para inserir a nova chave (chegou em um no folha)
        h = true;
        info_retorno = info;
        return NULL;
    } else {
        pos = encontra_chave_B(atual,info);
        if (atual->n_chaves > pos && atual->dado[pos] == info) {
         // printf("Chave ja contida na arvore -> %d \n",info);
            repetidoB++;
            h = false;
        } else {
            //desce na arvore ate encontrar o no folha para inserir a chave.
            filho_dir = insere(atual->filhos[pos],info,h,info_retorno);
            if (h) { //Se true deve inserir a info_retorno no no.
                if (atual->n_chaves < MAX_CHAVES) { //Tem espaco na pagina
                    insere_chave_B(atual, info_retorno, filho_dir);
                    h = false;
                } else { //Overflow. Precisa subdividir
                    temp = new (struct no);
                    temp->n_chaves = 0;

                    //inicializa filhos com NULL
                    for (i = 0; i < ORDEM; i++)
                        temp->filhos[i] = NULL;

                    if (pos<MIN_OCUP)
                        pos_mediano=MIN_OCUP-1;
                    if (pos>=MIN_OCUP)
                        pos_mediano=MIN_OCUP;
                    //elemento mediano que vai subir para o pai
                    if (pos==MIN_OCUP) {
                        info_mediano = info_retorno;
                        temp->filhos[0] = filho_dir;
                        insere_chave_B(temp, atual->dado[pos_mediano], atual->filhos[pos_mediano+1]);
                     }
                     else {
                            info_mediano = atual->dado[pos_mediano];
                            temp->filhos[0] = atual->filhos[pos_mediano+1];
                     }
                    //insere metade do no atual no temp (efetua subdivisao)
                    for (i = pos_mediano + 1; i < MAX_CHAVES; i++)
                        insere_chave_B(temp, atual->dado[i], atual->filhos[i+1]);

                    //atualiza na atual.
                    for (i = pos_mediano; i<MAX_CHAVES; i++) {
                        atual->dado[i] = 0;
                        atual->filhos[i+1] = NULL;
                    }
                    atual->n_chaves = pos_mediano;

                    //Verifica em qual no sera inserida a nova chave
                    if (pos < MIN_OCUP)
                        insere_chave_B(atual, info_retorno, filho_dir);
                    if (pos > MIN_OCUP)
                        insere_chave_B(temp, info_retorno, filho_dir);

                    //retorna o mediano para inseri-lo no no pai e o temp como filho direito do mediano.
                    info_retorno = info_mediano;
                    return temp;
                }
            }
        }
    }
}

// Insere uma chave em uma árvore B
struct no *insere_arvoreB(struct no *atual, int chave) {
    bool h;
    int info_retorno, i;
    struct no *filho_dir, *nova_raiz;

    filho_dir = insere(atual,chave,h,info_retorno);
    if (h) {
        //Aumetara a altura da arvore
        nova_raiz = new (struct no);
        nova_raiz->n_chaves = 1;
        nova_raiz->dado[0] = info_retorno;
        nova_raiz->filhos[0] = atual;
        nova_raiz->filhos[1] = filho_dir;
        for (i = 2; i <= MAX_CHAVES; i++)
            nova_raiz->filhos[i] = NULL;
        return nova_raiz;
    } else return atual;
}

void percurso(struct no *atual) {
    int i;

    if (atual!=NULL) {

        for (i=0; i<atual->n_chaves; i++) {
            percurso(atual->filhos[i]);
            printf("%d ",atual->dado[i]);
        }
        percurso(atual->filhos[atual->n_chaves]);
    }
}

// Conta o n�mero de n�s de uma ABM
int conta(struct no *atual) {

    int i, total;

    if (atual!=NULL) {
        total=1;
        for (i=0; i<atual->n_chaves+1; i++) {
            total = total + conta(atual->filhos[i]);
        };
        return total;
    };
    return 0;
}


int main() {
    for(int i=0; i< 30000; i++){
    raizB = insere_arvoreB(raizB, rand());
}

//    raizB=insere_arvoreB(raizB,10);
//    raizB=insere_arvoreB(raizB,25);
//    raizB=insere_arvoreB(raizB,8);
//    raizB=insere_arvoreB(raizB,40);
//    raizB=insere_arvoreB(raizB,125);
//    raizB=insere_arvoreB(raizB,9);
//    raizB=insere_arvoreB(raizB,896);
//    raizB=insere_arvoreB(raizB,1);

//    percurso(raizB);

    cout << "Existem " << conta(raizB) << " nos na arvore" << endl;

}
