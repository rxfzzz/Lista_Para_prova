#include <stdio.h>
#include <stdlib.h> // Para qsort
#include <string.h>

// Definição da estrutura do livro
typedef struct {
    char title[100];
    char isbn[20];
} Book;

// Função de comparação para ordenação por ISBN
int compareBooksByIsbn(const void* a, const void* b) {
    const Book* bookA = (const Book*)a; // Uso de const para garantir segurança
    const Book* bookB = (const Book*)b;
    return strcmp(bookA->isbn, bookB->isbn);
}

// Função de busca binária para encontrar um livro pelo ISBN
int binarySearch(const Book books[], int size, const char* isbn) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; // Evita overflow
        int result = strcmp(books[mid].isbn, isbn);
        if (result == 0) {
            return mid; // ISBN encontrado
        }
        if (result < 0) {
            left = mid + 1; // Busca à direita
        } else {
            right = mid - 1; // Busca à esquerda
        }
    }
    return -1; // ISBN não encontrado
}

int main() {
    // Array de livros
    Book books[] = {
        {"Book A", "978-1-234-56789-0"},
        {"Book B", "978-1-234-56789-1"},
        {"Book C", "978-1-234-56789-2"},
        {"Book D", "978-1-234-56789-3"}
    };
    int size = sizeof(books) / sizeof(books[0]); // Calcula o tamanho do array

    // Ordena os livros pelo ISBN para garantir a pré-condição da busca binária
    qsort(books, size, sizeof(Book), compareBooksByIsbn);

    // ISBN a ser buscado
    const char* isbnToFind = "978-1-234-56789-2";
    int index = binarySearch(books, size, isbnToFind);

    // Exibe o resultado da busca
    if (index != -1) {
        printf("Livro encontrado: %s\n", books[index].title);
    } else {
        printf("Livro não encontrado.\n");
    }

    return 0;
}
