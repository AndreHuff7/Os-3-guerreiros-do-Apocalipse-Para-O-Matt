#include <stdio.h>
#include <stdlib.h>

void dobrarValor(int *ptr) {
    if (ptr != NULL) {
        *ptr = (*ptr) * 2;
    }
}

int main() {
    printf("PARTE 1: Alocacao Simples\n");
    float *ptrFloat = (float *)malloc(sizeof(float));
    
    if (ptrFloat != NULL) {
        printf("Digite um valor float: ");
        scanf("%f", ptrFloat);
        printf("Valor armazenado: %.2f\n", *ptrFloat); 
        free(ptrFloat); 
    } else {
        printf("Erro na alocacao de memoria para o float.\n");
    }
    printf("\n");

    printf("PARTE 2: Gestao Segura\n");
    size_t tamanho1GB = 1024ULL * 1024ULL * 1024ULL;
    void *ptrGB = malloc(tamanho1GB);

    if (ptrGB == NULL) {
        printf("Erro: Nao foi possivel alocar 1GB de memoria!\n");
    } else {
        printf("Sucesso: 1GB alocado com sucesso.\n");
        free(ptrGB);
        printf("Memoria de 1GB liberada imediatamente.\n");
    }
    printf("\n");

    printf("PARTE 3: Vetores Dinamicos\n");
    int N;
    printf("Digite o tamanho do vetor (N): ");
    scanf("%d", &N);
    
    if (N > 0) {
        int *vetorDin = (int *)malloc(N * sizeof(int));
        
        if (vetorDin != NULL) {
            int soma = 0;
            for (int i = 0; i < N; i++) {
                printf("Digite o valor para a posicao %d: ", i);
                scanf("%d", &vetorDin[i]);
                soma += vetorDin[i];
            }
            float media = (float)soma / N;
            printf("A media aritmetica dos valores e: %.2f\n", media);
            
            free(vetorDin);
        } else {
             printf("Erro na alocacao do vetor dinamico.\n");
        }
    }
    printf("\n");

    printf("PARTE 4: Aritmetica de Ponteiros\n");
    int *vetorPonteiros = malloc(5 * sizeof(int));
    
    if (vetorPonteiros != NULL) {
        for (int i = 0; i < 5; i++) {
            *(vetorPonteiros + i) = (i + 1) * 10; 
        } 
        
        printf("Imprimindo o vetor usando aritmetica (ptr++ e *):\n");
        int *ptrAux = vetorPonteiros; 
        
        for (int i = 0; i < 5; i++) {
            printf("%d ", *ptrAux);
            ptrAux++; 
        }
        printf("\n");
        
        free(vetorPonteiros); 
    }
    printf("\n");

    printf("PARTE 5: Teste Passagem por Referencia\n");
    int var = 15;
    printf("Valor original no main: %d\n", var);
    
    dobrarValor(&var); 
    
    printf("Valor apos chamar dobrarValor(): %d\n", var);
    printf("\n");

    return 0;
}