#ifndef CONTATOS_H
#define CONTATOS_H

typedef struct {
    char nome[50];
    char telefone[20];
} Contato;

void adicionarContato(Contato agenda[], int *numContatos);

#endif
