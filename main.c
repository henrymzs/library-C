#include <stdio.h>
#include <string.h>

#define CAPACIDADE_MAXIMA 100 

struct Livro {
    char titulo[50];
    char autor[50];
    int anoPublicacao;
    int codigoLivro;
    int disponibilidade; 
};

void adicionarLivro(struct Livro biblioteca[], int *contador, struct Livro livro) {
    if (*contador < CAPACIDADE_MAXIMA) {
        biblioteca[*contador] = livro; 
        (*contador)++; 
        printf("Livro adicionado com sucesso!\n");
    } else {
        printf("A biblioteca está cheio! Não é possível adicionar mais livros.\n");
    }
}

void removerLivro(struct Livro biblioteca[], int *contador, int codigoLivro) {
    int i, j;

    for (i = 0; i < *contador; i++) { 
        if (biblioteca[i].codigoLivro == codigoLivro) { 
            for (j = i; j < *contador - 1; j++) {
                biblioteca[j] = biblioteca[j + 1];
            }
            (*contador)--; 
            printf("Livro removido com sucesso!\n");
            return;
        }
    }

    printf("Livro com código %d não encontrado!\n", codigoLivro);
}

void buscarPorTitulo(struct Livro biblioteca[], int contador, const char *titulo) {
    int encontrado = 0; 
    for (int i = 0; i < contador; i++) {
        if (strcmp(biblioteca[i].titulo, titulo) == 0) { 
            printf("-------------------\n");
            printf("Livro encontrado:\n");
            printf("Título: %s\n", biblioteca[i].titulo);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Ano de Publicação: %d\n", biblioteca[i].anoPublicacao);
            printf("Código do Livro: %d\n", biblioteca[i].codigoLivro);
            printf("Disponibilidade: %s\n\n", biblioteca[i].disponibilidade ? "Disponível" : "Indisponível");
            encontrado = 1;
        }
    }
    if (!encontrado) { 
        printf("Nenhum livro encontrado com o título \"%s\".\n", titulo);
    }
}

void buscarPorAutor(struct Livro biblioteca[], int contador, const char *autor) {
    int encontrado = 0; 
    for (int i = 0; i < contador; i++) { 
        if (strcmp(biblioteca[i].autor, autor) == 0) { 
            printf("-------------------\n");
            printf("Livro encontrado:\n");
            printf("Título: %s\n", biblioteca[i].titulo);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Ano de Publicação: %d\n", biblioteca[i].anoPublicacao);
            printf("Código do Livro: %d\n", biblioteca[i].codigoLivro);
            printf("Disponibilidade: %s\n\n", biblioteca[i].disponibilidade ? "Disponível" : "Indisponível");
            encontrado = 1; 
        }
    }
    if (!encontrado) { 
        printf("Nenhum livro encontrado com o autor \"%s\".\n", autor);
    }
}

void buscarPorCodigo(struct Livro biblioteca[], int contador, int codigoLivro) {
    for (int i = 0; i < contador; i++) {
        if (biblioteca[i].codigoLivro == codigoLivro) { 
            printf("-------------------\n");
            printf("Livro encontrado:\n");
            printf("Título: %s\n", biblioteca[i].titulo);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Ano de Publicação: %d\n", biblioteca[i].anoPublicacao);
            printf("Código do Livro: %d\n", biblioteca[i].codigoLivro);
            printf("Disponibilidade: %s\n\n", biblioteca[i].disponibilidade ? "Disponível" : "Indisponível");
            return; 
        }
    }
    printf("Nenhum livro encontrado com o código %d.\n", codigoLivro);
}

void listarLivros(struct Livro biblioteca[], int contador, int apenasDisponiveis) {
    printf("Listagem de Livros:\n");
    int encontrou = 0; 
    for (int i = 0; i < contador; i++) {
        if (apenasDisponiveis == 0 || biblioteca[i].disponibilidade == 1) {
            printf("-------------------\n");
            printf("Título: %s\n", biblioteca[i].titulo);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Ano de Publicação: %d\n", biblioteca[i].anoPublicacao);
            printf("Código do Livro: %d\n", biblioteca[i].codigoLivro);
            printf("Disponibilidade: %s\n\n", biblioteca[i].disponibilidade ? "Disponível" : "Indisponível");
            encontrou = 1; 
        }
    }
    if (!encontrou) {
        printf("Nenhum livro encontrado.\n");
    }
}



int main() {
    
    struct Livro biblioteca[CAPACIDADE_MAXIMA]; 
    int contador = 0;
    int opcao; 
    int codigo; 
    char titulo[50];
    char autor[50];
    struct Livro livro;

    while (1) {
        printf("Menu:\n");
        printf("1. Adicionar Livro\n");
        printf("2. Remover Livro\n");
        printf("3. Buscar Livro por Título\n");
        printf("4. Buscar Livro por Autor\n");
        printf("5. Buscar Livro por Código\n");
        printf("6. Listar Todos os Livros\n");
        printf("7. Listar Apenas Livros Disponíveis\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: 
                if (contador >= CAPACIDADE_MAXIMA) {
                    printf("O acervo está cheio!\n");
                    break;
                }
                printf("Digite o título do livro: ");
                scanf(" %[^\n]s", livro.titulo); 
                printf("Digite o autor do livro: ");
                scanf(" %[^\n]s", livro.autor);
                printf("Digite o ano de publicação: ");
                scanf("%d", &livro.anoPublicacao);
                printf("Digite o código do livro: ");
                scanf("%d", &livro.codigoLivro);
                printf("Digite a disponibilidade (1 para disponível, 0 para não disponível): ");
                scanf("%d", &livro.disponibilidade);
                adicionarLivro(biblioteca, &contador, livro);
                break;

            case 2: 
                printf("Digite o código do livro para remover: ");
                scanf("%d", &codigo);
                removerLivro(biblioteca, &contador, codigo);
                break;

            case 3: 
                printf("Digite o título do livro para buscar: ");
                scanf(" %[^\n]s", titulo);
                buscarPorTitulo(biblioteca, contador, titulo);
                break;

            case 4: 
                printf("Digite o autor do livro para buscar: ");
                scanf(" %[^\n]s", autor);
                buscarPorAutor(biblioteca, contador, autor);
                break;

            case 5: 
                printf("Digite o código do livro para buscar: ");
                scanf("%d", &codigo);
                buscarPorCodigo(biblioteca, contador, codigo);
                break;

            case 6: 
                listarLivros(biblioteca, contador, 0); 
                break;

            case 7: 
                listarLivros(biblioteca, contador, 1); 
                break;

            case 0: 
                printf("Saindo do programa...\n");
                return 0;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;


}