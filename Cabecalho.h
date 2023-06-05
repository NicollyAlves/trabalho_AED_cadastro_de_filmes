#ifndef CABECALHO_H
#define CABECALHO_H

//estrutura para um Filme com:
//nome, preco e "info"
typedef struct filme Filme;

//estrutura para informações mais específicas do filme como: 
//diretor, genero, ano, faixa etaria
typedef struct info Info;

//Função que cria e retorna um ponteiro simples para o tipo Filme
Filme* criar_filme();

//Função que exclui um filme e libera memória
void free_filme(Filme* f);

//função que imprime informações de um filme
void imprimir_filme(Filme* f);

//função que acessa e modifica o nome de um filme
void set_nome(Filme* f, char* novo);

//função que acessa e modifica o preço de um filme
void set_preco(Filme* f, float novo);

//função que acessa e renomeia um diretor de um filme
void set_diretor(Filme* f, char* novo);

//função que acessa e renomeia os gêneros de um filme
void set_genero(Filme* f, char* novo);

//função que acessa e modifica o ano de um filme
void set_ano(Filme* f, int novo);

//função que acessa e modifica a faixa etária de um filme
void set_faixaetaria(Filme* f, int novo);

//função que imprime as informações atualizadas de uma lista de filmes
// código -- preço R$ ## nome (gênero, faixa etária) ## diretor ano
// 0001 -- 25.50 R$ ## The Godfather Part II (Crime/Drama, 16) ## Francis Ford Coppola 1974
void print_tabela(Filme **tabela, int tam);

//função que verifica se um filme contém o gênero terror e tem faixa etária menor que 18 anos
int verificaTerror(char* genero, int faixaEtaria);

//função que exibe um menu com opções de alterações na lista de filmes 
void menu(Filme** filmes, int N);

void renomear_titulo(Filme** tabela, int indice);

void atualizar_preco(Filme** tabela, int indice);

void atualizar_genero(Filme** tabela, int indice);

#endif