#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <stdexcept>

namespace queue
{

    template <typename T>
    struct Node
    {
        T data;
        Node *next = nullptr;
        Node(T data)
        {
            this->data = data;
        }
    };

    template <typename T>
    class Queue
    {
    public:
        ~Queue();
        int size();
        Queue &push(T const &x);
        T front();
        T pop();
        bool isEmpty();

    private:
        int length = 0;
        Node<T> *head = nullptr;
        Node<T> *tail = nullptr;
    };

    template <typename T>
    Queue<T>::~Queue()
    {
        Node<T> *temp = nullptr;
        while (this->head != nullptr)
        {
            temp = this->head->next;
            delete this->head;
            this->head = temp;
        }
    }

    template <typename T>
    bool Queue<T>::isEmpty()
    {
        return this->head == nullptr;
    }

    template <typename T>
    int Queue<T>::size()
    {
        return this->length;
    }

    template <typename T>
    Queue<T> &Queue<T>::push(T const &x)
    {
        Node<T> *newNode = new Node<T>(x);

        if (this->isEmpty())
        {
            this->head = newNode;
            this->tail = newNode;
        }
        else
        {
            this->tail->next = newNode;
            this->tail = newNode;
        }
        this->length++;
        return *this;
    }

    template <typename T>
    T Queue<T>::front()
    {

        if (this->isEmpty())
            throw std::out_of_range("Queue is empty");
        return this->head->data;
    }

    template <typename T>
    T Queue<T>::pop()
    {
        T data = this->head->data;
        Node<T> *temp = this->head;
        this->head = temp->next;
        delete temp;
        temp = nullptr;
        this->length--;

        return data;
    }
} // namespace queue

#endif