#include <stdio.h>

/**
 * Realiza a ordenação de um array utilizando o algoritmo Shell Sort.
 * @param arr Array de inteiros a ser ordenado.
 * @param size Tamanho do array.
 */
void shellSort(int arr[], int size) {
    int n = size;

    // Começa com uma grande distância (gap) e vai diminuindo
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Realiza a inserção com o gap atual
        for (int i = gap; i < n; i++) {
            int temp = arr[i]; // Elemento a ser inserido
            int j = i;

            // Desloca os elementos para a posição correta dentro do "gap"
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            // Coloca o elemento na posição correta
            arr[j] = temp;
        }
    }
}

/**
 * Método principal para demonstrar o funcionamento do Shell Sort.
 */
int main() {
    int arr[] = {34, 8, 64, 51, 32, 65, 21, 91};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array antes da ordenação: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Ordena o array utilizando Shell Sort
    shellSort(arr, size);

    printf("Array após a ordenação: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /**
     * Explicação:
     * 
     * O Shell Sort é uma versão generalizada da ordenação por inserção. Ele começa com um intervalo (gap)
     * grande e vai diminuindo esse intervalo, o que permite que os elementos se movam mais rapidamente para suas
     * posições corretas. A ideia é que ao realizar a ordenação com gaps maiores, a ordem dos elementos se aproxima
     * de uma ordenação regular, fazendo com que as inserções subsequentes sejam mais eficientes.
     *
     * Vantagens:
     * 
     * - Mais rápido que a ordenação por inserção para grandes listas.
     * - A escolha do gap impacta o desempenho; sequências de gap como Hibbard e Knuth são mais eficientes.
     *
     * Desvantagens:
     * 
     * - Menos eficiente que algoritmos mais avançados como Merge Sort e Quick Sort.
     * - O desempenho depende fortemente da escolha do gap.
     */

    return 0;
}
