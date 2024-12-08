#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Funções de ordenação
void bucketSort(double arr[], int n);
void mergeSort(double arr[], int left, int right);
void merge(double arr[], int left, int mid, int right);

// Funções de busca
int binarySearch(double arr[], int n, double key);
int interpolationSearch(double arr[], int n, double key);

// Função de comparação para qsort
int compare(const void* a, const void* b);

int main() {
    // Notas dos alunos no intervalo [0, 100]
    double grades[SIZE] = {97.5, 82.4, 65.0, 90.3, 88.6, 75.2, 50.4, 92.1, 60.8, 85.0};

    // Exibição do menu para escolha do algoritmo
    int choice;
    printf("Escolha uma opção:\n");
    printf("1 - Algoritmos de Ordenação\n");
    printf("2 - Algoritmos de Busca\n");
    if (scanf("%d", &choice) != 1) {
        printf("Entrada inválida.\n");
        return 1;
    }

    switch (choice) {
        case 1: {
            // Algoritmos de Ordenação
            printf("Escolha o algoritmo de ordenação:\n");
            printf("1 - Bucket Sort\n");
            printf("2 - Merge Sort\n");
            int sortChoice;
            if (scanf("%d", &sortChoice) != 1) {
                printf("Entrada inválida.\n");
                return 1;
            }

            double gradesCopy[SIZE];
            for (int i = 0; i < SIZE; i++) gradesCopy[i] = grades[i];

            printf("Antes da ordenação: ");
            for (int i = 0; i < SIZE; i++) printf("%.1f ", gradesCopy[i]);
            printf("\n");

            switch (sortChoice) {
                case 1:
                    bucketSort(gradesCopy, SIZE);
                    printf("Após ordenação (Bucket Sort): ");
                    break;
                case 2:
                    mergeSort(gradesCopy, 0, SIZE - 1);
                    printf("Após ordenação (Merge Sort): ");
                    break;
                default:
                    printf("Opção inválida.\n");
                    return 1;
            }

            for (int i = 0; i < SIZE; i++) printf("%.1f ", gradesCopy[i]);
            printf("\n");
            break;
        }
        case 2: {
            // Algoritmos de Busca
            printf("Escolha o algoritmo de busca:\n");
            printf("1 - Binary Search\n");
            printf("2 - Interpolation Search\n");
            int searchChoice;
            if (scanf("%d", &searchChoice) != 1) {
                printf("Entrada inválida.\n");
                return 1;
            }

            double gradeToFind;
            printf("Digite a nota para procurar: ");
            if (scanf("%lf", &gradeToFind) != 1) {
                printf("Entrada inválida.\n");
                return 1;
            }

            // Ordena as notas para busca
            qsort(grades, SIZE, sizeof(double), compare);

            int result = -1;
            switch (searchChoice) {
                case 1:
                    result = binarySearch(grades, SIZE, gradeToFind);
                    printf("Resultado da busca Binária: ");
                    break;
                case 2:
                    result = interpolationSearch(grades, SIZE, gradeToFind);
                    printf("Resultado da busca por Interpolação: ");
                    break;
                default:
                    printf("Opção inválida.\n");
                    return 1;
            }

            if (result != -1)
                printf("Encontrado no índice %d\n", result);
            else
                printf("Não encontrado.\n");

            break;
        }
        default:
            printf("Opção inválida.\n");
            return 1;
    }

    return 0;
}

// Função de comparação para qsort
int compare(const void* a, const void* b) {
    double valA = *(double*)a;
    double valB = *(double*)b;
    return (valA > valB) - (valA < valB);
}

// Implementação do Bucket Sort
void bucketSort(double arr[], int n) {
    if (n <= 1) return;

    double min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int bucketCount = 10;
    double range = max - min;
    double bucketRange = range / bucketCount;

    double buckets[bucketCount][n];
    int bucketSizes[bucketCount];
    for (int i = 0; i < bucketCount; i++) bucketSizes[i] = 0;

    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)((arr[i] - min) / bucketRange);
        if (bucketIndex == bucketCount) bucketIndex--;
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        qsort(buckets[i], bucketSizes[i], sizeof(double), compare);
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

// Implementação do Merge Sort
void mergeSort(double arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(double arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    double L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Implementação do Binary Search
int binarySearch(double arr[], int n, double key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Implementação do Interpolation Search
int interpolationSearch(double arr[], int n, double key) {
    int low = 0, high = n - 1;
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        int pos = low + (int)(((key - arr[low]) / (arr[high] - arr[low])) * (high - low));
        if (arr[pos] == key) return pos;
        if (arr[pos] < key) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}
