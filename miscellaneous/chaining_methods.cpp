#include <iostream>
using namespace std;

class Plan {
public:
    Plan& setName(string name) {
        this->name = name;
        return *this;
    }
    Plan& setDescription(string description) {
        this->description = description;
        return *this;
    }
    Plan& setType(string type) {
        this->type = type;
        return *this;
    }
    void print() {
        cout << "Name: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Type: " << type << endl;
    }
private:
    string name;
    string description;
    string type;
};

int main() {
    Plan plan;
    plan.setName("Bestflix monthly subscription")
        .setDescription("Gets you all the features of our site")
        .setType("INFINITE")
        .print();
    return 0;
}
