#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // Incluído para strcmp

// Função para gerar números aleatórios entre 0 e 99
int randomInt() {
    return rand() % 100;
}

// Função para imprimir um array (opcional, para visualização)
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para testar e exibir o tempo de execução de um algoritmo de ordenação
void testSort(const char* algorithm, int* arr, int n) {
    int* copy = (int*)malloc(n * sizeof(int)); // Cria uma cópia do array
    memcpy(copy, arr, n * sizeof(int));       // Copia o conteúdo original para evitar alteração

    clock_t startTime = clock();  // Marca o início do tempo

    if (strcmp(algorithm, "Shell Sort") == 0) {
        shellSort(copy, n);
    } else if (strcmp(algorithm, "Merge Sort") == 0) {
        mergeSort(copy, 0, n - 1);
    } else if (strcmp(algorithm, "Selection Sort") == 0) {
        selectionSort(copy, n);
    } else if (strcmp(algorithm, "Quick Sort") == 0) {
        quickSort(copy, 0, n - 1);
    } else if (strcmp(algorithm, "Bucket Sort") == 0) {
        bucketSort(copy, n);
    } else if (strcmp(algorithm, "Radix Sort") == 0) {
        radixSort(copy, n);
    }

    clock_t endTime = clock();  // Marca o fim do tempo
    double duration = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    printf("%s durou: %f segundos\n", algorithm, duration);

    free(copy); // Libera a memória alocada para a cópia
}

// Implementação simplificada de Shell Sort
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Implementação simplificada de Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

// Implementação simplificada de Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

// Implementação simplificada de Quick Sort
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

// Implementação simplificada de Bucket Sort
void bucketSort(int arr[], int n) {
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    int range = max - min + 1;
    int* bucket = (int*)calloc(range, sizeof(int));

    for (int i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }

    int index = 0;
    for (int i = 0; i < range; i++) {
        while (bucket[i]-- > 0) {
            arr[index++] = i + min;
        }
    }

    free(bucket);
}

// Implementação simplificada de Radix Sort
void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

void countingSort(int arr[], int n, int exp) {
    int* output = (int*)malloc(n * sizeof(int));
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
}

int main() {
    srand(time(NULL));  // Inicializa a semente para números aleatórios

    int smallArray[] = {5, 2, 9, 1, 5, 6};
    int mediumArray[] = {5, 3, 8, 6, 7, 9, 1, 2, 4};
    int largeArray[10000];

    // Preenchendo o array grande com números aleatórios
    for (int i = 0; i < 10000; i++) {
        largeArray[i] = randomInt();
    }

    printf("Testando Shell Sort:\n");
    testSort("Shell Sort", smallArray, 6);
    testSort("Shell Sort", mediumArray, 9);
    testSort("Shell Sort", largeArray, 10000);

    printf("Testando Merge Sort:\n");
    testSort("Merge Sort", smallArray, 6);
    testSort("Merge Sort", mediumArray, 9);
    testSort("Merge Sort", largeArray, 10000);

    printf("Testando Selection Sort:\n");
    testSort("Selection Sort", smallArray, 6);
    testSort("Selection Sort", mediumArray, 9);
    testSort("Selection Sort", largeArray, 10000);

    printf("Testando Quick Sort:\n");
    testSort("Quick Sort", smallArray, 6);
    testSort("Quick Sort", mediumArray, 9);
    testSort("Quick Sort", largeArray, 10000);

    printf("Testando Bucket Sort:\n");
    testSort("Bucket Sort", smallArray, 6);
    testSort("Bucket Sort", mediumArray, 9);
    testSort("Bucket Sort", largeArray, 10000);

    printf("Testando Radix Sort:\n");
    testSort("Radix Sort", smallArray, 6);
    testSort("Radix Sort", mediumArray, 9);
    testSort("Radix Sort", largeArray, 10000);

    return 0;
}
