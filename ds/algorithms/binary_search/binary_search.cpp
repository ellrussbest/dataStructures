#include <iostream>

using namespace std;

bool binary_search(int *arr, int value, int size)
{
    int start = 0;
    int end = size - 1;
    int middle = (start + end) / 2;

    while (start <= end || end >= start)
    {
        if (arr[middle] == value)
        {
            return true;
        }
        else if (arr[middle] < value)
        {
            middle = (start + end) / 2;
            start = middle;
            middle = (start == middle) ? middle + 1 : middle;
            start = start + 1;
        }
        else
        {
            middle = (start + end) / 2;
            end = middle;
            middle = (end == middle) ? middle - 1 : middle;
            end = end - 1;
        }
    }

    return false;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    std::cout << binary_search(arr, 6, 5);
}