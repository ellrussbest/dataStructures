#include <memory>

template <typename T>
class MyTemplateClass {
public:
    using ConstPtr = std::shared_ptr<const MyTemplateClass<T>>;

    MyTemplateClass(const T& value) : m_value(value) {}

    const T& getValue() const { return m_value; }

private:
    T m_value;
};

int main() {
    auto myObject = std::make_shared<MyTemplateClass<int>>(42);
    MyTemplateClass<int>::ConstPtr myConstObject = myObject;
    return 0;
}

/**
Smart pointers are a type of C++ pointer that help you manage memory in a safer and more efficient way. 
In general, C++ pointers are used to store the memory addresses of objects. When you create a pointer, 
you can use it to access the object that it points to. However, you need to be careful when using pointers, 
since they can be dangerous if you don't manage them correctly. For example, if you delete an object that a 
pointer points to, but then try to access that object through the pointer, you will get undefined behavior.

Smart pointers are a type of C++ pointer that help you avoid these types of errors. 
There are several different types of smart pointers, but two of the most common types are `unique_ptr` and `shared_ptr`.

A `unique_ptr` is a pointer that manages ownership of an object. When you create a `unique_ptr`, 
it takes ownership of the object that it points to. This means that when the `unique_ptr` goes out of scope or is deleted, 
it automatically deletes the object that it points to. You can also transfer ownership of a `unique_ptr` from one object to another using `std::move`.

Here's an example of how to use a `unique_ptr`:

```c++
#include <memory>

int main() {
    std::unique_ptr<int> myPtr(new int(42));
    // do something with myPtr
    return 0;
}
```

In this example, we create a `unique_ptr` to an `int` object with the value `42`. When the `unique_ptr` goes out of scope at the end of the `main` function, it automatically deletes the `int` object.

A `shared_ptr` is a pointer that allows multiple objects to share ownership of an object. When you create a `shared_ptr`, 
it creates a reference count that is set to 1. Every time you create a new `shared_ptr` that points to the same object, 
the reference count is incremented. When a `shared_ptr` goes out of scope or is reset, the reference count is decremented. When the reference count reaches zero, the object is automatically deleted.

Here's an example of how to use a `shared_ptr`:

```c++
#include <memory>

int main() {
    std::shared_ptr<int> myPtr1(new int(42));
    std::shared_ptr<int> myPtr2 = myPtr1;
    // do something with myPtr1 and myPtr2


A shared pointer is a smart pointer that manages the lifetime of an object through reference counting. 
When you create a shared pointer, it creates a reference count that is set to 1. Every time you create a 
new shared pointer that points to the same object, the reference count is incremented. When a shared pointer goes out of scope or is reset, 
the reference count is decremented. When the reference count reaches zero, the object is automatically deleted.
The benefit of using shared pointers is that they allow multiple objects to share ownership of a single object. 
This can be useful in situations where you need to pass objects between functions or manage the lifetime of objects in a complex class hierarchy.
Another benefit of shared pointers is that they provide a safe way to manage memory. 
Since the shared pointer automatically deletes the object when the reference count reaches zero, you don't need to worry about deleting the object manually or accidentally deleting it multiple times.
Overall, shared pointers are a powerful tool for managing the lifetime of objects in C++, and they can help you write safer and more maintainable code.
**/
