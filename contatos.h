#ifndef CONTATOS_H
#define CONTATOS_H

typedef struct {
    char nome[50];
    char telefone[20];
} Contato;

void adicionarContato(Contato agenda[], int *numContatos);
void listarContatos(Contato agenda[], int numContatos);
void deletarContato(Contato agenda[], int *numContatos, char *telefone);
void salvarAgenda(Contato agenda[], int numContatos, char *nomeArquivo);
void carregarAgenda(Contato agenda[], int *numContatos, char *nomeArquivo);

#endif
