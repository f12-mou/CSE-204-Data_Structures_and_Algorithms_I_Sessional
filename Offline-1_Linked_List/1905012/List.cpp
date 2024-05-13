#include<iostream>
using namespace std;

template<typename E>class List{
private:
    //void operator=(const List&){}//protect assignment
    //List(const List&){}//Protect copy constructor
public:
    List(){}//Default constructor
    virtual ~List(){}//Destructor

    //Clear contents from the list so that it is empty
    virtual void clear()=0;

    virtual void insert(const E& item)=0;//inserting element at the current position

    virtual void append(const E& item)=0;//inserting element at the last

    virtual void moveToStart() = 0;//set the current position at the start of the list

    virtual void moveToEnd() = 0; // Set the current position to the end of the list

    // Move the current position one step left. No change
    // if already at beginning.
    virtual void prev() = 0;
    // Move the current position one step right. No change
    // if already at end.
    virtual void next() = 0;//here end defines the position after the last element
    // Return: The number of elements in the list.
    virtual int length() = 0;
    // Return: The position of the current element.
    virtual int currPos()  = 0;

    //move the current position according to the specified parameter
    virtual void moveToPos(int pos)=0;
    // Return: The current element.
    virtual const E& getValue() = 0;
    virtual E remove()=0;
    virtual int Search(E& )=0;
};
