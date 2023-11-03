#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

void printUniqueCharacters(char arr[], int size) {
    // Сортировка массива символов
    qsort(arr, size, sizeof(char), cmpfunc);

    printf("Символы, которые встречаются по одному разу в алфавитном порядке: ");
    
    bool foundUnique = false;
    for (int i = 0; i < size; i++) {
        // Проверяем, является ли текущий символ уникальным
        if (arr[i] != arr[i+1] && arr[i] != arr[i-1]) {
            printf("%c ", arr[i]);
            foundUnique = true;
        }
    }

    if (!foundUnique) {
        printf("Нет уникальных символов во введенном массиве.");
    }

    printf("\n");
}

int main() {
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    char *arr = (char *)malloc(size * sizeof(char));

    printf("Введите символы массива: ");
    for (int i = 0; i < size; i++) {
        scanf(" %c", &arr[i]);
    }

    printUniqueCharacters(arr, size);

    free(arr);

    return 0;
}
