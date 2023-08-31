#include "stack.hpp"
#include "queue.hpp"

#include <iostream>
#include <stdexcept>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

class Person
{
public:
    std::string name = "";
    ~Person() {}
};

int main()
{

    // Enable memory leak detection
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // Data structures
    stack::Stack<Person> stack;
    queue::Queue<Person> queue;

    // Objects
    Person a, b, c, d, e;
    a.name = "russell";
    b.name = "odhiambo";
    c.name = "best";
    d.name = "abijos";
    e.name = "ochuonyo";

    // test stack
    stack.push(a).push(b).push(c).push(d).push(e);

    std::cout << stack.top().name << " ";
    std::cout << stack.pop().name << " ";
    std::cout << stack.pop().name << " ";
    std::cout << stack.top().name << " ";
    std::cout << stack.top().name << " ";
    std::cout << stack.size() << " ";
    std::cout << "\n";

    // test queue
    try
    {
        std::cout << queue.front().name << "\n";
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    queue.push(a).push(b).push(c).push(d).push(e);

    std::cout << queue.front().name << " ";
    std::cout << queue.pop().name << " ";
    std::cout << queue.pop().name << " ";
    std::cout << queue.front().name << " ";
    std::cout << queue.front().name << " ";
    std::cout << queue.size() << " ";
    std::cout << "\n";

    _CrtDumpMemoryLeaks();

    return 0;
}