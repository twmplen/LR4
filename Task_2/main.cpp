#include <iostream>
using namespace std;

int main() {
    int M, N;

    cout << "Введите количество строк (M): ";
    cin >> M;
    cout << "Введите количество столбцов (N): ";
    cin >> N;

    int matrix[M][N];
    cout << "Введите элементы массива (строка за строкой):" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Исходная матрица:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    int count = 0;
    for (int i = 1; i < M; i++) {
        for (int j = 0; j < N - i; j++) {
            if (matrix[i][j] > 0) {
                count++;
            }
        }
    }

    cout << "Количество положительных элементов ниже побочной диагонали: " << count << endl;

    return 0;
}