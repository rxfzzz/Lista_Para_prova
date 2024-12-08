#include <stdio.h>
#include <stdlib.h>

// Protótipo da função merge
void merge(int arr[], int left, int mid, int right);

/**
 * Realiza a ordenação de um array utilizando o algoritmo Merge Sort.
 * @param arr Array de inteiros a ser ordenado.
 * @param left Índice inicial do subarray.
 * @param right Índice final do subarray.
 */
void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return; // Retorna se o array tiver 0 ou 1 elemento
    }

    // Divide o array ao meio
    int mid = left + (right - left) / 2;
    
    // Ordena as duas metades
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Mescla as duas metades ordenadas
    merge(arr, left, mid, right);
}

/**
 * Mescla dois subarrays ordenados em um único array ordenado.
 * @param arr Array original que receberá a ordenação.
 * @param left Índice inicial do subarray esquerdo.
 * @param mid Índice do meio do subarray.
 * @param right Índice final do subarray direito.
 */
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Cria os arrays temporários
    int* leftArr = (int*)malloc(n1 * sizeof(int));
    int* rightArr = (int*)malloc(n2 * sizeof(int));

    // Copia os dados para os arrays temporários
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    // Mescla os dois subarrays temporários de volta no array original
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    // Copia os elementos restantes do subarray esquerdo, se houver
    while (i < n1) {
        arr[k++] = leftArr[i++];
    }

    // Copia os elementos restantes do subarray direito, se houver
    while (j < n2) {
        arr[k++] = rightArr[j++];
    }

    // Libera a memória alocada para os arrays temporários
    free(leftArr);
    free(rightArr);
}

/**
 * Método principal para demonstrar o funcionamento do Merge Sort.
 */
int main() {
    int arr[] = {34, 8, 64, 51, 32, 65, 21, 91};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array antes da ordenação: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Ordena o array utilizando Merge Sort
    mergeSort(arr, 0, size - 1);

    printf("Array após a ordenação: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}