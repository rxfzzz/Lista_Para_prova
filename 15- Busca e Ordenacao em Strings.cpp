#include <stdio.h>
#include <string.h>

// Função para mesclar dois subarrays
void merge(char* arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    char* L[n1], * R[n2];
    
    // Copiando os dados para os arrays temporários L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copiando os elementos restantes de L[], se houver
    while (i < n1) arr[k++] = L[i++];
    
    // Copiando os elementos restantes de R[], se houver
    while (j < n2) arr[k++] = R[j++];
}

// Implementação de Merge Sort para Strings
void mergeSort(char* arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Função para particionar o array para Quick Sort
int partition(char* arr[], int low, int high) {
    char* pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            char* temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    char* temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// Implementação de Quick Sort para Strings
void quickSort(char* arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Implementação de Binary Search para Strings
int binarySearch(char* arr[], int n, char* key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int result = strcmp(arr[mid], key);
        if (result == 0) return mid;
        if (result < 0) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    // Array de palavras
    char* words[] = {"banana", "apple", "grape", "kiwi", "orange"};
    int n = sizeof(words) / sizeof(words[0]);

    printf("Antes da ordenação:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    // Ordenando com Merge Sort
    mergeSort(words, 0, n - 1);
    printf("Após ordenação (Merge Sort):\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    // Ordenando com Quick Sort
    char* wordsForQuickSort[] = {"banana", "apple", "grape", "kiwi", "orange"};
    int m = sizeof(wordsForQuickSort) / sizeof(wordsForQuickSort[0]);
    quickSort(wordsForQuickSort, 0, m - 1);
    printf("Após ordenação (Quick Sort):\n");
    for (int i = 0; i < m; i++) {
        printf("%s ", wordsForQuickSort[i]);
    }
    printf("\n");

    // Procurando por uma palavra usando Binary Search
    char* key = "kiwi";
    int index = binarySearch(words, n, key);
    if (index != -1) {
        printf("A palavra '%s' foi encontrada no índice: %d\n", key, index);
    } else {
        printf("A palavra '%s' não foi encontrada.\n", key);
    }

    return 0;
}