#include<iostream>
using namespace std;

//Stack Abstract class
template <typename E> class Stack {
private:
    void operator =(const Stack&) {} // Protect assignment
    Stack(const Stack&) {} // Protect copy constructor
public:
    Stack() {} // Default constructor
    virtual ~Stack(){}
    // Reinitialize the stack. The user is responsible for
    // reclaiming the storage used by the stack elements.~
    virtual void clear() = 0;
    // Push an element onto the top of the stack.
    // it: The element being pushed onto the stack.
    virtual void push(E& it) = 0;
    // Remove the element at the top of the stack.
    // Return: The element at the top of the stack.
    virtual E pop() = 0;
    // Return: A copy of the top element.
    virtual E topValue() = 0;
    // Return: The number of elements in the stack.
    virtual int length() = 0;
    virtual void setDirection(int a)=0;
};
