#include <iostream>

using namespace std;

void insertionSort(int arr[], int size){
    int i, j;
    for(i = 1; i < size; i++){
        j = i;
        while(j > 0 && arr[j-1] > arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

int main(){
    int arr[] = {5, 2, 42, 6, 1, 3, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
