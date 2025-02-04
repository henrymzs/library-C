# Sistema de Gerenciamento de Biblioteca

Este projeto é um sistema de gerenciamento de biblioteca desenvolvido em C, que permite ao usuário organizar e consultar um acervo de livros. O sistema suporta operações de adicionar, remover, buscar e listar livros, com uma interface interativa no terminal.

## Funcionalidades
- Adicionar Livro: Permite ao usuário adicionar novos livros à biblioteca.
- Remover Livro: Remove um livro específico com base no código do livro fornecido.
- Buscar Livro por Título, Autor ou Código: Pesquisa na biblioteca com base em critérios de busca específicos. 
- Listar Livros: Lista todos os livros da biblioteca ou apenas aqueles disponíveis.
- Controle de Disponibilidade: Indica se um livro está disponível ou não.

## Estrutura do Código
- `struct Livro`: Estrutura que representa cada livro, contendo informações como título, autor, ano de publicação, código e disponibilidade.

Funções:

- `adicionarLivro()`: Adiciona um novo livro a biblioteca.

- `removerLivro()`: Remove um livro pelo código.

- `buscarPorTitulo()`, `buscarPorAutor()`, `buscarPorCodigo()`: Realizam buscas na biblioteca.

- `listarLivros()`: Exibe os livros de acordo com a disponibilidade.

Menu Interativo: Um loop while que exibe um menu de opções para o usuário interagir com o sistema.


## Exemplo de Uso
Ao executar o programa, você verá um menu interativo no console, onde poderá adicionar, buscar, remover e listar contatos.
- Exemplo de entrada:
```bash
Menu:
1. Adicionar Livro
2. Remover Livro
3. Buscar Livro por Título
4. Buscar Livro por Autor
5. Buscar Livro por Código
6. Listar Todos os Livros
7. Listar Apenas Livros Disponíveis
0. Sair
```


## Instalação e Configuração

1. **Clonar o repositório**:
   Clone este repositório para a sua máquina local:
   ```bash
   git clone https://github.com/henrymzs/gerenciamento-de-biblioteca.git
    ```
2. **Navegar até o Diretório do Projeto**:
    Navegue para a pasta onde o repositório foi clonado:
    ```bash
    cd nome-do-repositorio
    ```
3. **Compilar o Código**:
    No Git Bash ou prompt de comando, compile o código usando o GCC do MinGW:
    ```bash
    gcc -o main.c -o main.c
    ```
    Esse comando criará um executável chamado biblioteca.exe.

4. **Executar o Programa**:
    ```bash
    ./main.c
    ```