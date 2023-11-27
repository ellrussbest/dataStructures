#include <iostream>

void swap(int* i, int* j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

int getPartitionIndex(int *arr, int startIndex, int endIndex) {
    // Choose the pivot: In our case our pivot will always be the last index/ end index
    int pivot = arr[endIndex];

    // Index of smaller element and indicate the right position of pivot found so far
    int i = startIndex;

    for (int j = startIndex; j <= endIndex; j++)
    {
        // If current element is smaller than the pivot
        if(arr[j] < pivot) {
            swap(&arr[i], &arr[j]);

            // Increment index of smaller element
            i++;
        }
    }
    swap(&arr[i], &arr[endIndex]);
    return i;
}


void quickSort(int *arr, int startIndex, int endIndex) {
    if (startIndex < endIndex)
    {
        // partitionIndex
        int partitionIndex = getPartitionIndex(arr, startIndex, endIndex);

        // Recursion Call
        // Smaller element than pivot goes left and higher element goes right
        quickSort(arr, startIndex, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, endIndex);
    }
}

int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int size = sizeof(arr) / sizeof arr[0];

    quickSort(arr, 0, size-1);

    std::cout << "Sorted Array\n";
    for(auto i: arr) {
        std::cout << i << "\t";
    }
    return 0;
}