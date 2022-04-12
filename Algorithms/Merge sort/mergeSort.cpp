#include <iostream>
using namespace std;

//merge the two halves into a sorted array
void Merge(int *a, int from, int to, int mid){
    int i = from;
    int j = mid+1;
    int k = 0;

    int temp[to-from+1];

    //merge the two parts into temp[]
    while(i <= mid && j <= to){
        if(a[i] < a[j]){
            temp[k] = a[i];
            k++; i++;
        }else{
            temp[k] = a[j];
            k++; j++;
        }
    }

    //insert all the reaminging values from i to mid into temp[]
    while (i <= mid){
        temp[k] = a[i];
        k++; i++;
    }

    //insert all the remaining values from j to to into temp[]
    while (j <= to){
        temp[k] = a[j];
        k++; j++;
    }

    //assign sorted data sorted in temp[] to a[]
    for (i = from; i <= to; i++){
        a[i] = temp[i-from];
    }
}

void mergeSort(int *a, int from, int to){
    int mid;
    if(from < to){
        mid = (from+to)/2;

        mergeSort(a, from, mid); //O(n/2)
        mergeSort(a, mid+1, to); //O(n/2)

        Merge(a, from, to, mid); //O(n)
    }
}

int main(){
    int n = 10; // number of elements
    int arr[10] = {10,54, 63, 6, 420, 11, 41, 32, 17, 22}; 

    mergeSort(arr, 0, n-1);

    //print the array
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
