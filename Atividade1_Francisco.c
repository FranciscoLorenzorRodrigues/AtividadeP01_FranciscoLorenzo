#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparacoes;
long long movimentacoes;

// Bubble Sort 
void bubbleSort(int arr[], int n) { 
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            comparacoes++;
            if (arr[j] > arr[j + 1]) { 
                temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp;
                movimentacoes++;
            }
        }
    }
}

// Selection Sort 
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            comparacoes++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            movimentacoes++;
        }
    }
}

// Ordem decrescente
void preencherDecrescente(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

int main(int argc, char *argv[]) {
    int tamanhos[] = {100, 1000, 10000};
    int i, t;
    clock_t inicio, fim;
    double tempo_ms;

    // saída
    printf("%-15s %-10s %-12s %-15s %-15s\n", "Algoritmo", "Tamanho", "Tempo (ms)", "Comparacoes", "Movimentacoes");
    printf("-------------------------------------------------------------------------------------\n");

    for (t = 0; t < 3; t++) {
        int n = tamanhos[t];
        int *vetor = (int *)malloc(n * sizeof(int));

        // Teste Bubble Sort 
        preencherDecrescente(vetor, n);
        comparacoes = 0;
        movimentacoes = 0;
        
        inicio = clock();
        bubbleSort(vetor, n);
        fim = clock();
        
        tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
        printf("%-15s %-10d %-12.2f %-15lld %-15lld\n", "Bubble Sort", n, tempo_ms, comparacoes, movimentacoes);

        // Teste Selection Sort
    
        preencherDecrescente(vetor, n);
        comparacoes = 0;
        movimentacoes = 0;
        
        inicio = clock();
        selectionSort(vetor, n);
        fim = clock();
        
        tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
        printf("%-15s %-10d %-12.2f %-15lld %-15lld\n", "Selection Sort", n, tempo_ms, comparacoes, movimentacoes);

        free(vetor); 
    }

    return 0;
}

// Analise: Analisando o resultado do algoritmo na tabela é possível perceber que quanto maior é o tamanho, maior é o tempo, já que também aumentam os números de comparações e movimentações.
// Ao analisar no tamanho 10000 se nota que o tempo do Selection Sort (83.00) foi bem menor que o do Bubble Sort (216.00), isso não se deve às comparações, já que eles fazem a mesma quantidade,
// e sim pelas movimentações. Enquanto o Bubble Sort troca imediatamente a cada posição errada e estamos analisando no pior caso, em toda comparação ele vai movimentar, enquanto o Selection Sort faz
// uma série de comparações primeiro, guarda o índice do menor e só faz uma troca colocando o menor no início e por aí vai até a ordenação acabar.
