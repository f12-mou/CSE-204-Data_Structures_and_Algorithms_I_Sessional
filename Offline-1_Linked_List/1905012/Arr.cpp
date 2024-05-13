#include<iostream>
#include<cstdlib>
#include "List.cpp"
using namespace std;

template<typename E>
class AList:public List<E>
{
private:
    int maxSize;
    int listSize;
    int curr;
    int currAllocatedSize;
    E* listArray;
    void reAllocate()
    {
        currAllocatedSize+=maxSize;
        E* temp=new E[currAllocatedSize];
        for(int i=0;i<listSize;i++)
        {
            temp[i]=listArray[i];
        }
        delete listArray;
        listArray=new E[currAllocatedSize];
        for(int i=0;i<listSize;i++)
            listArray[i]=temp[i];
        delete temp;
    }
public:
    AList(int size=100)
    {
        maxSize=size;
        currAllocatedSize=maxSize;
        listSize=0;
        curr=0;
        listArray=new E[maxSize];
    }
    AList(const AList& obj)
    {
        maxSize=obj.maxSize;
        currAllocatedSize=obj.currAllocatedSize;
        listSize=obj.listSize;
        curr=obj.curr;
        listArray=new E[currAllocatedSize];
        for(int i=0;i<listSize;i++)
        {
            listArray[i]=obj.listArray[i];
        }
    }
    AList& operator=(const AList& obj)
    {
        delete[] listArray;
         maxSize=obj.maxSize;
        currAllocatedSize=obj.currAllocatedSize;
        listSize=obj.listSize;
        curr=obj.curr;
        listArray=new E[currAllocatedSize];
        for(int i=0;i<listSize;i++)
        {
            listArray[i]=obj.listArray[i];
        }
    }
    AList(E* a,int Y)
    {
         maxSize=Y;
         currAllocatedSize=maxSize;
         listArray=new E[maxSize];
         for(int i=0;i<Y;i++){
            listArray[i]=*a;
            a++;
         }
         listSize=Y;
         curr=0;
    }
    ~AList()
    {
        delete[] listArray;
    }
    void insert(const E& item)
    {
        if(currAllocatedSize==listSize)
            reAllocate();
        for(int i=listSize;i>curr;i--)
            listArray[i]=listArray[i-1];
        listArray[curr]=item;
        listSize++;
    }
    void append(const E& item)
    {
        if(currAllocatedSize==listSize)
            reAllocate();
        listArray[listSize++]=item;
    }
    E remove()
    {
        try{
            if(listSize==0)
                throw "The List is Empty.";
            E it=listArray[curr];
            for(int i=curr;i<listSize-1;i++)
            {
                listArray[i]=listArray[i+1];
            }
            listSize--;
             if(curr==listSize && curr!=0)
                curr--;
            return it;
        }catch(const char* a)
        {
            //cout<<a<<endl;
            //Exception is not printed here in accordance to the Output Format.
            exit(1);
        }
    }
    void clear()
    {
        delete[] listArray;
        listSize=curr=0;
        listArray=new E[maxSize];
        currAllocatedSize=maxSize;
    }

    void moveToStart()
    {
        try{
            if(listSize==0)
                throw "The List is Empty and So current position can't be at Start";
            curr=0;
        } catch(const char* a)
        {
           //cout<<a<<endl;
           //Exception is not printed here in accordance to the Output Format.
        }
    }
    void moveToEnd(){
         try{
            if(listSize==0)
                throw "The List is Empty and So current position can't be at Start";
            curr=listSize-1;
        } catch(const char* a)
        {
           //cout<<a<<endl;
           //Exception is not printed here in accordance to the Output Format.
        }

    }
    void prev(){
        try{
            if(listSize==0 || curr==0)
                throw "Can't go to Previous Position";
                curr--;
        } catch(const char* a)
        {
            //cout<<a<<endl;
           //Exception is not printed here in accordance to the Output Format.
        }
    }
    void next() {
        try{
            if(listSize==0 || curr==(listSize-1))
              throw "Can't go to Next Position";
                curr++;
        }catch(const char* a)
        {
            //cout<<a<<endl;
           //Exception is not printed here in accordance to the Output Format.
        }
    }
    int length() { return listSize; }
    // Return current position
    int currPos()  { return curr; }

    void moveToPos(int pos) {
       try{
        if(pos<0 || pos>=listSize)
           throw "Index Out Of Bound Exception.";
        curr=pos;
        }catch(const char* a)
        {
            //cout<<a<<endl;
            //Exception is not printed here in accordance to the Output Format.
        }
    }
    const E& getValue() const {
        // Return current element
        try{
            if(listSize==0)
                throw "The List is Empty";
        return listArray[curr];
        }catch(const char* a)
        {
            //cout<<a<<endl;
            //Exception is not printed here in accordance to the Output Format.
        }
    }
    int Search(E& item)
    {
        int index=-1;
        for(int i=0;i<listSize;i++)
        {
            if(listArray[i]==item)
            {
                index=i;
                break;
            }
        }
        return index;
    }
};

