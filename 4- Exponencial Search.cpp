#include <stdio.h>
#include <math.h>

// Protótipo da função binarySearch
int binarySearch(int arr[], int target, int left, int right);

/**
 * Realiza o Exponential Search em um array ordenado.
 * @param arr Array de inteiros ordenado.
 * @param size Tamanho do array.
 * @param target Elemento a ser buscado.
 * @return Índice do elemento encontrado, ou -1 se não encontrado.
 */
int exponentialSearch(int arr[], int size, int target) {
    int n = size;

    // Caso especial: verifica se o primeiro elemento é o alvo
    if (arr[0] == target) {
        return 0; // Retorna o índice 0 se o elemento for encontrado no início
    }

    // Encontra o intervalo onde o elemento pode estar, dobrando o índice a cada iteração
    int bound = 1;
    while (bound < n && arr[bound] <= target) {
        bound *= 2; // Dobra o limite superior
    }

    // Realiza busca binária no intervalo definido
    return binarySearch(arr, target, bound / 2, (bound < n ? bound : n) - 1);
}

/**
 * Realiza busca binária em um intervalo específico do array.
 * @param arr Array de inteiros ordenado.
 * @param target Elemento a ser buscado.
 * @param left Limite inferior do intervalo.
 * @param right Limite superior do intervalo.
 * @return Índice do elemento encontrado, ou -1 se não encontrado.
 */
int binarySearch(int arr[], int target, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2; // Calcula o índice do meio para evitar estouro de inteiros
        if (arr[mid] == target) {
            return mid; // Retorna o índice se o elemento for encontrado
        }
        if (arr[mid] < target) {
            left = mid + 1; // Move o limite inferior para a direita
        } else {
            right = mid - 1; // Move o limite superior para a esquerda
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}

/**
 * Método principal para demonstrar o funcionamento do Exponential Search.
 */
int main() {
    // Array ordenado necessário para o Exponential Search funcionar
    int sortedArray[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31};
    int target = 15;
    int size = sizeof(sortedArray) / sizeof(sortedArray[0]);

    // Exibe o array ordenado
    printf("Array ordenado: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArray[i]);
    }
    printf("\n");

    // Busca o elemento alvo na lista ordenada
    int index = exponentialSearch(sortedArray, size, target);

    // Exibe o resultado da busca
    if (index != -1) {
        printf("Elemento %d encontrado no índice %d.\n", target, index);
    } else {
        printf("Elemento %d não encontrado.\n", target);
    }

    return 0;
}