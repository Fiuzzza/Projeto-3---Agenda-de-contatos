#include <stdio.h>
#include <string.h>
#include "contatos.h"

void adicionarContato(Contato agenda[], int *numContatos) {
}

void listarContatos(Contato agenda[], int numContatos) {
}

void deletarContato(Contato agenda[], int *numContatos, char *telefone) {
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
