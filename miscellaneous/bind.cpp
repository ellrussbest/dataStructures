#include <functional>
#include <iostream>
#include <boost/bind.hpp>

int subtract(int x, int y) {
    return x - y;
}

class MyClass {
public:
    MyClass() : boundMethod(std::bind(&MyClass::printMessage, this, "Hello, world!")) {}

    void printMessage(const std::string& message) {
        std::cout << message << std::endl;
    }

    std::function<void()> boundMethod;
};



int main () {
    auto x_minus_five = std::bind2nd(std::ptr_fun(subtract), 5);
    auto x_minus_five_with_placeholder = std::bind(std::ptr_fun(subtract), std::placeholders::_1, 5);
    auto x_minus_five_with_boost = boost::bind(subtract, boost::placeholders::_1, 5);
    auto five_minus_x = std::bind1st(std::ptr_fun(subtract), 5);
    
    std::cout << x_minus_five(20) << "\n"; // 15
    std::cout << x_minus_five_with_placeholder(20) << "\n"; // 15
    std::cout << x_minus_five_with_boost(20) << "\n"; // 15
    std::cout << five_minus_x(20) << "\n"; // -15

    // you must pass the object you're referring to in both cases... i.e. this and myObject
    // initialized through constructor initialization
    MyClass myObject;
    myObject.boundMethod();

    // created through an object
    auto boundMethod = std::bind(&MyClass::printMessage, &myObject, "Hello, world!");
    boundMethod();
    
    return 0;
}
