#include <iostream>

using namespace std;

void selectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++)// we need to do n - 2 passes
    {
        int iMin = i; //ith position: elements from i till n-1 are candites
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[iMin]){
                iMin = j; //update the index of minimum element
            }
        }
        int temp = arr[i];
        arr[i] = arr[iMin];
        arr[iMin] = temp;
    }
}

int main(){
    int arr[] = {2, 7, 4, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
