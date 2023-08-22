#include <iostream>
#include <functional>

/*

[capture clause] (parameters) -> return-type {
    // function body
}

*/

// you can use lambda when we have a function pointer and you want to define
// it anonymously later.
/**/
std::function<void (std::string const &str)> funcPtr = nullptr;

    

int main () {
    int a = 10, b = 20;
    
    // the variable in the main function are READONLY
    auto sum = [=](int x, int y) -> int {
        std::cout << a << std::endl;
        return x + y;
    };
    std::cout << sum(10, 20) << std::endl;
    
    // the variable in the main function can be edited
    auto sub = [&](int x, int y) -> int {
        a = a + 1;
        return x + y;
    };
    std::cout << sub(20, 10) << std::endl;
    std::cout << a << std::endl;
    
    // passing the local main variable to the lambda
    auto sumWithB = [b](int x) -> int {
        return b + x;
    };
    std::cout << sumWithB(10) << std::endl;
    
    
    // LAMBDA INITIALIZED LATER...
    funcPtr = [](std::string const &str) {
        std::cout << str << std::endl;
    };
    funcPtr("Hello World");
    return 0;
}
