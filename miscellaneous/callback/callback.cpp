#include <iostream>
#include <cstdlib>
using namespace std;

void callback(int x) {
    cout << x;
}

void useCallback(void (*callback)(int)) {
    callback(rand() % 10);
}

int main() {
    useCallback(&callback);
    return 0;
}
