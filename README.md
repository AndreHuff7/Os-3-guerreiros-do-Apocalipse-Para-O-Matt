# Os 3 guerreiros do Apocalipse Para O Matt

## Conteúdo

### 1. Fundamentos de Memória (exercicio1.c)
* **Alocação Dinâmica**: Uso de `malloc` e `free` para tipos `float` e `int`.
* **Segurança**: Verificação de retorno nulo em alocações de grande porte (1GB).
* **Vetores e Aritmética**: Implementação de vetores dinâmicos e navegação via aritmética de ponteiros.
* **Referência**: Função para modificar valores originais via ponteiros.

### 2. Estruturas e Strings (exercicio2.c)
* **Manipulação de Structs**: Alocação dinâmica de registros e funções para resetar dados.
* **Strings Dinâmicas**: Dimensionamento exato de memória para strings baseado na entrada do usuário.
* **Composição**: Estruturas aninhadas com alocação independente para campos de ponteiro.

### 3. Matrizes e Algoritmos (exercicio3.c)
* **Redimensionamento**: Uso de `realloc` para expansão de arrays em tempo de execução.
* **Matrizes Dinâmicas**: Alocação de matrizes bidimensionais com função de liberação profunda.
* **Filtros e Busca**: Algoritmos para clonagem de estruturas, busca sequencial e filtragem de sub-vetores.
* **Complexidade**: Demonstração de loop aninhado para exemplificar complexidade $O(n^2)$.

### 4. TAD Ponto (execicio.h, exer3.c)
* **Abstração**: Interface definida em arquivo de cabeçalho com implementação oculta no arquivo fonte.
* **Operações**: Funções para criação, destruição e cálculo de distância entre coordenadas.

## Compilação
```bash
gcc exercicio1.c -o ex1
gcc exercicio2.c -o ex2
gcc exercicio3.c -o ex3 -lm
gcc exer3.c main.c -o tad_ponto -lm
