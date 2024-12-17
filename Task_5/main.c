#include <stdio.h>
#include <stdlib.h>

int readInt() {
    int input;
    while (scanf("%d", &input) != 1 || input <= 0) {
        printf("Неверный ввод! Введите положительное число: ");
        while (getchar() != '\n');  
    }
    return input;
}

void inputFieldSize(int *n, int *m) {
    while (1) {
        printf("Введите количество строк (n): ");
        *n = readInt();  
        printf("Введите количество столбцов (m): ");
        *m = readInt(); 

        if (*n == 1 && *m == 1) {
            printf("Размер 1x1 недопустим! Пожалуйста, введите другие размеры.\n");
        } else {
            break;  
        }
    }
}

char **createField(int n, int m) {
    char **field = (char **)malloc(n * sizeof(char *));  
    for (int i = 0; i < n; i++) {
        field[i] = (char *)malloc(m * sizeof(char));  
    }
    return field;
}

void inputField(char **field, int n, int m) {
    printf("Введите поле игры (символы '.' для пустого места и '*' для бомбы):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            while (1) {
                scanf(" %c", &field[i][j]);  
                if (field[i][j] == '.' || field[i][j] == '*') {
                    break;
                } else {
                    printf("Неверный ввод! Введите символ '.' или '*': ");
                }
            }
        }
    }
}

void countMines(char **field, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '*') {
                continue;  
            }

            int mineCount = 0;
            
            if (i > 0 && j > 0 && field[i-1][j-1] == '*') mineCount++;  // Верхний левый
            if (i > 0 && field[i-1][j] == '*') mineCount++;               // Верхний
            if (i > 0 && j < m - 1 && field[i-1][j+1] == '*') mineCount++; // Верхний правый
            if (j > 0 && field[i][j-1] == '*') mineCount++;               // Левый
            if (j < m - 1 && field[i][j+1] == '*') mineCount++;           // Правый
            if (i < n - 1 && j > 0 && field[i+1][j-1] == '*') mineCount++; // Нижний левый
            if (i < n - 1 && field[i+1][j] == '*') mineCount++;           // Нижний
            if (i < n - 1 && j < m - 1 && field[i+1][j+1] == '*') mineCount++; // Нижний правый

            field[i][j] = '0' + mineCount;  // Преобразуем число в символ
        }
    }
}

void printField(char **field, int n, int m) {
    printf("Результат:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c ", field[i][j]);
        }
        printf("\n");
    }
}

void freeField(char **field, int n) {
    for (int i = 0; i < n; i++) {
        free(field[i]);  
    }
    free(field);  
}

int main() {
    printf("Программа, дополняющая поле для игры <сапер> размерами n*m символов числами, как в оригинальной игре.\n");
    printf("Выполнил Смольский Александр, группа 453505.\n\n");
    int n, m;
    char choice;

    while (1) {
        inputFieldSize(&n, &m);

        char **field = createField(n, m);

        inputField(field, n, m);

        countMines(field, n, m);

        printField(field, n, m);

        freeField(field, n);
        
        printf("\nХотите выполнить программу снова? (Если да, введите 1, иначе любой другой символ для выхода): ");
        while (getchar() != '\n');  
        scanf("%c", &choice);

        if (choice != '1') {
            printf("Выполнение программы завершено.\n\n");
            break;
        }
    }

    return 0;
}