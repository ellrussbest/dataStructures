#include <iostream>
#include <vector>

std::vector<int> countSort(std::vector<int> &inputArray) {
    int size = (int)inputArray.size();

    // Finding the maximum element of array inputArray[].
    int maximum = 0;

    for(int i = 0; i < size; i++) {
        maximum = std::max(maximum, inputArray[i]);
    }

    // Initializing countArray[] with 0
    std::vector<int> countArray(maximum + 1, 0);

    // Mapping each element of inputArray[] as an index of CountArray[] array
    for(int i = 0; i < size; i++) {
        countArray[inputArray[i]]++;
    }

    // Calculating prefix sum at every index of array countArray[]
    for(int i = 1; i <= maximum; i++) {
        countArray[i] += countArray[i - 1];
    }

    // Creating outputArray[] from countArray[] array
    std::vector<int> outputArray(size);

    for(int i = size - 1; i >= 0; i--) {
        outputArray[countArray[inputArray[i]] - 1] = inputArray[i];
        countArray[inputArray[i]]--;
    }

    return outputArray;
}


int main() {
    // Input array
    std::vector<int> inputArray = { 4, 3, 12, 1, 5, 5, 3, 9 };

    // Output array
    std::vector<int> outputArray = countSort(inputArray);

    for(int i = 0; i < inputArray.size(); i++) {
        std::cout << outputArray[i] << "\t";
    }

    return 0;
}