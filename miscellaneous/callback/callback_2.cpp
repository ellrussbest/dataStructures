#include <iostream>
#include <cstdlib>
using namespace std;

// define the function pointer type
typedef void (*callbackType)(int);

void callback(int x) {
    cout << x;
}

void useCallback(callbackType callback) {
    callback(rand() % 10);
}

int main() {
    useCallback(callback);
    return 0;
}
