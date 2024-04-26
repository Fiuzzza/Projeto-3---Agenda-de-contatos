#include <stdio.h>
#include <string.h>
#include "contatos.h"

void adicionarContato(Contato agenda[], int *numContatos) {
}

void listarContatos(Contato agenda[], int numContatos) {
}

void deletarContato(Contato agenda[], int *numContatos, char *telefone) {
    if (*numContatos == 0) {
        printf("Não há contatos na agenda.\n");
        return;
    }

    int encontrado = 0;
    for (int i = 0; i < *numContatos; i++) {
        if (strcmp(agenda[i].telefone, telefone) == 0) {
            printf("Contato deletado: %s - %s\n", agenda[i].nome, agenda[i].telefone);
            for (int j = i; j < *numContatos - 1; j++) {
                agenda[j] = agenda[j + 1];
            }
            (*numContatos)--;
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Contato não encontrado.\n");
    }
}
