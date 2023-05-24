#include <iostream>

using namespace std;

class Person{
    public:
        Person(string name): 
        name(name)
        {};
        
        virtual Person& setSex() = 0;
        string getSex() {
            return this->sex;
        }
        string getName() {
            return this->name;
        }
    
    protected:
        string sex;
    private:
        string name;
};

class Male: public Person {
    public:
        Male(string name): Person(name){}
        
        virtual Person& setSex() override {
            this->sex = "male";
            return *this;
        }
};

class Female: public Person {
    public:
        Female(string name): Person(name){}
        
        virtual Person& setSex() override {
            this->sex = "female";
            return *this;
        }
};

int main() {
    Person *russell = new Male("Russell");
    Person *michelle = new Female("Michelle");
    
    cout << russell->setSex().getSex();
    cout << "\n";
    cout << michelle->setSex().getSex();
    return 0;
}
