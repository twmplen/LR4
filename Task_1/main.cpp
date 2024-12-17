#include <iostream>
using namespace std;

void transformArray(int arr[], int n) {
    int i = 0, j = n - 1;

    int result[n];
    int index = 0;

    for (int k = 0; k < n; ++k) {
        if (arr[k] < 0) {
            result[index++] = arr[k];
        }
    }

    for (int k = 0; k < n; ++k) {
        if (arr[k] >= 0) {
            result[index++] = arr[k];  
        }
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = result[i];
    }
}

int main() {
    int k;

    cout << "Введите количество элементов в массиве: ";
    cin >> k;

    int arr[k];

    cout << "Введите элементы массива: ";
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }
    cout << "Исходный массив: ";
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    transformArray(arr, k);

    cout << "Преобразованный массив: ";
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}