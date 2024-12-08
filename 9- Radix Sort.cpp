#include <stdio.h>
#include <stdlib.h>

// Protótipo da função countingSortByDigit
void countingSortByDigit(int arr[], int n, int exp);

/**
 * Realiza a ordenação de um array de inteiros utilizando o algoritmo Radix Sort.
 * @param arr Array de inteiros a ser ordenado.
 * @param n Tamanho do array.
 */
void radixSort(int arr[], int n) {
    int max = arr[0];

    // Encontra o maior número no array
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Realiza a ordenação por dígitos (começando pelo menor dígito)
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSortByDigit(arr, n, exp); // Ordena por dígito específico (unidades, dezenas, etc.)
    }
}

/**
 * Ordena o array utilizando o Counting Sort com base em um dígito específico.
 * @param arr Array de inteiros a ser ordenado.
 * @param n Tamanho do array.
 * @param exp O dígito a ser utilizado na ordenação (ex.: unidades, dezenas, etc.)
 */
void countingSortByDigit(int arr[], int n, int exp) {
    int output[n]; // Array de saída
    int count[10] = {0}; // Contagem dos dígitos (0 a 9)

    // Contagem dos dígitos no array
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Ajusta a contagem para armazenar as posições dos elementos
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Preenche o array de saída com os elementos ordenados por dígito
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copia o array de saída para o array original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

/**
 * Método principal para demonstrar o funcionamento do Radix Sort.
 */
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]); // Calcula o tamanho do array

    printf("Array antes da ordenação: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Ordena o array utilizando Radix Sort
    radixSort(arr, n);

    printf("Array após a ordenação: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
