#include <iostream>
using namespace std;
int rows, cols;

void transpose(int *arr) {
    int _rows = cols;
    int _cols = rows;

    int *_arr = new int[_rows * _cols];

    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            *(_arr + _cols*i + j) = *(arr + cols*j + i);
        }
    }
    cout << "The transpose for the following matrix: " << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << *(arr + cols*i + j) << " ";
        }
        cout << endl;
    }
    cout << "_______is_______" << endl;

    for(int i = 0; i < _rows; i++) {
        for(int j = 0; j < _cols; j++) {
            cout << *(_arr + _cols*i + j) << " ";
        }
        cout << endl;
    }

    delete _arr;
    _arr = nullptr;
}

int main () {
    cout << "Please enter the number of rows your matrix will have: ";
    cin >> rows;
    cout << "\n";
    cout << "Please enter the number of columns your matrix will have: ";
    cin >> cols;
    cout << "\n";

    int *arr = new int[rows * cols];

    for (int i = 0; i < rows; i++) {
        int value;
        cout << "Enter the values at row " << i+1 << endl;
        for (int j = 0; j < cols; j++) {
            cin >> value;
            *(arr + cols*i + j) = value;
        }
    }

    transpose(arr);
    delete arr;
    arr = nullptr;

    return 0;
}
