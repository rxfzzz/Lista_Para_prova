#include <stdio.h>

/**
 * Realiza a busca binária em um array ordenado.
 * @param arr Array de inteiros ordenado.
 * @param size Tamanho do array.
 * @param target Elemento a ser buscado.
 * @return Índice do elemento encontrado, ou -1 se não encontrado.
 */
int binarySearch(int arr[], int size, int target) {
    int left = 0; // Início do intervalo de busca
    int right = size - 1; // Fim do intervalo de busca

    // Continua enquanto o intervalo de busca for válido
    while (left <= right) {
        // Calcula o índice do elemento central
        int mid = left + (right - left) / 2;

        // Verifica se o elemento central é o alvo
        if (arr[mid] == target) {
            return mid; // Elemento encontrado
        } 
        // Se o alvo é maior que o elemento central, descarta a metade esquerda
        else if (arr[mid] < target) {
            left = mid + 1;
        } 
        // Se o alvo é menor que o elemento central, descarta a metade direita
        else {
            right = mid - 1;
        }
    }
    return -1; // Elemento não encontrado
}

/**
 * Método principal para demonstrar o funcionamento do Binary Search.
 */
int main() {
    // Array ordenado necessário para o Binary Search funcionar
    int sortedArray[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int target = 17;
    int size = sizeof(sortedArray) / sizeof(sortedArray[0]);

    // Exibe o array ordenado
    printf("Array ordenado: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArray[i]);
    }
    printf("\n");

    // Busca o elemento alvo na lista ordenada
    int index = binarySearch(sortedArray, size, target);

    // Exibe o resultado da busca
    if (index != -1) {
        printf("Elemento %d encontrado no índice %d.\n", target, index);
    } else {
        printf("Elemento %d não encontrado.\n", target);
    }

    /**
     * Por que a lista precisa estar ordenada:
     * 
     * O Binary Search funciona dividindo a lista em metades sucessivas.
     * Se o valor no meio for menor que o alvo, elimina-se a metade esquerda.
     * Se o valor no meio for maior que o alvo, elimina-se a metade direita.
     * Isso só é possível se a lista estiver ordenada, pois a ordenação garante
     * que os elementos à esquerda do meio são sempre menores e os à direita
     * são sempre maiores. Caso contrário, o algoritmo pode descartar a parte
     * da lista onde o elemento alvo realmente está.
     */
    
    return 0;
}
