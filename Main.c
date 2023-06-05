#include <stdio.h>
#include <stdlib.h>
#include "Cabecalho.h"

int main(void){
    int N;

    printf("Entre com o tamanho da sua tabela: ");
    scanf("%d", &N);

    Filme **filmes;
    filmes = (Filme**)malloc(N*sizeof(Filme**));

    for(int i = 0; i < N; i++){
        filmes[i] = (Filme*)malloc(sizeof(Filme*));
        filmes[i] = criar_filme();
    }

    print_tabela(filmes, N);
    menu(filmes, N);
}

