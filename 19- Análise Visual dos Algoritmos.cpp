#include <stdio.h>
#include <stdlib.h>

// Função para imprimir o array (visualização no console)
void printArray(int arr[], int n);

// Funções do Merge Sort
void mergeSort(int arr[], int n);
void mergeSortHelper(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

// Funções do Quick Sort
void quickSort(int arr[], int n);
void quickSortHelper(int arr[], int low, int high);
int partition(int arr[], int low, int high);

// Função do Selection Sort
void selectionSort(int arr[], int n);

int main() {
    int array1[] = {10, 7, 8, 9, 1, 5};
    int array2[] = {10, 7, 8, 9, 1, 5};
    int array3[] = {10, 7, 8, 9, 1, 5};
    int n = 6;  // Tamanho dos arrays

    printf("Merge Sort:\n");
    mergeSort(array1, n);  // Visualizando o Merge Sort
    printf("\n");

    printf("Quick Sort:\n");
    quickSort(array2, n);  // Visualizando o Quick Sort
    printf("\n");

    printf("Selection Sort:\n");
    selectionSort(array3, n);  // Visualizando o Selection Sort
    return 0;
}

// Função para imprimir o array (visualização no console)
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Merge Sort com visualização
void mergeSort(int arr[], int n) {
    mergeSortHelper(arr, 0, n - 1);
}

void mergeSortHelper(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
        printArray(arr, right + 1);  // Visualização após cada fusão
    }
}

void merge(int arr[], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    
    int *leftArr = (int*)malloc(leftSize * sizeof(int));
    int *rightArr = (int*)malloc(rightSize * sizeof(int));

    // Copiar os elementos para os arrays auxiliares
    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < leftSize) arr[k++] = leftArr[i++];
    while (j < rightSize) arr[k++] = rightArr[j++];

    free(leftArr);
    free(rightArr);
}

// Quick Sort com visualização
void quickSort(int arr[], int n) {
    quickSortHelper(arr, 0, n - 1);
}

void quickSortHelper(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        printArray(arr, high + 1);  // Visualização após cada partição
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // Troca arr[i] e arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Troca arr[i + 1] e arr[high]
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Selection Sort com visualização
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Troca arr[i] e arr[minIndex]
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
        printArray(arr, n);  // Visualização após cada troca
    }
}
