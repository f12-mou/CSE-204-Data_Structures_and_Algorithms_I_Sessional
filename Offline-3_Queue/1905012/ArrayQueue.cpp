#include<iostream>
#include<cstdlib>
#include "QueueADT.cpp"
using namespace std;

//Array Based queue implementation
template<typename E>class AQueue:public Queue<E>
{
private:
    int maxsize;        //Max size of the queue
    int front;          //Index of front element
    int rear;           //Index of rear element
    E* listArray;       //Array holding queue elements

    void reAllocate()    //Reallocating and initializing memory when exhausted
    {
        E* temp;
        int len=length();
        temp=new E[maxsize];
        int ii=0;
        while(length()!=0)
        {
            E item=dequeue();
            temp[ii++]=item;
        }
        listArray=new E[(maxsize)*2];
        front=1;
        rear=0;
        ii=0;
        while(length()!=len)
        {
            E item=temp[ii];
            enqueue(item);
            ii++;
        }
         maxsize=(maxsize)*2;
         delete temp;
    }
public:
    AQueue(int size=100)        //Constructor
    {
        maxsize=size+1;
        front=1;
        rear=0;
        listArray=new E[maxsize];
    }
    AQueue(E* arr,int y)
    {
        maxsize=y+1;
        front=1;
        rear=0;
        listArray=new E[maxsize];
        for(int i=0;i<y;i++)
        {
            enqueue(*arr);
            arr++;
        }
    }
    ~AQueue()                   //Destructor
    {
        delete[] listArray;
    }
    void clear()                //Initializing the queue
    {
        rear=0;
        front=1;
    }
    void enqueue(E& item)       //Inserting an element at the rear index
    {
        if((rear+2)%maxsize ==front)
        {
            reAllocate();
        }
        rear=(rear+1)%maxsize;
        listArray[rear]=item;
    }
    E dequeue()
    {
        try{
            if(length()==0)
                throw "The Queue is Empty";
            E item=listArray[front];
            front=(front+1)%maxsize;
            return item;
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
            E it=listArray[front];
            return it;
        } catch(const char* a)
        {
            cout<<a<<endl;
            exit(1);
        }
    }
    int length()
    {
        return ((rear+maxsize)-front+1)%maxsize;
    }
    E rearValue()
    {
        try{
            if(length()==0)
                throw "The Queue is Empty";
        E it=listArray[rear];
        return it;
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
            throw "The Queue has no element";
        E it=listArray[rear];
        rear=((rear+maxsize)-1)%maxsize;
        return it;
        } catch(const char* a)
        {
            cout<<a<<endl;
            exit(1);
        }
    }
    AQueue& operator=(AQueue& Obj) //Assignment Protection
    {
        delete[] listArray;
        maxsize=Obj.maxsize;
        listArray=new E[maxsize];
        rear=0;front=1;
        int len=Obj.length();
        AQueue<E>temp(len);
        while(len!=0)
        {
            E item=Obj.dequeue();
            enqueue(item);
            temp.enqueue(item);
            len--;
        }
        len=temp.length();
        while(len!=0)
        {
            E item=temp.dequeue();
            Obj.enqueue(item);
            len--;
        }
        return *this;
    }
    AQueue(AQueue& Obj)  //Copy Constructor Protection
    {
        maxsize=Obj.maxsize;
        listArray=new E[maxsize];
        rear=0;front=1;
        int len=Obj.length();
        AQueue<E>temp(len);
        while(len!=0)
        {
            E item=Obj.dequeue();
            enqueue(item);
            temp.enqueue(item);
            len--;
        }
        len=temp.length();
        while(len!=0)
        {
            E item=temp.dequeue();
            Obj.enqueue(item);
            len--;
        }
    }
};
