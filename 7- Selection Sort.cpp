#include <stdio.h>

/**
 * Realiza a ordenação de um array utilizando o algoritmo Selection Sort.
 * @param arr Array de inteiros a ser ordenado.
 * @param n Tamanho do array.
 */
void selectionSort(int arr[], int n) {
    // Percorre todo o array
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume que o elemento atual é o menor

        // Encontra o menor elemento no restante do array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Atualiza o índice do menor elemento
            }
        }

        // Troca o elemento atual com o menor encontrado
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

/**
 * Método principal para demonstrar o funcionamento do Selection Sort.
 */
int main() {
    int arr[] = {34, 8, 64, 51, 32, 65, 21, 91};
    int n = sizeof(arr) / sizeof(arr[0]); // Calcula o tamanho do array

    printf("Array antes da ordenação: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Ordena o array utilizando Selection Sort
    selectionSort(arr, n);

    printf("Array após a ordenação: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /**
     * Explicação:
     * 
     * O Selection Sort é um algoritmo simples que seleciona o menor elemento da parte não ordenada do array
     * e o coloca na posição correta. Esse processo é repetido até que todo o array esteja ordenado.
     *
     * Vantagens:
     * 
     * - Simples de implementar.
     * - Não requer espaço adicional.
     *
     * Desvantagens:
     * 
     * - Ineficiente para grandes listas, com complexidade O(n^2) no pior e melhor caso.
     * - Realiza muitas trocas e comparações, mesmo quando o array está parcialmente ordenado.
     */

    return 0;
}
