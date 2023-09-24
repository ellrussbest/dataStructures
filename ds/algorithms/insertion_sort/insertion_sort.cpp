#include <iostream>

// insertion sort
void insertion_sort(int* arr, int size) {
    int i, j, key;

    for(j = 1; j < size; j++) {
        key = arr[j];
        i = j - 1;

        while (i >= 0 && arr[i] > key)
        {
            arr[i+1] = arr[i];
            i = i - 1;
        }
        arr[i+1] = key;
    }
}

int main () {
    int arr[] = { 12, 11, 13, 5, 6 };
    int size = sizeof arr / sizeof arr[0];

    insertion_sort(arr, size);

    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}