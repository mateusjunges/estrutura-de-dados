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
187
188
189
190
191
192
193
194
195
196
197
198
199
200
201
202
203
204
205
206
207
208
209
210
211
212
213
214
215
216
217
218
219
220
221
222
223
224
225
226
227
228
229
230
231
232
233
234
235
236
237
238
239
240
241
242
243
244
245
246
247
248
249
250
251
252
253
254
255
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define TAM 10

using namespace std;
int chave;
int vetor[TAM];
int cont = 0;


void vet(){
     int i = 0;
    while(i<TAM){
        vetor[i] = rand()%20;
        i++;
    }
}

void ordenaVetor(){
    sort(vetor, vetor+TAM);
}

void gera_chave(){
    chave = rand()%20;
}

void imprime(){
    int j = 0;
    while(j<TAM){
        cout<<" "<<vetor[j];
        j++;
    }
    cout<<endl;
}

struct no {
            int dado;
            struct no *esq;
            struct no *dir;
            int bal;
            };

struct no* raiz, *raiz_avl;


// Rotaзгo para a esquerda
void esquerda(struct no *p) {

    struct no *q, *hold;

   q = p->dir;
   hold = q->esq;
   q->esq = p;
   p->dir = hold;

}

//Rotaзгo para a direita
void direita(struct no *p) {

    struct no *q, *hold;

   q = p->esq;
   hold = q->dir;
   q->dir = p;
   p->esq = hold;

}

// Cira um no e preenche os membros
struct no *cria_no(int valor){
    struct no *aux = new (struct no);
    aux->dado=valor;
    aux->dir=NULL;
    aux->esq=NULL;
    aux->bal=0;
    return aux;
};

//Insere valor em uma бrvore AVL
void insere_bal(int chave)
{

    struct no *pp=NULL, *p=raiz_avl, *pajovem=NULL, *ajovem=raiz_avl, *q, *filho;
   int imbal;

   if (p==NULL) {             /* Arvore vazia */
      raiz_avl = cria_no(chave);  /* Funcao para criacao de um novo no */
      return;
   }

/* Insere chave e descobre ancestral mais jovem a ser desbalanceado */
   while (p!=NULL) {
    if (chave < p->dado)
        q = p->esq;
         else q = p->dir;
      if (q!=NULL)
        if (q->bal != 0) {
            pajovem=p;
            ajovem=q;
      }
      pp = p;
      p = q;
   }

   q = cria_no(chave);

   if (chave<pp->dado)
    pp->esq=q;
      else pp->dir=q;

/* Balanceamento de todos os nуs entre ajovem e q devem ser ajustados */
   if (chave<ajovem->dado)
    filho = ajovem->esq;
      else filho = ajovem->dir;

   p = filho;

   while (p!=q) {
    if (chave < p->dado) {
        p->bal=1;
         p=p->esq;
    } else {
            p->bal = -1;
            p=p->dir;
            }
   }

   if (chave<ajovem->dado)
    imbal = 1;
      else imbal = -1;

   if (ajovem->bal==0) {      /*Nгo houve desbalanceamento */
    ajovem->bal=imbal;
      return;
   }


    if (ajovem->bal!=imbal) {   /*Nгo houve desbalanceamento */
    ajovem->bal=0;
      return;
   }

    /* Houve desbalanceamento */
   if (filho->bal == imbal) {
    p=filho;
      if (imbal==1)        /* Faz rotaзгo simples */
        direita(ajovem);
        else esquerda(ajovem);
      ajovem->bal=0;
      filho->bal=0;
   } else {
        if (imbal==1) {   /*Faz rotaзгo dupla */
            p=filho->dir;
            esquerda(filho);
            ajovem->esq=p;
            direita(ajovem);
        } else {
              p=filho->esq;
              direita(filho);
              ajovem->dir=p;
              esquerda(ajovem);
         }
         if (p->bal==0) {
            ajovem->bal=0;
            filho->bal=0;
         } else {
                if (p->bal == imbal) {
                ajovem->bal = - imbal;
                  filho->bal = 0;
               } else {
                ajovem->bal = 0;
                  filho->bal = imbal;
               }
         }
      p->bal=0;
   }

   if (pajovem == NULL)  /* Ajusta ponteiro do pai do ancestral mais jovem */
      raiz_avl = p;
      else if (ajovem==pajovem->dir)
                 pajovem->dir = p;
                else pajovem->esq = p;

   return;
}

//Insere valor em uma бrvore binбria
void insere(int valor)
{

   struct no *atual, *aux;

   aux = new(struct no);
   aux->dado = valor;
   aux->esq = NULL;
   aux->dir = NULL;

   atual=raiz;

   if (atual==NULL) {
      raiz = aux;
      return;
   }

   while (1) {
            if (valor < atual->dado)
                if (atual->esq==NULL) {
                    atual->esq=aux;
                    return;
                 }
                 else atual=atual->esq;
            else if (atual->dir==NULL) {
                    atual->dir=aux;
                    return;
                 }
                 else atual=atual->dir;
         }
}

void em_ordem(struct no *atual)
{
    if (atual!=NULL) {
       em_ordem(atual->esq);
       printf("%d ",atual->dado);
       em_ordem(atual->dir);

    }

}



int main(){

vet();
for(int i=0; i<TAM; i++){
    insere_bal(vetor[i]);
    insere(vetor[i]);
}
gera_chave();
cout<<"CHAVE: "<<chave<<"\n";
imprime();
ordenaVetor();
imprime();
cout<<" ";
em_ordem(raiz);
cout<<endl;
cout<<" ";
em_ordem(raiz_avl);

return 0;
}
