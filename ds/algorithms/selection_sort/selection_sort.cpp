#include <iostream>

/*
* The idea behind this Algorithm is that after every inner Iteration, 
* the most mininum/maximum value will have been sorted into its position
*
*/
void selection_sort(int* arr, int size) {
    for(int i = 0; i < size - 1; i++) {
        int min = i;
        for(int j = i+1; j < size; j++) {
            if(arr[j] < arr[min]) min = j;
        }

        if(min != i) {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    int arr[8] = {2, 8, 1, 3, 6, 7, 5, 4};

    selection_sort(arr, 8);

    for(int i = 0; i < 8; i++) {
        std::cout << arr[i] << "    ";
    }
}