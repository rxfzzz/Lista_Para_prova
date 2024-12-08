#include <stdio.h>
#include <stdlib.h>

// Função auxiliar para mesclar as duas metades ordenadas
void merge(int arr[], int left, int mid, int right);

// Função para ordenar utilizando Selection Sort (instável)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Troca dos elementos
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Função para ordenar utilizando Bubble Sort (estável)
void bubbleSort(int arr[], int n) {
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // Se não houve troca, o array já está ordenado
        if (!swapped) break;
    }
}

// Função para ordenar utilizando Merge Sort (estável)
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Divide o array em duas metades
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Mescla as duas metades
        merge(arr, left, mid, right);
    }
}

// Função auxiliar para mesclar as duas metades ordenadas
void merge(int arr[], int left, int mid, int right) {
    // Tamanho das duas sublistas
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Arrays temporários para armazenar as duas metades
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    // Copiar os dados para os arrays temporários
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    // Índices para os arrays L, R e o array original
    int i = 0, j = 0, k = left;

    // Mesclar os dois arrays de volta no array original
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copiar os elementos restantes de L[], se houver
    while (i < n1) arr[k++] = L[i++];

    // Copiar os elementos restantes de R[], se houver
    while (j < n2) arr[k++] = R[j++];

    // Liberar a memória alocada
    free(L);
    free(R);
}

// Função para imprimir o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Exemplo de um array com elementos iguais
    int array1[] = {4, 2, 4, 1, 3};
    int array2[] = {4, 2, 4, 1, 3};
    int array3[] = {4, 2, 4, 1, 3};
    int n = 5;  // Tamanho dos arrays

    printf("Array original: \n");
    printArray(array1, n);

    // Demonstrando Selection Sort (instável)
    selectionSort(array1, n);
    printf("Após Selection Sort (instável): \n");
    printArray(array1, n);

    printf("\nArray original: \n");
    printArray(array2, n);

    // Demonstrando Bubble Sort (estável)
    bubbleSort(array2, n);
    printf("Após Bubble Sort (estável): \n");
    printArray(array2, n);

    printf("\nArray original: \n");
    printArray(array3, n);

    // Demonstrando Merge Sort (estável)
    mergeSort(array3, 0, n - 1);
    printf("Após Merge Sort (estável): \n");
    printArray(array3, n);

    return 0;
}
