#include <iostream>

using namespace std;

int** allocateMatrix(int rows, int cols) {
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void deallocateMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void inputMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Введіть елемент матриці [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    cout << "Матриця:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void processMatrix(int** matrix, int rows, int cols) {
    int rowsWithNegativeAndZero = 0;
    int sumAfterFirstPositive = 0;

    for (int i = 0; i < rows; ++i) {
        bool hasZero = false;
        bool hasNegative = false;

        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                hasZero = true;
            }
            else if (matrix[i][j] < 0) {
                hasNegative = true;
            }

            if (hasZero && hasNegative) {
                ++rowsWithNegativeAndZero;
                break;
            }

            if (matrix[i][j] > 0 && !hasZero) {
                sumAfterFirstPositive += matrix[i][j];
            }
        }
    }

    cout << "Кількість рядків з хоча б одним нульовим елементом: " << rowsWithNegativeAndZero << endl;
    cout << "Сума елементів після першого додатного елемента в кожному рядку: " << sumAfterFirstPositive << endl;
}

int main() {
    int rows, cols;

    cout << "Введіть кількість рядків: ";
    cin >> rows;
    cout << "Введіть кількість стовпців: ";
    cin >> cols;

    int** matrix = allocateMatrix(rows, cols);

    // Введення матриці
    inputMatrix(matrix, rows, cols);

    // Виведення матриці
    printMatrix(matrix, rows, cols);

    // Обробка матриці
    processMatrix(matrix, rows, cols);

    // Звільнення пам'яті
    deallocateMatrix(matrix, rows);

    return 0;
}
