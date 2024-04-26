#include <stdio.h>
#include "contatos.h"

int main() {
    Contato agenda[255];
    int numContatos = 0;
    int opcao;
    char telefone[20];

    do {
        printf("\nSelecione uma opção:\n");
        printf("1. Adicionar contato\n");
        printf("2. Listar contatos\n");
        printf("3. Deletar contato\n");
        printf("4. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato(agenda, &numContatos);
                break;
            case 2:
                listarContatos(agenda, numContatos);
                break;
            case 3:
                printf("Digite o número de telefone do contato a ser deletado: ");
                scanf("%s", telefone);
                deletarContato(agenda, &numContatos, telefone);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}
