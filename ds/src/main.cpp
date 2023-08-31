#include "stack.hpp"
#include "queue.hpp"

#include <iostream>

class Person {
public:
    std::string name;
};

int main()
{
    stack::Stack<Person> stack;
    queue::Queue<Person> queue;

    std::cout<< queue.front().name<< "\n";

    Person a, b, c, d, e;
    a.name = "russell"; b.name = "odhiambo"; c.name = "best"; d.name = "abijos"; e.name = "ochuonyo";

    queue.push(a);

    std::cout << queue.isEmpty() << "\n";

    stack.push(a).push(b).push(c).push(d).push(e);

    std::cout << stack.top().name << " ";
    std::cout << stack.pop().name << " ";
    std::cout << stack.pop().name << " ";
    std::cout << stack.top().name << " ";
    std::cout << stack.top().name << " ";
    std::cout << stack.size() << " ";
    return 0;
}