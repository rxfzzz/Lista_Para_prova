#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

/**
 * Função auxiliar para comparar elementos durante a ordenação de baldes.
 * @param a Ponteiro para o primeiro número.
 * @param b Ponteiro para o segundo número.
 * @return Retorna valor de comparação entre os dois números.
 */
int compare(const void *a, const void *b) {
    return (*(float*)a - *(float*)b);
}

/**
 * Realiza a ordenação de um array de números em ponto flutuante utilizando o algoritmo Bucket Sort.
 * @param arr Array de números em ponto flutuante.
 * @param n Tamanho do array.
 */
void bucketSort(float arr[], int n) {
    if (n <= 0) return; // Não faz nada se o array estiver vazio

    // Cria os "baldes" para organizar os elementos
    float **buckets = (float**)malloc(n * sizeof(float*));
    int *bucketSizes = (int*)malloc(n * sizeof(int)); // Para controlar o tamanho de cada balde

    for (int i = 0; i < n; i++) {
        buckets[i] = (float*)malloc(BUCKET_SIZE * sizeof(float));
        bucketSizes[i] = 0; // Inicializa os tamanhos dos baldes
    }

    // Distribui os elementos nos baldes com base no seu valor
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * n); // Calcula o índice do balde com base no valor
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i]; // Coloca o número no balde correto
    }

    // Ordena cada balde individualmente e coloca os elementos de volta no array original
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (bucketSizes[i] > 0) {
            qsort(buckets[i], bucketSizes[i], sizeof(float), compare); // Ordena o balde com qsort
            for (int j = 0; j < bucketSizes[i]; j++) {
                arr[index++] = buckets[i][j]; // Coloca os elementos ordenados de volta no array
            }
        }
    }

    // Libera a memória alocada para os baldes
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

/**
 * Método principal para demonstrar o funcionamento do Bucket Sort.
 */
int main() {
    float arr[] = {0.34f, 0.8f, 0.64f, 0.51f, 0.32f, 0.65f, 0.21f, 0.91f};
    int n = sizeof(arr) / sizeof(arr[0]); // Calcula o tamanho do array

    printf("Array antes da ordenação: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    // Ordena o array utilizando Bucket Sort
    bucketSort(arr, n);

    printf("Array após a ordenação: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    /**
     * Explicação:
     * 
     * O Bucket Sort divide o array em baldes, com cada balde representando um intervalo de valores. Cada balde é
     * ordenado separadamente (geralmente por outro algoritmo como o Insertion Sort), e depois os baldes são
     * combinados para formar o array final ordenado.
     *
     * Vantagens:
     * 
     * - Eficiente para listas de números com uma distribuição uniforme.
     * - Pode ser mais eficiente que algoritmos O(n^2) como Selection Sort em casos específicos.
     *
     * Desvantagens:
     * 
     * - Depende da distribuição dos dados e pode ser ineficiente se os dados não forem distribuídos uniformemente.
     * - Requer espaço adicional para os baldes.
     */

    return 0;
}
