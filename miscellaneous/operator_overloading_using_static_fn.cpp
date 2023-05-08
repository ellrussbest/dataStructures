#include <iostream>
using namespace std;

class Person {
  private:
    int age;

  public:
    Person(int a) {
      age = a;
    }

    int getAge() const {
      return age;
    }
    
    // normal operator overloading
    // not a static function
    
    /**
    *We return *this because we want to make sure that the current object gets updated with the values of the object 
    *that we're assigning to it. 
    *By returning *this, we're returning a reference to the current object, 
    *which allows us to chain multiple assignments together.
    **/
    Person& operator=(const Person &a) {
      this->age = a.age;
      return *this;
    }
    
    // anytime you have to use a this operator you cannot use a static function
    static int sumAges(const Person& p1, const Person& p2) {
      return p1.age + p2.age;
    }
    
    /**
    *Static member functions can only access static data members and other static member functions. 
    *This is because static member functions do not have access to the "this" pointer, which means they cannot access 
    *non-static data members or non-static member functions. 
    *If you're overloading an operator that requires access to non-static data members or non-static member functions, you cannot make the operator function static. 
    **/
    friend int operator+(const Person& p1, const Person& p2);
};

// We have defined our operator overloader outside of our class because
// we cannot use a static operator overloader inside of the class
// for us to use the operator overloader we are supposed to call the refer to the function as a friend as 
// shown in the above code
int operator+(const Person& p1, const Person& p2) {
  return p1.age + p2.age;
}

int main() {
  Person p1(25);
  Person p2(30);

  // Using the static function
  int sum = Person::sumAges(p1, p2);
  cout << "Sum of ages using static function: " << sum << endl;

  // Using the overloaded operator
  sum = p1 + p2;
  cout << "Sum of ages using overloaded operator: " << sum << endl;

  return 0;
}
