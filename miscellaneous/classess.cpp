/**
A virtual class is a class that has at least one virtual function, 
and it is often used as an abstract base class. A pure virtual class is a virtual class that has a pure virtual function, 
which means that it cannot be instantiated directly. A class that derives from a pure virtual class must override the pure virtual function. 
A non-pure virtual class is a virtual class that has at least one virtual function with a default implementation, 
which means that it can be instantiated directly. 
A class that derives from a non-pure virtual class can choose to use the default implementation of the virtual function or override it with its own implementation.
*/

#include <iostream>
#include <vector>

// Define a Shape base class with a virtual draw function
class Shape {
public:
  virtual void draw() = 0;
};

// Define a Circle derived class that implements draw
class Circle : public Shape {
public:
  void draw() override{
    std::cout << "Drawing a circle" << std::endl;
  }
};

// Define a Rectangle derived class that implements draw
class Rectangle : public Shape {
public:
  void draw() override{
    std::cout << "Drawing a rectangle" << std::endl;
  }
};

// Define a Triangle derived class that implements draw
class Triangle : public Shape {
public:
  void draw() override{
    std::cout << "Drawing a triangle" << std::endl;
  }
};

int main() {
  // Create a vector of Shape pointers
  std::vector<Shape*> shapes;

  // Add some shapes to the vector
  shapes.push_back(new Circle());
  shapes.push_back(new Rectangle());
  shapes.push_back(new Triangle());

  // Draw all the shapes in the vector
  for (Shape* shape : shapes) {
    shape->draw();
  }

  // Clean up the memory used by the shapes
  for (Shape* shape : shapes) {
    delete shape;
  }

  return 0;
}

/*

#include <iostream>

class Shape {
private:
    int x, y;
public:
    Shape(int x, int y) : x(x), y(y) {
        std::cout << "Shape constructor" << std::endl;
    }
    virtual ~Shape() {
        std::cout << "Shape destructor" << std::endl;
    }
    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
    virtual void draw() = 0;
};

class Circle : public Shape {
private:
    int radius;
public:
    Circle(int x, int y, int radius) : Shape(x, y), radius(radius) {
        std::cout << "Circle constructor" << std::endl;
    }
    ~Circle() override {
        std::cout << "Circle destructor" << std::endl;
    }
    void draw() override {
        std::cout << "Circle::draw() at (" << x << ", " << y << ") with radius " << radius << std::endl;
    }
};

int main() {
    Shape* s = new Circle(10, 20, 5);
    s->move(5, 10);
    s->draw();
    delete s;
    return 0;
}

*/
