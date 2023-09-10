#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <stdexcept>
#include <vector>

namespace stack
{
    template <typename T>
    class Stack
    {
    public:
        ~Stack();
        T top();
        T pop();
        bool isEmpty();
        Stack &push(T const &x);
        size_t size();

    private:
        std::vector<T> vec;
        size_t length = 0;
    };

    template <typename T>
    Stack<T>::~Stack()
    {
    }

    template <typename T>
    T Stack<T>::top()
    {

        if (this->isEmpty())
            throw std::out_of_range("Stack is empty");
        return this->vec.back();
    }

    template <typename T>
    T Stack<T>::pop()
    {
        if (this->isEmpty())
            throw std::out_of_range("Stack is empty");

        T popped = this->vec.back();
        this->vec.pop_back();
        this->length = this->vec.size();
        return popped;
    }

    template <typename T>
    bool Stack<T>::isEmpty()
    {
        return this->length == 0;
    }

    template <typename T>
    Stack<T> &Stack<T>::push(T const &x)
    {
        this->vec.push_back(x);
        this->length = this->vec.size();
        return *this;
    }

    template <typename T>
    size_t Stack<T>::size()
    {
        return this->length;
    }
} // namespace stack

#endif