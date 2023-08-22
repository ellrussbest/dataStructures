#include <iostream>

#define ADD(x, y) (x + y)
#define MAX(x, y) ( \
    ((x) > (y)) ? (x) : (y) )
    
#define FIBO(x) \
    ({ \
        int *arr = new int[x]; \
        for(int i = 0; i < x; i++) { \
            if(i < 2) \
                arr[i] = 1; \
            else \
                arr[i] = arr[i-1] + arr[i-2]; \
        } \
        int result = arr[x-1]; \
        delete[] arr; \
        result; \
    })

#define PERSON_CLASS \
class Person { \
public: \
    Person(std::string const &name): name(name){} \
    void getName(){ \
        std::cout << this->name << std::endl; \
    } \
private: \
    std::string name; \
};

PERSON_CLASS

int main() {
    Person a("Borat");
    a.getName();
    
    std::cout << ADD(10, 20) << std::endl;
    std::cout << MAX(10, 20) << std::endl;
    std::cout << FIBO(6) << std::endl;
    return 0;
}
