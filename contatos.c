#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
