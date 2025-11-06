#include <stdio.h>
#include <string.h>
void printString(char* texto);
void cadastroProduto(struct gerenciaVarejo loja[]);
void exibirProduto(struct gerenciaVarejo loja[]);

struct gerenciaVarejo {
	char nomeProduto[50];
	float precoProduto;
};

gerenciaVarejo loja[100]; //pode ter um maximo de 100 produtos
int totalProdutos = 0;

int main() {
    char nomeLoja[50];
    int opcao;

    printf("Bem-vindo ao Sistema de Gerenciamento de Varejo!\n");
    printf("Para iniciar, digite o nome da sua loja: ");
    scanf("%s", nomeLoja);
    printf("Cadastro realizado. Iniaremos gerencia para: ");
    printString(nomeLoja);

    while (1) {
        printf("\n====== MENU ======\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produto\n");
        printf("3 - Buscar produto pelo nome\n");
        printf("4 - Mostrar preco mais caro e mais barato\n");
        printf("5 - Media de preco\n");
        printf("6 - Mudar Nome da loja\n");
        printf("0 - Sair\n");
        printf("Escolha uma op: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("Op 1 selecionada: Cadastrar produto.\n");
            cadastroProduto(loja);
            break;
        case 2:
            printf("Op 2 selecionada: Listar produtos.\n");
            exibirProduto(loja);
            break;
        case 3:
            printf("Op 3 selecionada: Buscar produto pelo nome.\n");
            break;
        case 4:
            printf("Op 4 selecionada: Mostrar preco mais caro e mais barato.\n");
            break;
        case 5:
            printf("Op 5 selecionada: Media de precos.\n");
            break;
        case 6:
            printf("Op 6 selecionada: Mudar nome da loja.\n");
            break;
        case 0:
            printf("Saindo do programa...\n");
            return 0;
        default:
            printf("Invalido. Tente novamente.\n");
        }
    }

    return 0;
}

void cadastroProduto(struct gerenciaVarejo loja[]) {
    int quantidade;
    printf("Deseja cadastrar quantos produtos? ");
    scanf("%d", &quantidade);

    if (totalProdutos + quantidade > 100) {
        printf("O cadastro esta limitado a 100 produtos.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        printf("Nome Produto: ");
        scanf("%s", loja[totalProdutos].nomeProduto);
        printf("Valor Produto: ");
        scanf("%f", &loja[totalProdutos].precoProduto);

        totalProdutos++;
    }

    printf("Na base de dados temos %d produtos cadastrados!\n", totalProdutos);

}

void exibirProduto(struct gerenciaVarejo loja[]) {
   for (int i = 0; i < totalProdutos; i++) {
       printf("Produto %d:\n", i + 1);
       printf("Nome Produto: ");
       printString(loja[i].nomeProduto);
       printf("Valor Produto: R$ %.2f\n", loja[i].precoProduto);
   }
}

void printString(char* texto) {

    for (int i = 0; i < strlen(texto); i++) {
        printf("%c", texto[i]);
    }
    printf("\n");
}