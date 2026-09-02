/*
ANA JULIA YAGUTI MATILHA - 10436655
CAROLINA LEE - 10440304
PEDRO CASAS PEQUENO JUNIOR - 10437031
*/

#include <stdio.h>
#include <stdlib.h> 

// Definição da struct
typedef struct {
    int codigo;
    char *nome;
    float preco;
    int quantidade;
} Produto;
 //Funções
void adicionar_produto(){
    /*
    - O usuário informa: nome, preço e quantidade.
    - O sistema gera automaticamente um código único (incremental).
    - O vetor de produtos deve ser **realocado dinamicamente** para acomodar o novo produto (use `realloc`).
    - O nome do produto deve ter memória alocada individualmente.
    */
   printf("--- Adicionar Produto ---");
}
void listar_produtos(){
    /*- Exibe todos os produtos cadastrados em formato tabular.
    - Mostra: código, nome, preço, quantidade e **valor em estoque** (preço × quantidade).
    - Ao final, exibe o **valor total do estoque** (soma de todos os valores em estoque).*/
    printf("--- Lista de Produtos ---");
}
Produto* buscar_produto(){
    /*- O usuário informa um código.
    - O sistema busca e exibe as informações do produto, ou informa que não foi encontrado.
    - A busca deve ser implementada em uma **função separada** que retorne um ponteiro para o produto encontrado (ou `NULL`).*/
    return 0;
}
void atualizar_estoque(){
    /*- O usuário informa o código do produto e a nova quantidade.
    - O sistema deve usar a função de busca (item 3) para localizar o produto.
    - Utilize **passagem por referência** para modificar a quantidade.*/
    printf("--- Atualizar Estoque ---");
}
void remover_produto(){
    /*- O usuário informa o código do produto a ser removido.
    - O sistema deve:
    1. Localizar o produto no vetor
    2. Liberar a memória do nome (`free`)
    3. Reorganizar o vetor (deslocar elementos)
    4. Realocar o vetor para o novo tamanho (`realloc`)
    - **Atenção especial** à ordem de liberação de memória!*/
    printf("--- Atualizar Estoque ---");
}
void liberar_memoria(){
    /*- Antes de encerrar, o programa **deve liberar toda a memória alocada**:
    - Primeiro: liberar cada `nome` individualmente
    - Depois: liberar o vetor de produtos
    - Exiba uma mensagem confirmando que a memória foi liberada.*/
    printf("Liberando memória...");
}


int main(){
    int opcao = 0;
     //Mostra e lê as opções do menu
    printf("========================================\n");
    printf("    SISTEMA DE CADASTRO DE PRODUTOS     \n");
    printf("========================================\n");
    printf("\nMenu:\n1. Adicionar produto\n2. Listar produtos\n3. Buscar produto\n4. Atualizar estoque\n5. Remover produto\n6. Sair");

    while (opcao != 6){
        //Válidação básica
        printf("\nOpção: ");
        scanf("%d", &opcao);
        while ( (opcao<=0) || (opcao>=7)){
            printf("\nOpção: ");
            scanf("%d", &opcao);
        }
        //redirecionando para as funções certas, menos a opção de sair que ficou para fora
        if (opcao == 1){
            adicionar_produto();
        }
        else if (opcao == 2 ){
            listar_produtos();
        }
        else if (opcao == 3){
            buscar_produto();
        }
        else if (opcao == 4){
            atualizar_estoque();
        }
        else if (opcao == 5){
            remover_produto();
        }
    }
    //opção 6 menu, Sair
    if( opcao == 6){
        liberar_memoria();
    }
    return 0;
}