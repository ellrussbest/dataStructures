#include <iostream>

using namespace std;

int& func(int& x) {
    x++;
    return x;
}

int main() {
    int num = 5;
    int& numRef = func(num);
    cout << numRef << endl; // Output: 6
    cout << num << endl; // Output: 6
}

/**
The above example is an example of pass by reference. 

When we pass a reference to an object as a function parameter, we are passing the object itself rather than a copy of the object. 
This means that any changes made to the object inside the function will also affect the original object outside the function.

In contrast, pass by value involves passing a copy of the object as a function parameter. 
This means that any changes made to the object inside the function will not affect the original object outside the function.

In the example I showed you, the function `func` takes a reference to an integer `x`. 
This means that any changes made to `x` inside the function will affect the original integer `num` outside the function.

**/
