#include <stdio.h>
#include <stdlib.h>

// Функция для отображения контекстного меню
void displayMenu() {
    printf("Лабораторная работа No4\n");
    printf("Выполнил: Смольский Александр\n");
    printf("Группа: 453505\n");
    printf("Задание: Определить диагональ с наибольшей суммой чисел в трёхмерном массиве.\n");
    printf("===========================================\n");
}

// Функция для нахождения суммы диагоналей
void findMaxDiagonalSum(int ***array, int n) {
    int sumMainDiagonal = 0;
    int sumSecondaryDiagonal = 0;

    // Обход главной диагонали
    for (int i = 0; i < n; i++) {
        sumMainDiagonal += array[i][i][i];
    }

    // Обход побочной диагонали
    for (int i = 0; i < n; i++) {
        sumSecondaryDiagonal += array[i][i][n - 1 - i];
    }

    // Определяем, какая диагональ имеет большую сумму
    if (sumMainDiagonal > sumSecondaryDiagonal) {
        printf("Главная диагональ имеет большую сумму: %d\n", sumMainDiagonal);
    } else if (sumSecondaryDiagonal > sumMainDiagonal) {
        printf("Побочная диагональ имеет большую сумму: %d\n", sumSecondaryDiagonal);
    } else {
        printf("Суммы главной и побочной диагоналей равны: %d\n", sumMainDiagonal);
    }
}

int main() {
    int n;
    char choice;
    int ***array;
    int repeat = 1;

    while (repeat) {
        // Вывод контекстного меню
        displayMenu();

        // Ввод размера массива с проверкой
        printf("Введите размерность трёхмерного массива: ");
        while (scanf("%d", &n) != 1 || n <= 0) {
            printf("Неверный ввод. Пожалуйста, введите положительное целое число: ");
            while (getchar() != '\n'); // очищаем буфер
        }

        // Динамическое выделение памяти для трёхмерного массива
        array = (int ***)malloc(n * sizeof(int **));
        for (int i = 0; i < n; i++) {
            array[i] = (int **)malloc(n * sizeof(int *));
            for (int j = 0; j < n; j++) {
                array[i][j] = (int *)malloc(n * sizeof(int));
            }
        }

        // Ввод элементов массива
        printf("Введите элементы трёхмерного массива:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    while (scanf("%d", &array[i][j][k]) != 1 || array[i][j][k] < 0) {
                        printf("Неверный ввод. Пожалуйста, введите неотрицательное целое число:\n");
                        while (getchar() != '\n'); // очищаем буфер
                    }
                }
            }
        }

        // Нахождение диагонали с наибольшей суммой
        findMaxDiagonalSum(array, n);

        // Освобождение памяти
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                free(array[i][j]);
            }
            free(array[i]);
        }
        free(array);

        // Спрашиваем, хочет ли пользователь повторить
        printf("Хотите выполнить программу снова? (y/n): ");
        while (getchar() != '\n'); // очищаем буфер
        choice = getchar();

        if (choice != 'y' && choice != 'Y') {
            repeat = 0;
        }
    }

    return 0;
}