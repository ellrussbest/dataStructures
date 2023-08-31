#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <stdexcept>

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
        int size();

    private:
        T *arr = nullptr;
        int length = 0;
    };

    template <typename T>
    Stack<T>::~Stack()
    {
        delete[] this->arr;
        this->arr = nullptr;
    }

    template <typename T>
    T Stack<T>::top()
    {

        if (this->isEmpty())
            throw std::out_of_range("Stack is empty");
        return this->arr[this->length - 1];
    }

    template <typename T>
    T Stack<T>::pop()
    {
        if (this->isEmpty())
            throw std::out_of_range("Stack is empty");

        T popped = this->arr[this->length - 1];
        T *arr = new T[this->length - 1];

        for (int i = 0; i < this->length - 1; i++)
            arr[i] = this->arr[i];

        delete[] this->arr;
        this->arr = arr;
        this->length = this->length - 1;
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
        if (this->isEmpty())
        {
            this->length = 1;

            T *arr = new T[this->length];
            arr[0] = x;
            this->arr = arr;
        }
        else
        {
            T *arr = new T[this->length + 1];

            for (int i = 0; i < this->length + 1; i++)
            {
                if (i == this->length)
                    arr[i] = x;
                else
                    arr[i] = this->arr[i];
            }

            this->length = this->length + 1;
            delete[] this->arr;
            this->arr = arr;
        }
        return *this;
    }

    template <typename T>
    int Stack<T>::size()
    {
        return this->length;
    }
} // namespace stack

#endif