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

void set_ano(Filme* f, int novo){
    f->informacoes->ano = novo;
}

void set_faixaetaria(Filme* f, int novo){
    f->informacoes->faixaEtaria = novo;
}

void set_nome(Filme* f, char* novo){
    strcpy(f->nome, novo);
}

void set_diretor(Filme* f, char* novo){
    strcpy(f->informacoes->diretor, novo);
}

void renomear_titulo(Filme** tabela, int indice){
    int codigo;  // Variável para armazenar o código do filme a ser renomeado

    printf("INFORME O CODIGO DO FILME: \n");
    scanf("%d", &codigo);

    // Verifica se o código é válido (está dentro do intervalo válido)
    if(codigo >= 1 && codigo <= indice){
        // Aloca memória para armazenar o novo título e novo diretor do filme
        char* novo_titulo = (char*)malloc(sizeof(char));
        char* novo_diretor = (char*)malloc(sizeof(char));

        printf("NOVO TITULO: \n");
        scanf(" %[^\n]", novo_titulo);  // Lê o novo título fornecido pelo usuário
        set_nome(tabela[codigo - 1], novo_titulo);  // Chama a função set_nome para atualizar o título do filme selecionado no array tabela

        //É pedido obrigatoriamente para ler o novo direto juntamente com o novo títutlo
        printf("NOVO DIRETOR: \n");
        scanf(" %[^\n]", novo_diretor);  // Lê o novo diretor fornecido pelo usuário
        set_diretor(tabela[codigo - 1], novo_diretor);  // Chama a função set_diretor para atualizar o diretor do filme selecionado no array tabela

        printf("TITULO RENOMEADO COM SUCESSO.\n");
    } else {
        printf("CODIGO DE FILME INVALIDO.\n");
    }
}

void set_preco(Filme* f, float novo){
    f->preco = novo;
}

void atualizar_preco(Filme** tabela, int indice){
    int codigo;  // Variável para armazenar o código do filme a ser atualizado

    // Solicita ao usuário que informe o código do filme
    printf("INFORME O CODIGO DO FILME: \n");
    scanf("%d", &codigo);

    // Verifica se o código é válido (está dentro do intervalo válido)
    if(codigo >= 1 && codigo <= indice) {
        float novo_preco;  // Variável para armazenar o novo preço

        // Solicita ao usuário que informe o novo preço
        printf("NOVO PRECO: \n");
        scanf("%f", &novo_preco);

        // Chama a função set_preco para atualizar o preço do filme selecionado
        set_preco(tabela[codigo - 1], novo_preco);

        printf("PRECO ATUALIZADO COM SUCESSO.\n");
    } else {
        printf("CODIGO DE FILME INVALIDO.\n");
    }
}

void set_genero(Filme* f, char* novo){
    strcpy(f->informacoes->genero, novo);
}

void atualizar_genero(Filme** tabela, int indice){
    int codigo;  // Variável para armazenar o código do filme a ser atualizado

    printf("INFORME O CODIGO DO FILME: \n");
    scanf("%d", &codigo);

    getchar();  // Limpa o caractere de nova linha residual no buffer

    // Aloca memória para armazenar o novo gênero do filme
    char* novo_genero = (char*)malloc(sizeof(char));

    // Verifica se o código é válido (está dentro do intervalo válido)
    if(codigo >= 1 && codigo <= indice) {

        printf("NOVO GENERO: \n");
        scanf(" %[^\n]", novo_genero);  // Lê o novo gênero fornecido pelo usuário

        // Chama a função set_genero para atualizar o gênero do filme selecionado no array tabela
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

//função que reordena depois da exclusão de um filme
void ordena_filmes(Filme** f, int tam, int n){
    for(int i=n-1; i<tam-1; i++){  //percorre a lista desde o indice do vetor excluído até o último índice
        strcpy(f[i]->nome, f[i+1]->nome); //copia a informação do próximo filme para a do anterior
        f[i]->preco =  f[i+1]->preco;
        strcpy(f[i]->informacoes->genero, f[i+1]->informacoes->genero);
        f[i]->informacoes->faixaEtaria = f[i+1]->informacoes->faixaEtaria;
        strcpy(f[i]->informacoes->diretor, f[i+1]->informacoes->diretor);
        f[i]->informacoes->ano = f[i+1]->informacoes->ano;
    }
    free(f[tam-1]->informacoes); //libera o espaço de memória do último filme da lista depois que foi ordenada
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

void print_tabela(Filme **tabela, int tam){
    printf("-------------TABELA DE FILMES-------------\n\n");
    for (int i = 0; i < tam; i++){
        printf("%.4d -- ", i + 1); // código de 4 caracteres
        imprimir_filme(tabela[i]);
    }
    printf("\n");
    printf("\n");
}

//função que verifica se o gênero de um filme com faixa etário menor que 18 anos é terror
int verificaTerror(char* genero, int faixaEtaria){
    char s1[7] = "Terror"; //String para comparar se o genêro do filme contém "Terror"
    char s2[7]; //string auxiliar para comparar com a string s1
    int terror = 0;

    if(faixaEtaria < 18 && strlen(genero) >= 7) // inicia se a faixa etaria for menor que 18 anos e poder conter "Terror" no gênero
        for(int i = 0; i < strlen(genero); i++) //percorre toda a string da descrição do gênero do filme
            for(int j = 0; j < 7; j++) //percorre em distâncias de 7 unidades, com a última sendo o '\0'
                if(j != 6)
                    s2[j] = genero[j+i]; //a string auxiliar toma 6 caracteres da string de genero durante o loop
                else{
                    s2[j] = '\0'; //o ultimo caractere da string auxiliar é '\0'
                    if(strcmp(s2,s1) == 0) //depois que a string está pronta, ela é comparada com "Terror"
                        terror = 1; //se forem iguais, a função retorna 1
                }                 //no próximo loop, a string auxiliar começa em um caractere na frente e assim percorre toda a descricao  

    return terror;
}

//Função que cria e retorna um ponteiro simples para o tipo Filme
Filme* criar_filme(){
    Filme* filme;
    filme = malloc(sizeof(Filme)); 
    filme->informacoes = malloc(sizeof(Info)); 

    printf("Nome: ");
    scanf(" %101[^\n]", filme->nome); //leitura do nome do filme em 100 caracteres + 1 para o '\0'

    printf("Preco: ");
    scanf("%f", &filme->preco); //leitura do preço em float

    printf("Diretor: ");
    scanf(" %101[^\n]", filme->informacoes->diretor); //leitura do nome do diretor em 100 caracteres + 1 para o '\0'

    printf("Ano: ");
    scanf("%d", &filme->informacoes->ano); //leitura do ano do filme

    printf("Genero: ");
    scanf(" %51[^\n]", filme->informacoes->genero); //leitura do gênero do filme em 50 caracteres + 1 para o '\0'

    printf("Faixa etaria: ");
    scanf("%d", &filme->informacoes->faixaEtaria); //leitura da faixa etária

    int terror = 1;  //bloco de código que verifica se o gênero do filme é terror e se a faixa etária é adequada
    while(terror == 1){ 
        terror = verificaTerror(filme->informacoes->genero, filme->informacoes->faixaEtaria);
        if(terror == 1){ //se a faixa etária não for adequada, a alteração dela é solicitada
            printf("Faixa etaria não adequada a filme de terror\n");
            printf("Digite nova faixa etária: ");
            scanf("%d", &filme->informacoes->faixaEtaria); 
        }
    }

    return filme;
}

