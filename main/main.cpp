#include <iostream>
#include <ctime>

using namespace std;

template<typename T>
void showArray(T** arr, size_t col, size_t* array_rows_size) {
    cout << "Array dynamic: " << endl;
    for (size_t i = 0; i < col; i++) {
        for (size_t j = 0; j < array_rows_size[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template<typename T>
T** addNewLineAtIndex(T** arr, int& col, size_t*& array_rows_size, size_t new_line_size, size_t position) {
    if (position >= 0 && position <= col) {
        size_t* new_array_rows_size = new size_t[col + 1];
        for (size_t i = 0; i < col; i++) {
            new_array_rows_size[i < position ? i : i + 1] = array_rows_size[i];
        }

        new_array_rows_size[position] = new_line_size;
        col++;
        T** new_arr = new T * [col];
        for (size_t i = 0; i < col; i++) {
            if (i < position) {
                new_arr[i] = arr[i];
            }
            else if (i > position) {
                new_arr[i] = arr[i - 1];
            }
            else {
                new_arr[i] = new T[new_line_size];
                for (size_t j = 0; j < new_line_size; j++) {
                    new_arr[i][j] = rand() % 10;
                }
            }
        }

        delete[] arr;
        delete[] array_rows_size;
        array_rows_size = new_array_rows_size;
        arr = new_arr;
        return arr;
    }
    else {
        cout << "Invalid position for adding line." << endl;
        return arr;
    }
}

int main() {
    srand(time(0));

    int rows, items;
    cout << "Rows items = ";
    cin >> rows;
    size_t* array_rows_size = new size_t[rows];
    int** arr_d = new int* [rows];
    for (int i = 0; i < rows; i++) {
        cout << "Items[" << i << "] = ";
        cin >> items;
        array_rows_size[i] = items;
        arr_d[i] = new int[items];
        for (int j = 0; j < items; j++) {
            arr_d[i][j] = rand() % 10;
        }
    }
    showArray(arr_d, rows, array_rows_size);
    cout << endl << endl;

    size_t new_size, position;
    cout << "Enter size of new line: ";
    cin >> new_size;
    cout << "Enter position to add line: ";
    cin >> position;

    arr_d = addNewLineAtIndex<int>(arr_d, rows, array_rows_size, new_size, position);
    showArray(arr_d, rows, array_rows_size);

    return 0;
}
