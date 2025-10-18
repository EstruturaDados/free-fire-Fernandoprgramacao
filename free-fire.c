do {
    printf("\n========== INVENTÁRIO DO JOGADOR ==========\n");
    printf("1. Adicionar item\n");
    printf("2. Remover item\n");
    printf("3. Listar itens\n");
    printf("4. Buscar item\n");
    printf("5. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar(); // limpa o buffer do teclado

    if (opcao == 1) {
        if (quantidadeAtual >= MAX_ITENS) {
            printf("\nA mochila está cheia! Não é possível adicionar mais itens.\n");
        } else {
            Item novo;
            printf("\n--- Cadastro de Novo Item ---\n");

            printf("Nome do item: ");
            fgets(novo.nome, 30, stdin);
            novo.nome[strcspn(novo.nome, "\n")] = '\0';

            printf("Tipo do item (ex: arma, munição, cura): ");
            fgets(novo.tipo, 20, stdin);
            novo.tipo[strcspn(novo.tipo, "\n")] = '\0';

            printf("Quantidade: ");
            scanf("%d", &novo.quantidade);
            getchar();

            mochila[quantidadeAtual] = novo;
            quantidadeAtual++;

            printf("\nItem adicionado com sucesso!\n");
        }
    }

    else if (opcao == 2) {
        if (quantidadeAtual == 0) {
            printf("\nA mochila está vazia! Nada para remover.\n");
        } else {
            char nomeBusca[30];
            printf("\nDigite o nome do item que deseja remover: ");
            fgets(nomeBusca, 30, stdin);
            nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

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
                printf("\nItem não encontrado na mochila.\n");
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
            printf("\nA mochila está vazia! Nenhum item para buscar.\n");
        } else {
            char nomeBusca[30];
            printf("\nDigite o nome do item que deseja buscar: ");
            fgets(nomeBusca, 30, stdin);
            nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

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
                printf("\nItem '%s' não encontrado na mochila.\n", nomeBusca);
            }
        }
    }

    else if (opcao == 5) {
        printf("\nSaindo do sistema. Até logo!\n");
    }

    else {
        printf("\nOpção inválida! Tente novamente.\n");
    }

} while (opcao != 5);

return 0;
