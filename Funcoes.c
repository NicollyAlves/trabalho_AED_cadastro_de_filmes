#include "Cabecalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

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


void menu(){
    int opcaoAtualizar = 0;
    int opcao = 0;

    while(opcao != 4){

        printf("MENU DE OPCOES\n");
        printf("\n");
        printf("1 - CADASTRAR UM NOVO TITULO\n");
        printf("2 - ATUALIZAR INFO DE UM TITULO\n");
        printf("3 - EXCLUIR UM TITULO\n");
        printf("4 - FINALIZAR OPERACAO\n");

        scanf("%d", &opcao);

        switch (opcao){
            case 1:
            break;
            
            case 2:
                printf("1 - RENOMEAR TITULO\n");
                printf("2 - ATUALIZAR PRECO\n");
                printf("3 - ATUALIZAR GENERO\n");

                scanf("%d", &opcaoAtualizar);

                switch (opcaoAtualizar){
                    case 1:
                    break;
                
                    case 2:
                    break;

                    case 3:
                    break;

                    default:
                    break;
                }
            break;

            case 3:
            break;

            case 4:
            break;
        
            default:
            break;
        }

    }
}

// Função que imprime a tabela atualizada dos filmes cadastrados
// código -- preço R$ ## nome (gênero, faixa etária) ## diretor ano
// 0001 -- 25.50 R$ ## The Godfather Part II (Crime/Drama, 16) ## Francis Ford Coppola 1974
void print_tabela(Filme **tabela, int tam){
    printf("-------------TABELA DE FILMES-------------\n\n");
    for (int i = 0; i < tam; i++){
        printf("%.4d -- ", i + 1); // código de 4 caracteres
        imprimir_filme(tabela[i]);
    }
    menu();
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

    printf("Ano: ");
    scanf("%d", &filme->informacoes->ano);

    printf("Genero: ");
    scanf(" %[^\n]", filme->informacoes->genero);

    printf("Faixa etaria: ");
    scanf("%d", &filme->informacoes->faixaEtaria);

    return filme;
}

