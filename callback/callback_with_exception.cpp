#include <iostream>
#include <stdexcept>

using namespace std;

// Define a callback function that takes an integer argument and prints a message to the console
void callback(int x) {
    cout << "I am a callback " << x << endl;
}

// Define a function that takes an integer argument and a function pointer as arguments,
// and calls the function pointer with the integer argument
void useCallback(int x, void (*callback)(int)) {
    try {
        if (callback == nullptr) {
            throw invalid_argument("Error: callback function pointer is null");
        } else {
            callback(x);
        }
    } catch (invalid_argument& e) {
        // Prints the thrown Error to the console
        cout << e.what() << endl;
    }
}

int main() {
    // Call the useCallback function with an integer argument and the callback function pointer
    useCallback(10, callback);
    
    return 0;
}
