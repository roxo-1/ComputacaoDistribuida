#include <stdio.h>
#include <stdlib.h> 

// Definição da struct
typedef struct {
    int codigo;
    char *nome;
    float preco;
    int quantidade;
} Produto;

void adicionar_produto();
void listar_produtos();
Produto* buscar_produto();
void atualizar_estoque();
void remover_produto();
void liberar_memoria();

int menu(){
    int opcao;
    printf("========================================\n");
    printf("    SISTEMA DE CADASTRO DE PRODUTOS     \n");
    printf("========================================\n");
    printf("\nMenu:\n1. Adicionar produto\n2. Listar produtos\n3. Buscar produto\n4. Atualizar estoque\n5. Remover produto\n6. Sair\n");
    scanf("Opção: %d", &opcao);
    return opcao;
}

int main(){
    int opcaoEscolhida = menu();
    while ( (opcaoEscolhida<1) || (opcaoEscolhida>6)){
        printf("Opção inválida, escolha novamente.\n");
        menu();
    }
    if (opcaoEscolhida == 1){
        adicionar_produto();
    }
    else if (opcaoEscolhida == 2 ){
        listar_produtos();
    }
    else if (opcaoEscolhida == 3){
        buscar_produto();
    }
    else if (opcaoEscolhida == 4){
        atualizar_estoque();
    }
    else if (opcaoEscolhida == 5){
        remover_produto();
    }
    else if( opcaoEscolhida == 6){
        liberar_memoria();
    }
    printf("fim");
    return 0;
}