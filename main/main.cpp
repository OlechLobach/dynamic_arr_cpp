#include <iostream>

using namespace std;

template<typename T>
void deleteColumn(T**& matrix, int numRows, int& numCols, int colPos) {
    T** tempMatrix = new T * [numRows];
    for (int i = 0; i < numRows; ++i) {
        tempMatrix[i] = new T[numCols - 1];
        int k = 0;
        for (int j = 0; j < numCols; ++j) {
            if (j != colPos) {
                tempMatrix[i][k++] = matrix[i][j];
            }
        }
    }

    cout << "Matrix after deleting column:\n";
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols - 1; ++j) {
            cout << tempMatrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < numRows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    matrix = tempMatrix;
    numCols--;
}

int main() {
    int numRows, numCols, colPos;

    cout << "Enter the number of rows: ";
    cin >> numRows;

    cout << "Enter the number of columns: ";
    cin >> numCols;

    int** array = new int* [numRows];
    for (int i = 0; i < numRows; ++i) {
        array[i] = new int[numCols];
        for (int j = 0; j < numCols; ++j) {
            array[i][j] = i * numCols + j + 1;
        }
    }

    cout << "Original matrix:\n";
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Enter the position to delete a column: ";
    cin >> colPos;

    deleteColumn(array, numRows, numCols, colPos);

    return 0;
}
