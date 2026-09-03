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
Produto* criacao_vetor(){
    Produto *vetor;
    int n = 250;
    vetor = (Produto*) malloc(n * sizeof(Produto));
    
    if (vetor == NULL) {
        printf("Erro: Falha na alocação de memória!\n");
        return NULL;
    }
    return vetor;
}

void adicionar_produto(Produto *v,int tamanho){
    //variáveis pro código funcionar
    char nome[100];
    float preco;
    int qtd, id;
    int novo_tamanho = tamanho+1;
    /*
    - O usuário informa: nome, preço e quantidade.
    - O sistema gera automaticamente um código único (incremental).
    - O vetor de produtos deve ser **realocado dinamicamente** para acomodar o novo produto (use `realloc`).
    - O nome do produto deve ter memória alocada individualmente. (não entendi isso)*/

    //Gerar código único
    // Para calcular o tamanho real do vetor+1
    int cont;
    for (int i = 0; i<sizeof(v); i++){
        cont++;
    }
    id = cont+1;

    //Pegas as infos do produto segundo o usuário
    printf("--- Adicionar Produto ---");
    printf("\nNome: ");
    scanf("%s", nome);
    printf("\nPreço: ");
    scanf("%f", &preco);
    printf("\nQuantidade: ");
    scanf("%d", &qtd);
    printf("-------------------------");

    //Cria o produto  na struct
    Produto p;
    p.codigo=id;
    p.nome=nome;
    p.preco=preco;
    p.quantidade=qtd;


    //realoca vetor
    v = (Produto*) realloc(v, novo_tamanho * sizeof(Produto));
    
    if (v == NULL) {
        printf("Erro: Falha na realocação!\n");
        return;
    }

    //Adiciona o produto no vetor
    for (int i = 0; i < novo_tamanho; i++) {
        if (i == novo_tamanho) {
            v[i] = p;
        }
    }


}
void listar_produtos(Produto *v, int tamanho){
    /*- Exibe todos os produtos cadastrados em formato tabular.
    - Mostra: código, nome, preço, quantidade e **valor em estoque** (preço × quantidade).
    - Ao final, exibe o **valor total do estoque** (soma de todos os valores em estoque).*/
    float total_estoque =0;
    printf("\n--- Lista de Produtos ---\n"); 
    printf("Codigo | Nome   |  Preco  | Quantidade | Valor em Estoque\n"); 
    printf("--------------------------------------------------------\n"); 
    for (int i = 0; i < tamanho; i++) { 
        float valor_estoque; 
        valor_estoque = v[i].preco * v[i].quantidade; 
        printf("     %d | %s | R$ %.2f |    %d     | R$ %.2f\n", v[i].codigo, v[i].nome, v[i].preco, v[i].quantidade, valor_estoque); 
        total_estoque = total_estoque + valor_estoque; } 
        printf("-----------------------------------------------------------\n"); 
    printf("Valor total do estoque: R$ %.2f\n", total_estoque);

}
Produto* buscar_produto(Produto *v, int tamanho, int codigo){
    /*- O usuário informa um código.
    - O sistema busca e exibe as informações do produto, ou informa que não foi encontrado.
    - A busca deve ser implementada em uma **função separada** que retorne um ponteiro para o produto encontrado (ou `NULL`).*/
    for (int i =0; i < tamnho; i++) {
        if (v[i].codigo == codigo){
            return &v[i];
        }
    }
    return NULL;
}
void atualizar_estoque(Produto *v){
    /*- O usuário informa o código do produto e a nova quantidade.
    - O sistema deve usar a função de busca (item 3) para localizar o produto.
    - Utilize **passagem por referência** para modificar a quantidade.*/
    printf("--- Atualizar Estoque ---");
}
void remover_produto(Produto *v){
    /*- O usuário informa o código do produto a ser removido.
    - O sistema deve:
    1. Localizar o produto no vetor
    2. Liberar a memória do nome (`free`)
    3. Reorganizar o vetor (deslocar elementos)
    4. Realocar o vetor para o novo tamanho (`realloc`)
    - **Atenção especial** à ordem de liberação de memória!*/
    printf("--- Atualizar Estoque ---");
}
void liberar_memoria(Produto *v){
    // ese liberar memória é de um produto em especifico
    /*- Antes de encerrar, o programa **deve liberar toda a memória alocada**:
    - Primeiro: liberar cada `nome` individualmente
    - Depois: liberar o vetor de produtos
    - Exiba uma mensagem confirmando que a memória foi liberada.*/
    printf("Liberando memória...");

    for (int i = 0; i < tamanho; i++) {
        printf(v[i].nome);
        free(v[i].nome);
    }
    free(v);
    printf("Vetor de produtos liberado.");
    printf("Programa encerrado.");
}


int main(){
    Produto *vetor_produtos = criacao_vetor();
    int opcao = 0;
    int tamanho = 0;
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
            adicionar_produto(vetor_produtos, tamanho);
        }
        else if (opcao == 2 ){
            listar_produtos(vetor_produtos, tamanho);
        }
        else if (opcao == 3){
            buscar_produto(vetor_produtos);
        }
        else if (opcao == 4){
            atualizar_estoque(vetor_produtos);
        }
        else if (opcao == 5){
            remover_produto(vetor_produtos);
        }
    }
    //opção 6 menu, Sair
    if( opcao == 6){
        liberar_memoria(vetor_produtos);
    }
    return 0;
}