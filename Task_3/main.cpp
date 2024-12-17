#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Введите размер матрицы (N): ";
    cin >> N;

    double** matrix = new double*[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new double[N];
    }

    cout << "Введите элементы матрицы (строка за строкой):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "Исходная матрица:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    double maxElement = matrix[0][0];
    double minElement = matrix[0][0];
    int maxRow = 0, minRow = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
                maxRow = i;
            }
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
                minRow = i;
            }
        }
    }

    if (maxRow == minRow) {
        cout << "Максимальный и минимальный элементы находятся в одной строке: " << maxRow + 1 << endl;
    } else {

        double* temp = matrix[maxRow];
        matrix[maxRow] = matrix[minRow];
        matrix[minRow] = temp;

        cout << "Матрица после перестановки строк:" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}