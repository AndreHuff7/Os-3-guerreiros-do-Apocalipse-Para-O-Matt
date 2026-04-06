#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    float preco;
} Produto;

typedef struct {
    char nome[50];
    float nota;
} Aluno;

typedef struct {
    char *nome;
} Usuario;

typedef struct {
    char logradouro[100];
    int numero;
} Endereco;

typedef struct {
    char nome[50];
    Endereco *end;
} Pessoa;

void reset_estoque(Produto *p) {
    if (p != NULL) {
        p->id = 0;
        p->preco = 0.0f;
        printf("Estoque resetado com sucesso!\n");
    }
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    printf("PARTE 1: Entidade Produto\n");
    Produto *prod = malloc(sizeof(Produto));
    if (prod != NULL) {
        prod->id = 101;
        prod->preco = 49.99f;
        printf("Produto ID: %d | Preco: R$ %.2f\n", prod->id, prod->preco);
    }
    printf("\n");

    printf("PARTE 3: Resete de Dados\n");
    if (prod != NULL) {
        printf("Antes do reset - ID: %d | Preco: %.2f\n", prod->id, prod->preco);
        reset_estoque(prod);
        printf("Depois do reset - ID: %d | Preco: %.2f\n", prod->id, prod->preco);
        free(prod);
        prod = NULL; 
    }
    printf("\n");


    printf("PARTE 2: Vetor de Registros\n");
    Aluno *turma = malloc(3 * sizeof(Aluno));
    if (turma != NULL) {
        for (int i = 0; i < 3; i++) {
            sprintf(turma[i].nome, "Aluno %d", i + 1); 
            turma[i].nota = 7.5f + i;                  
            printf("Lancado: %s - Nota: %.2f\n", turma[i].nome, turma[i].nota);
        }
        free(turma);
        turma = NULL;
    }
    printf("\n");


    printf("PARTE 4: Strings Dinamicas\n");
    Usuario *user = malloc(sizeof(Usuario));
    if (user != NULL) {
        char buffer[256]; 
        printf("Digite o nome do usuario: ");
        
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {

            buffer[strcspn(buffer, "\n")] = '\0';

            user->nome = malloc((strlen(buffer) + 1) * sizeof(char));
            
            if (user->nome != NULL) {
                strcpy(user->nome, buffer); 
                printf("Usuario dinamico criado: %s\n", user->nome);
                
                free(user->nome);
            }
        }
        free(user);
        user = NULL;
    }
    printf("\n");


    printf("PARTE 5: Composicao Dinamica\n");
    Pessoa *pes = malloc(sizeof(Pessoa));
    Endereco *end = malloc(sizeof(Endereco));
    
    if (pes == NULL || end == NULL) {
        printf("Falha na alocacao da Parte 5.\n");
        if (pes) free(pes);
        if (end) free(end);
    } else {
        strcpy(end->logradouro, "Avenida da Programacao");
        end->numero = 1024;

        strcpy(pes->nome, "Andre Huff");
        
        pes->end = end;
        
        printf("Pessoa: %s\n", pes->nome);
        printf("Mora em: %s, %d\n", pes->end->logradouro, pes->end->numero);
        
        free(pes->end);
        free(pes);
    }
    printf("\n");

    return 0;
}