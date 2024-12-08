#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para medir o tempo de execução
long measureExecutionTime(void (*method)(int[], int, int), int arr[], int n, int extra) {
    clock_t startTime = clock();
    method(arr, n, extra);
    clock_t endTime = clock();
    return (long)(endTime - startTime);
}

// Declaração da função partition
int partition(int arr[], int low, int high);

// Algoritmos de ordenação
void bubbleSort(int arr[], int n, int extra) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n, int extra) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// Algoritmos de busca
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Função para imprimir o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função principal
int main() {
    int n;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    printf("Preencha o array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Opções para o usuário escolher algoritmo de ordenação
    printf("Escolha um algoritmo de ordenação:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Quick Sort\n");
    int sortChoice;
    scanf("%d", &sortChoice);

    long sortTime = 0;
    switch (sortChoice) {
        case 1:
            sortTime = measureExecutionTime((void (*)(int[], int, int))bubbleSort, arr, n, 0);
            break;
        case 2:
            sortTime = measureExecutionTime((void (*)(int[], int, int))selectionSort, arr, n, 0);
            break;
        case 3:
            sortTime = measureExecutionTime((void (*)(int[], int, int))quickSort, arr, n, 0);
            break;
        default:
            printf("Opção inválida\n");
            free(arr);
            return 0;
    }

    // Exibindo o tempo de execução da ordenação
    printf("Array ordenado: ");
    printArray(arr, n);
    printf("Tempo de execução da ordenação (em microssegundos): %ld\n", sortTime);

    // Opções para o usuário escolher algoritmo de busca
    printf("Escolha um algoritmo de busca:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    int searchChoice;
    scanf("%d", &searchChoice);

    printf("Digite o elemento para buscar: ");
    int key;
    scanf("%d", &key);

    long searchTime = 0;
    int searchResult = -1;
    switch (searchChoice) {
        case 1:
            searchTime = measureExecutionTime((void (*)(int[], int, int))linearSearch, arr, n, key);
            searchResult = linearSearch(arr, n, key);
            break;
        case 2:
            searchTime = measureExecutionTime((void (*)(int[], int, int))binarySearch, arr, n, key);
            searchResult = binarySearch(arr, n, key);
            break;
        default:
            printf("Opção inválida\n");
            free(arr);
            return 0;
    }

    // Exibindo o resultado da busca
    if (searchResult != -1) {
        printf("Elemento encontrado no índice: %d\n", searchResult);
    } else {
        printf("Elemento não encontrado.\n");
    }

    // Exibindo o tempo de execução da busca
    printf("Tempo de execução da busca (em microssegundos): %ld\n", searchTime);

    // Liberar memória
    free(arr);
    return 0;
}
