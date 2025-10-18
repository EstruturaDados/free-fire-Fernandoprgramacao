#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

// Estrutura que representa um item do inventário
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

int main() {
    Item mochila[MAX_ITENS];
    int quantidadeAtual = 0;
    int opcao;

    do {
        printf("\n========== INVENTARIO DO JOGADOR ==========\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpa o Enter deixado pelo scanf

        if (opcao == 1) {
            if (quantidadeAtual >= MAX_ITENS) {
                printf("\nA mochila esta cheia! Nao e possivel adicionar mais itens.\n");
            } else {
                Item novo;
                printf("\n--- Cadastro de Novo Item ---\n");

                printf("Nome do item: ");
                scanf(" %29[^\n]", novo.nome);

                printf("Tipo do item (ex: arma, municao, cura): ");
                scanf(" %19[^\n]", novo.tipo);

                printf("Quantidade: ");
                scanf("%d", &novo.quantidade);

                mochila[quantidadeAtual] = novo;
                quantidadeAtual++;

                printf("\nItem adicionado com sucesso!\n");
            }
        }

        else if (opcao == 2) {
            if (quantidadeAtual == 0) {
                printf("\nA mochila esta vazia! Nada para remover.\n");
            } else {
                char nomeBusca[30];
                printf("\nDigite o nome do item que deseja remover: ");
                scanf(" %29[^\n]", nomeBusca);

                int encontrado = 0;
                for (int i = 0; i < quantidadeAtual; i++) {
                    if (strcmp(mochila[i].nome, nomeBusca) == 0) {
                        for (int j = i; j < quantidadeAtual - 1; j++) {
                            mochila[j] = mochila[j + 1];
                        }
                        quantidadeAtual--;
                        encontrado = 1;
                        printf("\nItem '%s' removido com sucesso!\n", nomeBusca);
                        break;
                    }
                }
                if (!encontrado) {
                    printf("\nItem nao encontrado na mochila.\n");
                }
            }
        }

        else if (opcao == 3) {
            printf("\n--- Itens na Mochila ---\n");
            if (quantidadeAtual == 0) {
                printf("Nenhum item cadastrado.\n");
            } else {
                for (int i = 0; i < quantidadeAtual; i++) {
                    printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n",
                           i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
                }
            }
        }

        else if (opcao == 4) {
            if (quantidadeAtual == 0) {
                printf("\nA mochila esta vazia! Nenhum item para buscar.\n");
            } else {
                char nomeBusca[30];
                printf("\nDigite o nome do item que deseja buscar: ");
                scanf(" %29[^\n]", nomeBusca);

                int encontrado = 0;
                for (int i = 0; i < quantidadeAtual; i++) {
                    if (strcmp(mochila[i].nome, nomeBusca) == 0) {
                        printf("\nItem encontrado:\n");
                        printf("Nome: %s\n", mochila[i].nome);
                        printf("Tipo: %s\n", mochila[i].tipo);
                        printf("Quantidade: %d\n", mochila[i].quantidade);
                        encontrado = 1;
                        break;
                    }
                }
                if (!encontrado) {
                    printf("\nItem '%s' nao encontrado na mochila.\n", nomeBusca);
                }
            }
        }

        else if (opcao == 5) {
            printf("\nSaindo do sistema. Ate logo!\n");
        }

        else {
            printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 5);

    return 0;
}
