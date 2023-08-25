#ifndef STACK_H_
#define STACK_H_

namespace stack {
    template <typename T>
    class Stack {
        public:
            T top();
            T pop();
            bool isEmpty();
            Stack &push(T const &x);
            int size();
        private:
            T* arr = nullptr;
            int length = 0;
    };
}

#endif