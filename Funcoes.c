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

//função que acessa e modifica o ano de um filme
void set_ano(Filme* f, int novo){
    f->informacoes->ano = novo;
}

//função que acessa e modifica a faixa etária de um filme
void set_faixaetaria(Filme* f, int novo){
    f->informacoes->faixaEtaria = novo;
}

//função que acessa e modifica o nome de um filme
void set_nome(Filme* f, char* novo){
    strcpy(f->nome, novo);
}

//função que acessa e renomeia um diretor de um filme
void set_diretor(Filme* f, char* novo){
    strcpy(f->informacoes->diretor, novo);
}

void renomear_titulo(Filme** tabela, int indice){
    int codigo;

    printf("INFORME O CODIGO DO FILME: \n");
    scanf("%d", &codigo);

    if(codigo >= 1 && codigo <= indice){
        char novo_titulo[101];
        char novo_diretor[101];

        printf("NOVO TITULO: \n");
        scanf(" %[^\n]", novo_titulo);
        set_nome(tabela[codigo - 1], novo_titulo);

        printf("NOVO DIRETOR: \n");
        scanf(" %[^\n]", novo_diretor);
        set_diretor(tabela[codigo - 1], novo_diretor);

        printf("TITULO RENOMEADO COM SUCESSO.\n");
    } else {
        printf("CODIGO DE FILME INVALIDO.\n");
    }
}

//função que acessa e modifica o preço de um filme
void set_preco(Filme* f, float novo){
    f->preco = novo;
}

void atualizar_preco(Filme** tabela, int indice){
    int codigo;

    printf("INFORME O CODIGO DO FILME: \n");
    scanf("%d", &codigo);

    if(codigo >= 1 && codigo <= indice) {
        float novo_preco;
        printf("NOVO PRECO: \n");
        scanf("%f", &novo_preco);
        set_preco(tabela[codigo - 1], novo_preco);

        printf("PRECO ATUALIZADO COM SUCESSO.\n");
    } else {
        printf("CODIGO DE FILME INVALIDO.\n");
    }
}

//função que acessa e renomeia os gêneros de um filme
void set_genero(Filme* f, char* novo){
    strcpy(f->informacoes->genero, novo);
}

void atualizar_genero(Filme** tabela, int indice){
    int codigo;

    printf("INFORME O CODIGO DO FILME: \n");
    scanf("%d", &codigo);

    getchar();

    char novo_genero[51];
    if(codigo >= 1 && codigo <= indice) {

        printf("NOVO GENERO: \n");
        scanf(" %[^\n]", novo_genero);
        set_genero(tabela[codigo - 1], novo_genero);

        printf("GENERO ATUALIZADO COM SUCESSO.\n");
    } else {
        printf("CODIGO DE FILME INVALIDO.\n");
    }
}

void free_filme(Filme* f){
    free(f->informacoes);
    free(f);
}

void ordena_filmes(Filme** f, int tam, int n){
    for(int i=n-1; i<tam-1; i++){
        strcpy(f[i]->nome, f[i+1]->nome);
        f[i]->preco =  f[i+1]->preco;
        strcpy(f[i]->informacoes->genero, f[i+1]->informacoes->genero);
        f[i]->informacoes->faixaEtaria = f[i+1]->informacoes->faixaEtaria;
        strcpy(f[i]->informacoes->diretor, f[i+1]->informacoes->diretor);
        f[i]->informacoes->ano = f[i+1]->informacoes->ano;
    }
    free(f[tam-1]->informacoes);
    free(f[tam-1]);
}

void menu(Filme** filmes, int N){
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
                N = N + 1;
                filmes = realloc(filmes, N*sizeof(Filme**));
                filmes[N-1] = malloc(sizeof(Filme*));
                filmes[N-1] = criar_filme();
                print_tabela(filmes, N);
            break;
            
            case 2:
                printf("1 - RENOMEAR TITULO\n");
                printf("2 - ATUALIZAR PRECO\n");
                printf("3 - ATUALIZAR GENERO\n");

                scanf("%d", &opcaoAtualizar);

                getchar();

                switch (opcaoAtualizar){
                    case 1:
                    renomear_titulo(filmes, N);
                    print_tabela(filmes, N);
                    break;
                
                    case 2:
                    atualizar_preco(filmes, N);
                    print_tabela(filmes, N);
                    break;

                    case 3:
                    atualizar_genero(filmes, N);
                    print_tabela(filmes, N);
                    break;

                    default:
                    break;
                }
            break;

            case 3:
                printf("INFORME O CODIGO DO FILME: \n");
                int num;
                scanf("%d", &num);

                free_filme(filmes[num-1]);
                ordena_filmes(filmes, N, num);
                N--;
                filmes = realloc(filmes, N*sizeof(Filme**));
                print_tabela(filmes, N);
            break;

            case 4:
            break;
        
            default:
            break;
        }

    }
}

void imprimir_filme(Filme* f){
    printf("%.2f R$ || %s (%s, %d) || %s %d\n", f->preco, f->nome, f->informacoes->genero, f->informacoes->faixaEtaria,f->informacoes->diretor, f->informacoes->ano);
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
    menu(tabela, tam);
}


Filme* criar_filme(){
    Filme* filme;
    filme = malloc(sizeof(Filme));
    filme->informacoes = malloc(sizeof(Info));

    printf("Nome: ");
    scanf(" %101[^\n]", filme->nome);

    printf("Preco: ");
    scanf("%f", &filme->preco);

    printf("Diretor: ");
    scanf(" %101[^\n]", filme->informacoes->diretor);

    printf("Ano: ");
    scanf("%d", &filme->informacoes->ano);

    printf("Genero: ");
    scanf(" %51[^\n]", filme->informacoes->genero);

    printf("Faixa etaria: ");
    scanf("%d", &filme->informacoes->faixaEtaria);

    return filme;
}

