#include <iostream>

void bubbleSort(int* arr, int size) {
    bool swapped;

    for(int i = 0; i < size - 1; i++) {
        swapped = false;

        for(int j = 0; j < (size - i - 1); j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop, then the array is sorted
        if(!swapped) break;
    }
}

int main () {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);

    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}