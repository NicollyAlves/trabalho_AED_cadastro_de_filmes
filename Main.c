#include <stdio.h>
#include <stdlib.h>

#include "Cabecalho.h"

typedef struct info{
    char diretor[101]; // 101 caracteres + 1 para fim de string
    char genero[51];   // 50 caracteres + 1 para fim de string
    int ano;
    int faixaEtaria; // Use 0 para classificação livre
} Info;

typedef struct filme{
    char nome[101];    // 100 caracteres + 1 para fim de string
    float preco;       // Até duas casas decimais
    Info *informações; // Ponteiro para struct Info
} Filme;

int main(void){
    int N;

    printf("Entre com o tamanho da sua tabela: ");
    scanf("%d", &N);

    Filme **filmes;
    filmes = (Filme**) malloc(N*sizeof(Filme**));

    for(int i = 0; i < N; i++){
        filmes[i] = (Filme*) malloc(sizeof(Filme*));
        filmes[i] = criar_filme();
    }

    print_tabela(filmes, N);
}

