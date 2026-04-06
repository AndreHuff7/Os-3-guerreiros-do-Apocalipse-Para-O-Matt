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

void liberar_matriz(int **matriz, int linhas) {
    if (matriz != NULL) {
        for (int i = 0; i < linhas; i++) {
            free(matriz[i]); 
        }
        free(matriz); 
    }
}

Produto* clonar(const Produto *origem) {
    if (origem == NULL) return NULL;
    
    Produto *novo = malloc(sizeof(Produto));
    if (novo != NULL) {
        novo->id = origem->id;
        novo->preco = origem->preco;
    }
    return novo;
}

Produto* buscar_produto_sequencial(Produto *vetor, int tamanho, int id_buscado) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i].id == id_buscado) {
            return &vetor[i]; 
        }
    }
    return NULL; 
}

Aluno** filtrar_aprovados(Aluno *turma, int total_alunos, int *qtd_aprovados) {
    *qtd_aprovados = 0;
    
    for (int i = 0; i < total_alunos; i++) {
        if (turma[i].nota > 7.0f) {
            (*qtd_aprovados)++;
        }
    }

    Aluno **aprovados = malloc((*qtd_aprovados) * sizeof(Aluno*));
    if (aprovados == NULL) return NULL;

    int index = 0;
    for (int i = 0; i < total_alunos; i++) {
        if (turma[i].nota > 7.0f) {
            aprovados[index] = &turma[i];
            index++; 
        }
    }

    return aprovados;
}


int main() {

    printf("1. REDIMENSIONAMENTO\n");
    int *array_dinas = malloc(2 * sizeof(int));
    if (array_dinas != NULL) {
        array_dinas[0] = 100;
        array_dinas[1] = 200;
        printf("Array incial [2 pos]: {%d, %d}\n", array_dinas[0], array_dinas[1]);
        
        int *array_temp = realloc(array_dinas, 4 * sizeof(int));
        if (array_temp != NULL) {
            array_dinas = array_temp;
            array_dinas[2] = 300;
            array_dinas[3] = 400;
            printf("Array Expandido (realloc) [4 pos]: {%d, %d, %d, %d}\n", array_dinas[0], array_dinas[1], array_dinas[2], array_dinas[3]);
        }
        free(array_dinas); 
    }
    printf("\n");

    printf("2. MATRIZ\n");
    int M = 3; 
    int N = 4; 
    
    int **matriz_dinamica = malloc(M * sizeof(int*));
    if (matriz_dinamica != NULL) {
        for (int i = 0; i < M; i++) {

            matriz_dinamica[i] = malloc(N * sizeof(int));
            for (int j = 0; j < N; j++) {
                matriz_dinamica[i][j] = i + j; 
                printf("%d ", matriz_dinamica[i][j]);
            }
            printf("\n");
        }

        liberar_matriz(matriz_dinamica, M); 
        printf("Memória M*N liberada profundamente.\n");
    }
    printf("\n");

    printf("4. VETOR DE STRING\n");
    int qtde_cidades = 2; 

    char **array_cidades = malloc(qtde_cidades * sizeof(char*));
    char bf[200]; 

    strcpy(bf, "Osasco"); 
    array_cidades[0] = malloc((strlen(bf) + 1) * sizeof(char));
    strcpy(array_cidades[0], bf);

    strcpy(bf, "Londres, Reino Unido");
    array_cidades[1] = malloc((strlen(bf) + 1) * sizeof(char));
    strcpy(array_cidades[1], bf);

    for (int i = 0; i < qtde_cidades; i++) {
        printf("City %d: %s\n", i+1, array_cidades[i]);
        free(array_cidades[i]); 
    }
    free(array_cidades);
    printf("\n");

    printf("5. CLONAGEM\n");
    Produto iphone_original = {900, 5000.0f}; 
    Produto *iphone_clone = clonar(&iphone_original);
    
    if (iphone_clone != NULL) {
        printf("Original ID: %d | Preco = %f\n", iphone_original.id, iphone_original.preco);
        printf("CLONE    ID: %d | Preco = %f\n", iphone_clone->id, iphone_clone->preco);
        free(iphone_clone);
    }
    printf("\n");

    printf("6. BUSCANDO ITEM DE ID 5\n");

    Produto lista_loja[10];
    for (int i = 0; i < 10; i++) {
        lista_loja[i].id = i + 1;
        lista_loja[i].preco = 50.0f + (i * 2);
    }

    Produto* ref = buscar_produto_sequencial(lista_loja, 10, 5); 
    if (ref != NULL) {
        printf("O Produto do ID=5 foi Achado na Memoria. Ele Custa: R$ %.2f\n", ref->preco);
    }
    printf("\n");

    printf("7. FILTRAGEM (TURMA)\n");
    Aluno classe[4] = { {"Eduardo", 10.0}, {"Jose", 8.5}, {"Judas", 4.0}, {"Matheus", 2.0} };
    int q_aprov = 0;
    
    Aluno **alunos_vencedores = filtrar_aprovados(classe, 4, &q_aprov);
    if (alunos_vencedores) {
        printf("Total de Vencedores > 7 de nota: %d\n", q_aprov);
        for (int i = 0; i < q_aprov; i++) {
            printf("+ %s [Media: %.2f]\n", alunos_vencedores[i]->nome, alunos_vencedores[i]->nota);
        }
        free(alunos_vencedores); 
    }
    printf("\n");

    printf("8. COMPLEXIDADE DE ALGORITMOS (BIG-O)\n");
    int tam = 5;
    int operacoes = 0;

    for (int i = 0; i < tam; i++) {       
        for (int j = 0; j < tam; j++) {     
           operacoes++; 
        }
    }
    printf("Para varrer uma Matriz Quadrada de tamanho %dx%d o Loop Aninhado precisou realizar: %d Operacoes.\n", tam, tam, operacoes);

    return 0;
}
