#include <stdio.h>
#include "contatos.h"

void adicionarContato(Contato agenda[], int *numContatos) {
    if (*numContatos >= 255) {
        printf("Erro: Limite de contatos atingido.\n");
        return;
    }

    Contato novoContato;

    printf("Nome: ");
    scanf("%s", novoContato.nome);

    printf("Telefone: ");
    scanf("%s", novoContato.telefone);

    agenda[*numContatos] = novoContato;
    (*numContatos)++;

    printf("Contato adicionado com sucesso!\n");
}

void listarContatos(Contato agenda[], int numContatos) {
    if (numContatos == 0) {
        printf("Não há contatos na agenda.\n");
        return;
    }

    printf("Lista de contatos:\n");
    for (int i = 0; i < numContatos; i++) {
        printf("Nome: %s\tTelefone: %s\n", agenda[i].nome, agenda[i].telefone);
    }
}
