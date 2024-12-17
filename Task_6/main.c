#include <stdio.h>
#include <stdlib.h>

int** magic_3(int n) {
    int apl = n / 2;
    static int u = 1;
    int** a = (int**)calloc(n + 2 * apl, sizeof(int*));
    for (int i = 0; i < n + 2 * apl; i++) {
        a[i] = (int*)calloc(n + 2 * apl, sizeof(int));
    }

    int ii = n - 1, jj = 0;
    for (int t = 0; t < n; t++) {
        for (; jj < n + t; ii--, jj++, u++)
            a[ii][jj] = u;
        ii = n + t;
        jj = t + 1;
    }

    // Верхняя часть
    for (int i = 0; i < 2 * apl - 1; i++) {
        for (int j = 0; j < n + 2 * apl; j++) {
            if (a[i][j] != 0 && a[i + n][j] == 0) {
                a[i + n][j] = a[i][j];
            }
        }
    }

    // Нижняя часть
    for (int i = n + apl; i < n + 2 * apl; i++) {
        for (int j = 0; j < n + 2 * apl; j++) {
            if (a[i][j] != 0 && a[i - n][j] == 0) {
                a[i - n][j] = a[i][j];
            }
        }
    }

    // Левая часть
    for (int j = 0; j < 2 * apl - 1; j++) {
        for (int i = 0; i < n + 2 * apl; i++) {
            if (a[i][j] != 0 && a[i][j + n] == 0)
                a[i][j + n] = a[i][j];
        }
    }

    // Правая часть
    for (int j = n + apl; j < n + 2 * apl; j++) {
        for (int i = 0; i < n + 2 * apl; i++) {
            if (a[i][j] != 0 && a[i][j - n] == 0)
                a[i][j - n] = a[i][j];
        }
    }

    return a;
}

void swap_elements(int* number_1, int* number_2) {
    int temp = *number_1;
    *number_1 = *number_2;
    *number_2 = temp;
}

int main() {
    int n, apl;
    scanf("%d", &n);

    if (n == 2) {
        printf("NO\n");
        return 0;
    }

    if (n % 2 != 0) { // Нечетные
        apl = n / 2;
        int** a = magic_3(n);
        for (int i = apl; i < n + apl; i++) {
            for (int j = apl; j < n + apl; j++) {
                printf("%d ", a[i][j]);
                if (j == n + apl - 1)
                    printf("\n");
            }
        }
        for (int i = 0; i < n + 2 * apl; i++)
            free(a[i]);
        free(a);
    }

    if (n % 4 == 0) { // Кратные 4
        apl = n / 4;
        int** a = (int**)calloc(n + 2 * apl, sizeof(int*));
        for (int i = 0; i < n + 2 * apl; i++)
            a[i] = (int*)calloc(n + 2 * apl, sizeof(int));

        int u = 1;
        for (int i = apl; i < n + apl; i++) {
            for (int j = apl; j < n + apl; j++) {
                a[i][j] = u;
                u++;
            }
        }

        for (int i = apl; i < n + apl; i++) {
            for (int j = apl; j < n + apl; j++) {
                printf("%d ", a[i][j]);
                if (j == n + apl - 1)
                    printf("\n");
            }
        }

        for (int i = 0; i < n + 2 * apl; i++)
            free(a[i]);
        free(a);
    }

    if (n % 4 == 2) { // Кратные 4 плюс 2
        int** a1 = magic_3(n / 2);
        int** a2 = magic_3(n / 2);
        int** a3 = magic_3(n / 2);
        int** a4 = magic_3(n / 2);

        int** a = (int**)calloc(n, sizeof(int*));
        for (int i = 0; i < n; i++)
            a[i] = (int*)calloc(n, sizeof(int));

        apl = n / 4;
        for (int i = apl; i < n / 2 + apl; ++i) {
            for (int j = apl; j < n / 2 + apl; ++j)
                a[i - apl][j - apl] = a1[i][j];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }

        for (int i = 0; i < n; i++)
            free(a[i]);
        free(a);
    }

    return 0;
}