#include<iostream>
using namespace std;

//Abstract Class Queue
template<typename E>class Queue
{
private:
    void operator =(const Queue&) {}    // Protect assignment
    Queue(const Queue&) {}              // Protect copy constructor
public:
    Queue(){} //Default Constructor
    virtual ~Queue(){} //Destructor

    // Reinitialize the queue. The user is responsible for
    // reclaiming the storage used by the queue elements.
    virtual void clear()=0;

    // Place an element at the rear of the queue.
    // it: The element being enqueued.
    virtual void enqueue(E& it)=0;

    // Remove and return element at the front of the queue.
    // Return: The element at the front of the queue.
    virtual E dequeue()=0;

    //Return: the front value of the queue
    virtual E frontValue()=0;

    // Return: The number of elements in the queue.
    virtual int length()=0;

    //Return: The rear Value of the queue
    virtual E rearValue()=0;

    //Return: The element at the rear which is leaving the queue
    virtual E leaveQueue()=0;
};

