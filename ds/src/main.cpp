#include "stack.hpp"
// #include "../stack/stack.cpp"

#include <iostream>

int main()
{
    stack::Stack<int> stack;

    stack.push(1).push(2).push(3).push(4).push(5);

    std::cout << stack.top() << " ";
    std::cout << stack.pop() << " ";
    std::cout << stack.pop() << " ";
    std::cout << stack.top() << " ";
    std::cout << stack.top() << " ";
    std::cout << stack.size() << " ";
    return 0;
}