#include <iostream>

using namespace std;

template<typename T>
void cyclicShiftRows(T** matrix, int numRows, int numCols, int k, int direction) {
    k %= numCols; 

    for (int i = 0; i < numRows; ++i) {
        T* tempRow = new T[numCols]; 

        for (int j = 0; j < numCols; ++j) {
            int newPos = (j + direction * k + numCols) % numCols; /
            tempRow[newPos] = matrix[i][j]; 
        }

        for (int j = 0; j < numCols; ++j) {
            matrix[i][j] = tempRow[j]; 
        }

        delete[] tempRow; 
    }
}

int main() {
    int numRows, numCols, shiftAmount, direction;

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

    cout << "Enter the number of positions to shift: ";
    cin >> shiftAmount;

    cout << "Enter the direction of shift (1 for right, -1 for left): ";
    cin >> direction;

    cyclicShiftRows(array, numRows, numCols, shiftAmount, direction);

    cout << "Matrix after cyclically shifting rows:\n";
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

  
    for (int i = 0; i < numRows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}