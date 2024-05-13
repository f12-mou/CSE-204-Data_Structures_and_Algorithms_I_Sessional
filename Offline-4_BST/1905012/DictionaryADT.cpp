#include<iostream>
using namespace std;

// The Dictionary Abstract Class
template<typename Key, typename E>
class Dictionary
{
public:
    // Default Constructor
    Dictionary()
    {

    }

    // Base Destructor
    virtual ~Dictionary()
    {

    }

    // Reinitialize the Dictionary
    virtual void clear()=0;

    // Insert a Record
    // k: The key for the record inserted
    // e: The record being inserted
    virtual void insert(Key k, E e)=0;

    // Remove and return a record
    // k: The key of the record being removed
    // Return a matching a record
    virtual int remove(Key k)=0;

    // Remove and return an arbitrary record from the dictionary
    // Return: The record being removed. Or NULL if none exists
    virtual E* removeAny()=0;

    //Return:  A record matching "k" (NULL if none exists)
    // k: The key of the record to find
    virtual void find(Key k)=0;

    // Return the number of records in the dictionary
    virtual int size()=0;
};
