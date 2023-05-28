#include "Cabecalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct info{
    char diretor[101]; // 101 caracteres + 1 para fim de string
    char genero[51];   // 50 caracteres + 1 para fim de string
    int ano;
    int faixaEtaria; // Use 0 para classificação livre
} Info;

typedef struct filme{
    char nome[101];    // 100 caracteres + 1 para fim de string
    float preco;       // Até duas casas decimais
    Info *informacoes; // Ponteiro para struct Info
} Filme;


void imprimir_filme(Filme* f){
    printf("%.2f R$ || %s (%s, %d) || %s %d\n", f->preco, f->nome, f->informacoes->genero, f->informacoes->faixaEtaria,f->informacoes->diretor, f->informacoes->ano);
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
    filme->informacoes = malloc(sizeof(Info));

    printf("Nome: ");
    scanf(" %[^\n]", filme->nome);

    printf("Preco: ");
    scanf("%f", &filme->preco);

    printf("Diretor: ");
    scanf(" %[^\n]", filme->informacoes->diretor);
    getchar();

    printf("Ano: ");
    scanf("%d", &filme->informacoes->ano);

    printf("Genero: ");
    scanf(" %[^\n]", filme->informacoes->genero);
    getchar();

    printf("Faixa etaria: ");
    scanf("%d", &filme->informacoes->faixaEtaria);

    return filme;
}

