// QueueADT.cpp

In this file, an abstract class of queue was defined which was further implemented by array based and linked list
based implementation. Our ADT includes pure virtual functions - clear(), enqueue(), dequeue(), frontValue(),
length(), frontValue(), rearValue().

// ArrayQueue.cpp

In this file, array based implementation is defined. An array is holding all the elements of the queue in a cyclic
direction so that maximum storage efficiency can be reached. An additional blank space is there for the sake of
simplicity of differing between full array and empty array.

// LinkedListQueue.cpp

In this file, linked list implementation is defined. A simple Link class is defined for storing the data and
the next field's pointer. This one was quite like List data structures.

// BankQueue.cpp

So this one was the most interesting. An actual simulation of queue in bank has been implemented in the file
using the ArrayQueue file's AQueue data structure. The commented lines are in order for better understanding.

// Main.cpp files

Two files named LinkedQueueMain.cpp and ArrQueueMain.cpp are written for demonstrating the functionality of the
implementation of our ADT.