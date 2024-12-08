#include <stdio.h>

/**
 * Realiza a busca de um elemento em um array ordenado utilizando o algoritmo Ternary Search.
 * O Ternary Search divide a lista em três partes e faz comparações para determinar em qual parte
 * o elemento procurado pode estar, repetindo o processo recursivamente.
 *
 * @param arr Array de inteiros ordenado.
 * @param key O valor a ser buscado no array.
 * @return O índice do elemento encontrado ou -1 se o elemento não for encontrado.
 */
int ternarySearch(int arr[], int left, int right, int key) {
    if (right >= left) {
        // Calcula as posições intermediárias (dividindo o intervalo em três partes)
        int mid1 = left + (right - left) / 3;     // Posição do primeiro ponto médio
        int mid2 = right - (right - left) / 3;    // Posição do segundo ponto médio

        // Verifica se o key é igual a algum dos pontos intermediários
        if (arr[mid1] == key) {
            return mid1;  // Se encontrar, retorna o índice de mid1
        }
        if (arr[mid2] == key) {
            return mid2;  // Se encontrar, retorna o índice de mid2
        }

        // Se o valor procurado (key) for menor que o valor em mid1, a busca continua na parte esquerda
        if (key < arr[mid1]) {
            return ternarySearch(arr, left, mid1 - 1, key);
        }
        // Se o valor procurado (key) for maior que o valor em mid2, a busca continua na parte direita
        if (key > arr[mid2]) {
            return ternarySearch(arr, mid2 + 1, right, key);
        }

        // Caso contrário, o valor procurado deve estar entre mid1 e mid2, então a busca continua entre esses índices
        return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
    }

    return -1;  // Retorna -1 se o elemento não for encontrado no array
}

/**
 * Função principal para testar a implementação do Ternary Search.
 */
int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23};
    int n = sizeof(arr) / sizeof(arr[0]); // Calcula o tamanho do array

    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int key = 15;  // Elemento a ser procurado no array
    int result = ternarySearch(arr, 0, n - 1, key);

    // Verifica se o elemento foi encontrado ou não
    if (result == -1) {
        printf("Elemento não encontrado.\n");
    } else {
        printf("Elemento encontrado no índice: %d\n", result);
    }

    /**
     * Explicação:
     * 
     * O Ternary Search é uma variação da busca binária, mas em vez de dividir o array em duas partes,
     * ele divide o array em três partes e faz comparações com os elementos nessas posições.
     *
     * Como funciona:
     * 
     * - O array é dividido em três partes (mid1, mid2), e a busca é feita comparando o valor procurado
     *   com os valores em mid1 e mid2.
     * - Se o valor não for encontrado em nenhum desses pontos, a busca é feita recursivamente nas partes
     *   esquerda, entre mid1 e mid2, ou direita, dependendo de onde o valor pode estar.
     *
     * Vantagens:
     * 
     * - O Ternary Search pode ser mais eficiente que o Binary Search em algumas situações, pois ele faz duas comparações por iteração,
     *   o que pode reduzir o número de recursões em certos casos.
     *
     * Desvantagens:
     * 
     * - O Ternary Search não é amplamente utilizado, pois a diferença de desempenho em relação ao Binary Search é pequena na maioria
     *   dos casos, e o Binary Search é mais simples.
     */

    return 0;
}
