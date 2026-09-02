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

void adicionar_produto(){
    printf("Produto adicionado");
}
void listar_produtos(){
    printf("Lista de produtos");
}
Produto* buscar_produto(){
    return 0;
}
void atualizar_estoque(){
    printf("Produto atualizado");
}
void remover_produto(){
    printf("produto removido");
}
void liberar_memoria(){
    printf("memória liberada");
}


int main(){
    int opcao = 0;
     //Mostra e lê as opções
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
        //redirecionando para as funções certas
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
    if( opcao == 6){
        liberar_memoria();
    }
    return 0;
}