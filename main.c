#include <stdio.h>
#include "contatos.h"

int main() {
    Contato agenda[255];
    int numContatos = 0;
    int opcao;

    do {
        printf("\nSelecione uma opção:\n");
        printf("1. Adicionar contato\n");
        printf("2. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato(agenda, &numContatos);
                break;
            case 2:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 2);

    return 0;
}
