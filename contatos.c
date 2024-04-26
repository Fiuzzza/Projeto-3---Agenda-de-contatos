// contatos.c
#include <stdio.h>
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

void salvarAgenda(Contato agenda[], int numContatos, char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fwrite(&numContatos, sizeof(int), 1, arquivo);
    fwrite(agenda, sizeof(Contato), numContatos, arquivo);

    fclose(arquivo);
}

void carregarAgenda(Contato agenda[], int *numContatos, char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fread(numContatos, sizeof(int), 1, arquivo);
    fread(agenda, sizeof(Contato), *numContatos, arquivo);

    fclose(arquivo);
}
