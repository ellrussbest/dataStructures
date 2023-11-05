#include <iostream>

void merge(int* arr, int from, int to, int mid) {
    int i = from;
    int j = mid + 1;
    int k = 0;
    int size = (to-from) + 1;

    int *temp = new int[size];

    while(i <= mid && j <= to) {
        if(arr[i] < arr[j]) {
            temp[k] = arr[i];
            k++; i++;
        }else {
            temp[k] = arr[j];
            k++; j++;
        }
    }

    while(i <= mid) {
        temp[k] = arr[i];
        k++; i++;
    }

    while(j <= to) {
        temp[k] = arr[j];
        k++; j++;
    }

    for(i = from; i <= to; i++) {
        arr[i] = temp[i-from];
    }
    delete[] temp;
}

void mergeSort(int* arr, int from, int to) {
    if(from < to) {
        int mid = (from + to) / 2;

        mergeSort(arr, from, mid);
        mergeSort(arr, mid+1, to);
        merge(arr, from, to, mid);
    }
}

int main() {
    int arr[10] = { 10, 54, 63, 6, 420, 11, 41, 32, 17, 22 };
    int size = sizeof arr / sizeof(int);

    mergeSort(arr, 0, size-1);

    for(auto num: arr) std::cout << num << " ";

    return 0;
}