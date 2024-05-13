#include<iostream>
#include "QueueADT.cpp"
using namespace std;

template<typename E>class Link
{
public:

    E element;
    Link<E>* next;
    Link()
    {
        next=NULL;
    }
    Link(E item,Link<E>* n)
    {
        element=item;
        next=n;
    }
};

template<typename E>class LQueue:public Queue<E>
{
private:
    Link<E>* front;
    Link<E>*rear;
    int size;
public:
    LQueue(int sz=100)
    {
        front=rear=new Link<E>();
        size=0;
    }
    ~LQueue()
    {
        clear();
        delete front;
    }
    void clear()
    {
        Link<E>* temp=front->next;
        while(temp!=NULL)
        {
            rear=temp;
            temp=temp->next;
            delete rear;
        }
        rear=front;
        front->next=NULL;
        size=0;
    }
    void enqueue(E& it)
    {
        rear->next=new Link<E>(it,NULL);
        rear=rear->next;
        size++;
    }
    LQueue& operator=(LQueue& Obj)
    {
        clear();
        Link<E>* temp=Obj.front->next;
        while(temp!=NULL)
        {
            E item=temp->element;
            enqueue(item);
            temp=temp->next;
        }
        rear->next=NULL;
        return *this;
    }
    LQueue(LQueue& Obj)
    {
        front=rear=new Link<E>();
        size=0;
        Link<E>* temp=Obj.front->next;
        while(temp!=NULL)
        {
            E item=temp->element;
            enqueue(item);
            temp=temp->next;
        }
        rear->next=NULL;
    }
    E dequeue()
    {
        try{
            if(length()==0)
                throw "The Queue is Empty";
            E it=front->next->element;
            Link<E>* temp=front->next;
            front->next=temp->next;
            if(rear==temp)
                rear=front;
            delete temp;
            size--;
            return it;
        } catch(const char* a)
        {
            cout<<a<<endl;
            exit(1);
        }
    }
    E frontValue()
    {
         try{
            if(length()==0)
                throw "The Queue is Empty";
            return front->next->element;
        } catch(const char* a)
        {
            cout<<a<<endl;
            exit(1);
        }
    }
    int length(){return size;}
    E rearValue()
    {   try{
        if(length()==0)
            throw "The List is Empty";
            return rear->element;
        } catch(const char* a)
        {
            cout<<a<<endl;
            exit(1);
        }
    }
    E leaveQueue()
    {
        try{
        if(length()==0)
            throw "The List is Empty";
        Link<E>* temp=front;
        while(temp->next!=rear)
        {
            temp=temp->next;
        }
        E item=rear->element;
        size--;
        delete rear;
        rear=temp;
        rear->next=NULL;
        return item;
        } catch(const char* a)
        {
            cout<<a<<endl;
            exit(1);
        }
    }

};


