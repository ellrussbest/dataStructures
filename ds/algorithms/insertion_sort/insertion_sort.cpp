#include <iostream>

// insertion sort
void insertion_sort(int* arr, int size) {
    int key;

    for(int i = 1; i < size; i++) {
        key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main () {
    int arr[5] = {12, 11, 13, 5, 6};
    insertion_sort(arr, 5);

    for(auto i: arr) {
        std::cout << i << " ";
    }
}