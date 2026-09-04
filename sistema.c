/*
ANA JULIA YAGUTI MATILHA - 10436655
CAROLINA LEE - 10440304
PEDRO CASAS PEQUENO JUNIOR - 10437031
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// Definição da struct
typedef struct {
    int codigo;
    char *nome;
    float preco;
    int quantidade;
} Produto;

//Funções
Produto* criacao_vetor(){
    // Produto *vetor;
    // int n = 250;
    // vetor = (Produto*) malloc(n * sizeof(Produto));
    
    // if (vetor == NULL) {
    //     printf("Erro: Falha na alocação de memória!\n");
    //     return NULL;
    // }
    return NULL;
}

void adicionar_produto(Produto **v,int *tamanho){
    //variáveis pro código funcionar
    char nome[100];
    float preco;
    int qtd, id;
    /*
    - O usuário informa: nome, preço e quantidade.
    - O sistema gera automaticamente um código único (incremental).
    - O vetor de produtos deve ser **realocado dinamicamente** para acomodar o novo produto (use `realloc`).
    - O nome do produto deve ter memória alocada individualmente. (não entendi isso)*/

    //Gerar código único
    // Para calcular o tamanho real do vetor+1
    static int cont = 1;
    id = cont;

    //Pegas as infos do produto segundo o usuário
    printf("--- Adicionar Produto ---");
    printf("\nNome: ");
    scanf(" %[^\n]", nome);
    printf("\nPreço: ");
    scanf("%f", &preco);
    //validação preço
    while (preco<0){
        printf("\nPreço não pode ser negativo, digite novamente: ");
        scanf("%f", &preco);
    }
    printf("\nQuantidade: ");
    scanf("%d", &qtd);
    //validação qtd 
    while (qtd<0){
        printf("\nQuantidade nâo pode ser negativo, digite novamente: ");
        scanf("%d", &qtd);
    }

    //Cria o produto  na struct
    // Produto v;
    // v.codigo=id;
    // v.nome=nome;
    // v.preco=preco;
    // v.quantidade=qtd;

    //ponteiro de ponteiro
    Produto *novo_vetor = (Produto*) realloc(*v, (*tamanho + 1) * sizeof(Produto));
    if (novo_vetor == NULL){
        printf("Erro: Falha na realocação\n");
        return;
    }
    *v = novo_vetor;
    
    (*v)[*tamanho].nome = (char*) malloc(strlen(nome) + 1);
    if ((*v)[*tamanho].nome == NULL){
        printf("Erro: Falha na alocação para nome\n");
        return;
    }
    
    strcpy((*v)[*tamanho].nome, nome);
    (*v)[*tamanho].codigo = id;
    (*v)[*tamanho].preco = preco;
    (*v)[*tamanho].quantidade = qtd;

    (*tamanho) ++;
    cont ++;

    printf("Produto adicionado com código %d!\n", id);

    //realoca vetor
    // v = (Produto*) realloc(v, novo_tamanho * sizeof(Produto));
    
    // if (v == NULL) {
    //     printf("Erro: Falha na realocação!\n");
    //     return;
    // }

    // //Adiciona o produto no vetor
    // for (int i = 0; i < novo_tamanho; i++) {
    //     if (i == novo_tamanho) {
    //         v[i] = p;
    //     }
    // }


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
        float valor_estoque; //valor total do produto
        valor_estoque = v[i].preco * v[i].quantidade; 
        printf("     %d | %s | R$ %.2f |    %d     | R$ %.2f\n", v[i].codigo, v[i].nome, v[i].preco, v[i].quantidade, valor_estoque); 
        total_estoque = total_estoque + valor_estoque; } //valor do estoque todo
        printf("-----------------------------------------------------------\n"); 
    printf("Valor total do estoque: R$ %.2f\n", total_estoque);

}
Produto* buscar_produto(Produto *v, int tamanho, int codigo){
    /*- O usuário informa um código.
    - O sistema busca e exibe as informações do produto, ou informa que não foi encontrado.
    - A busca deve ser implementada em uma **função separada** que retorne um ponteiro para o produto encontrado (ou `NULL`).*/
    for (int i =0; i < tamanho; i++) {
        if (v[i].codigo == codigo){
            return &v[i];
        }
    }
    printf("Produto não encontrado\n");
    return NULL;
}
void atualizar_estoque(Produto *v, int tamanho){
    /*- O usuário informa o código do produto e a nova quantidade.
    - O sistema deve usar a função de busca (item 3) para localizar o produto.
    - Utilize **passagem por referência** para modificar a quantidade.*/
    int codigo;
    int nova_qtd;

    printf("--- Atualizar Estoque ---");
    printf("\nCódigo do produto: ");
    scanf("%d", &codigo);

    //usa função buscar_produto para localizar o produto
    Produto *p = buscar_produto(v, tamanho, codigo);
    //validação
    if (p == NULL) {
        printf("Não localizado!");
        return;
    }

    printf("Nova quantidade: ");
    scanf("%d", &nova_qtd);
    //validação nova_qtd não pode ser negativa
    while (nova_qtd<0){
        printf("\nNova quantidade errada, digite novamente: ");
        scanf("%d", &nova_qtd);
    }
    //passsagem por referencia
    p->quantidade = nova_qtd;
    printf("Estoque atualizado com sucesso!\n");
}
void remover_produto(Produto **v, int *tamanho){
    /*- O usuário informa o código do produto a ser removido.
    - O sistema deve:
    1. Localizar o produto no vetor
    2. Liberar a memória do nome (`free`)
    3. Reorganizar o vetor (deslocar elementos)
    4. Realocar o vetor para o novo tamanho (`realloc`)
    - **Atenção especial** à ordem de liberação de memória!*/
    int codigo;
    printf("--- Remover Produto ---");
    printf("\nCódigo do produto: ");
    scanf("%d", &codigo);

    //1
    int indice = -1;
    char salva_produto[*tamanho];
    for (int i = 0; i < *tamanho; i++) {
        if((*v)[i].codigo == codigo){
            indice = i;
            strcpy(salva_produto, (*v)[i].nome);
            break;
        }
    }

    //2
    free((*v)[indice].nome);

    //3
    for (int i = indice; i < *tamanho; i++) {
        (*v)[i] = (*v)[i+1];
    }

    (*tamanho) --;
    //4
    printf("%d", *tamanho);
    if (*tamanho == 0) {
        free(*v);
        *v = NULL;
        printf("Produto removido com sucesso!\n");
        return;
    }

    //ponteiro de ponteiro
    Produto *novo_vetor = (Produto*) realloc(*v, (*tamanho) * sizeof(Produto));    
    if (novo_vetor == NULL){
        printf("Erro: Falha na realocação da remoção\n");
        return;
    }
    *v = novo_vetor;

    printf("Produto '%s' removido com sucesso!", salva_produto);


}
void liberar_memoria(Produto *v, int tamanho){
    // ese liberar memória é de um produto em especifico
    /*- Antes de encerrar, o programa **deve liberar toda a memória alocada**:
    - Primeiro: liberar cada `nome` individualmente
    - Depois: liberar o vetor de produtos
    - Exiba uma mensagem confirmando que a memória foi liberada.*/
    printf("Liberando memória...\n");

    for (int i = 0; i < tamanho; i++) {
        printf("Memória do produto '%s' liberada.\n", v[i].nome);
        free(v[i].nome);//dá free no nome
    }
    free(v);//da free no vetor de produtos
    printf("Vetor de produtos liberado.\n");
    printf("Programa encerrado.\n");
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
            adicionar_produto(&vetor_produtos, &tamanho);
        }
        else if (opcao == 2 ){
            listar_produtos(vetor_produtos, tamanho);
        }
        else if (opcao == 3){
            int codigo_busca;
            printf("--- Buscar Produto ---");
            printf("\nCódigo do produto: ");
            scanf("%d", &codigo_busca);
 
            Produto *encontrado = buscar_produto(vetor_produtos, tamanho, codigo_busca);
            if (encontrado != NULL){
                printf("\nProduto encontrado:\n");
                printf("Código: %d\n", encontrado->codigo);
                printf("Nome: %s\n", encontrado->nome);
                printf("Preço: R$ %.2f\n", encontrado->preco);
                printf("Quantidade: %d\n", encontrado->quantidade);
            } else {
                printf("\nProduto não encontrado!\n");
            }
        }
        else if (opcao == 4){
            atualizar_estoque(vetor_produtos, tamanho);
        }
        else if (opcao == 5){
            remover_produto(&vetor_produtos, &tamanho);
        }
    }
    //opção 6 menu, Sair
    if( opcao == 6){
        liberar_memoria(vetor_produtos, tamanho);
    }
    return 0;
}