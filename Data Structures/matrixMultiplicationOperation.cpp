/*
number of row in matrix A === number of columns in matrix B
*/

#include <iostream>

using namespace std;
int rows_first, cols_first, rows_second, cols_second;

int* insertMatrix(int* matrix, int row, int col) {
    int value;
   for (int i = 0; i < row; i++) {
    cout << "Please enter values of row " << i + 1<< endl;
    for (int j = 0; j < col; j++) {
        cin >> value;
        *(matrix + row * i + j) = value;
    }
   }

   return matrix;
}

void displayMatrix(int* matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << *(matrix + row*i + j) << " ";
        }
        cout << endl;
    }
}

void displayBothMatrices(int* first_matrix, int* second_matrix) {
    cout << "The first Matrix is: " << endl;
    displayMatrix(first_matrix, rows_first, cols_first);
    cout << endl;

    cout << "The second Matrix is: " << endl;
    displayMatrix(second_matrix, rows_second, cols_second);
    cout << endl;
}

void productOfMatrix(int* first_matrix, int* second_matrix) {
   // int *matrixProduct = new int[rows_first * cols_second];

    // outer iteration will be iterating through the
    // the first matrix
    for(int i = 0; i < rows_first; i++) {
        // inner iteration will be iterating through
        // the column of second matrix
        for(int j = 0; j < cols_second; j++) {
            int sum = 0;
            // an iteration to add the matrix operation
            // iteration upto no of columns in first matrix
            for(int k = 0; k < cols_first; k++) {
                // sum = sum + first_matrix[i][k] * second_matrix[k][j];
                 sum = sum + *(first_matrix + rows_first * i + k) * *(second_matrix + rows_second * k + j);
            }
            cout << sum << " ";
        }
        cout << endl;
    }
}


int main() {

    cout << "Enter the number of rows for the first matrix: ";
    cin >> rows_first;
    cout << endl;
    cout << "Enter the number of columns for the first matrix: ";
    cin >> cols_first;
    cout << endl;

    cout << "Enter the number of rows for the second matrix: ";
    cin >> rows_second;
    cout << endl;
    cout << "Enter the number of columns for the second matrix: ";
    cin >> cols_second;
    cout << endl;

    int* first_matrix = new int[rows_first * cols_first];
    int* second_matrix = new int[rows_second * cols_second];

    cout << "Please Enter the values of the first Matrix " << endl;
    first_matrix = insertMatrix(first_matrix, rows_first, cols_first);

    cout << "Please Enter the values of the second Matrix " << endl;
    second_matrix = insertMatrix(second_matrix, rows_second, cols_second);

    cout << endl;

    // This is used to display the values of both matrices
    displayBothMatrices(first_matrix, second_matrix);

    if (rows_first != cols_second) {
        cout << "Matrix operations cannot be performed on the following matrix set please try again!";
        return 0;
    }

    cout << "The product of the two matrix is: \n";
    productOfMatrix(first_matrix, second_matrix);


}

