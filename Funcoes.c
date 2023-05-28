#include "Cabecalho.h"
#include <stdio.h>
#include <stdlib.h>

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


void imprimir_filme(Filme* f){
    printf("%.2f R$ || %s (%s, %d) || %s %d\n", f->preco, f->nome, f->informações->genero, f->informações->faixaEtaria,f->informações->diretor, f->informações->ano);
}

// Função que imprime a tabela atualizada dos filmes cadastrados
// código -- preço R$ ## nome (gênero, faixa etária) ## diretor ano
// 0001 -- 25.50 R$ ## The Godfather Part II (Crime/Drama, 16) ## Francis Ford Coppola 1974
void print_tabela(Filme **tabela, int tam){
    printf("-------------TABELA DE FILMES-------------\n\n");
    for (int i = 0; i < tam; i++)
    {
        printf("%.4d -- ", i + 1); // código de 4 caracteres
        imprimir_filme(tabela[i]);
    }
   // menu();
}

void clear_keyboard_buffer(void){
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
    return;
}



Filme* criar_filme(){
    Filme* filme;
    filme = malloc(sizeof(Filme));
    filme->informações = malloc(sizeof(Info));

    printf("Nome: ");
    scanf("%[^\n]", filme->nome);
    //fgets(filme->nome, 101, stdin);
    getchar();
    clear_keyboard_buffer();

    printf("Preco: ");
    scanf("%f", &filme->preco);
    //clear_keyboard_buffer();

    printf("Diretor: ");
    scanf("%[^\n]", filme->informações->diretor);
    //fgets(filme->informações->diretor, 101, stdin);
    getchar();
    clear_keyboard_buffer();

    printf("Ano: ");
    scanf("%d", &filme->informações->ano);
    //clear_keyboard_buffer();

    printf("Genero: ");
    scanf("%[^\n]", filme->informações->genero);
    //fgets(filme->informações->genero, 51, stdin);
    getchar();
    clear_keyboard_buffer();

    printf("Faixa etaria: ");
    scanf("%d", &filme->informações->faixaEtaria);
    //clear_keyboard_buffer();

    return filme;
}

