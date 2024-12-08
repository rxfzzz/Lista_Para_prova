#include <stdio.h>

/**
 * Realiza a partição do array e retorna o índice do pivô.
 * @param arr Array de inteiros.
 * @param low Índice inferior do subarray.
 * @param high Índice superior do subarray.
 * @return Índice do pivô.
 */
int partition(int arr[], int low, int high);

/**
 * Realiza a ordenação de um array utilizando o algoritmo Quick Sort.
 * @param arr Array de inteiros a ser ordenado.
 * @param low Índice inferior do subarray a ser ordenado.
 * @param high Índice superior do subarray a ser ordenado.
 */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Pivô e partição do array
        int pi = partition(arr, low, high);

        // Ordena as duas partes separadas pelo pivô
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/**
 * Realiza a partição do array e retorna o índice do pivô.
 * @param arr Array de inteiros.
 * @param low Índice inferior do subarray.
 * @param high Índice superior do subarray.
 * @return Índice do pivô.
 */
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // O último elemento é escolhido como pivô
    int i = (low - 1); // Índice do menor elemento

    // Organiza os elementos para que os menores que o pivô fiquem à esquerda e os maiores à direita
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Troca os elementos
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Coloca o pivô na posição correta
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

/**
 * Método principal para demonstrar o funcionamento do Quick Sort.
 */
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]); // Calcula o tamanho do array

    printf("Array antes da ordenação: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Ordena o array utilizando Quick Sort
    quickSort(arr, 0, n - 1);

    printf("Array após a ordenação: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
