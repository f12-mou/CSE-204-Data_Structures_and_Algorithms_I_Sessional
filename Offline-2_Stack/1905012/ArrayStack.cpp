#include<iostream>
#include<cstdlib>
#include "StackADT.cpp"
using namespace std;
//Array Based Stack Implementation
template<typename E>class AStack:public Stack<E>
{
private:
    int maxsize;        //Maximum Size of Stack
    int top;            //Index of top element
    int direction;      //1 indicates stack will grow upward and -1 indicates stack will go downward
    int sharedArray;    //Flag to determine whether the Pointer will be deleted or not in the destructor
    E* listarray;       //Array holding the stack elements

void reAllocate()
{
   if(direction==1){
    E* temp;
    temp=new E[maxsize];
    for(int i=0;i<maxsize;i++)
        temp[i]=listarray[i];
    delete[] listarray;
    listarray=new E[maxsize*2];
    for(int i=0;i<maxsize;i++)
        temp[i]=listarray[i];
    delete[] temp;
    maxsize=maxsize*2;
    }
   else{
        E* temp;
        int prev_maxsize=maxsize;
        int prev_top=top;
        temp=new E[maxsize];
        for(int i=maxsize-1;i>top;i--)
            temp[i]=listarray[i];
        delete[] listarray;
        listarray=new E[maxsize*2];
        maxsize=maxsize*2;
        top=top+prev_maxsize;
        for(int i=maxsize-1;i>top;i--){
           listarray[i]=temp[prev_maxsize-1];
           prev_maxsize--;
        }
        delete[] temp;
   }
}
public:
    AStack(int size=100) //Constructor
    {
        maxsize=size;
        listarray=new E[maxsize];
        top=0; //Setting the position to receive new stack elements
        direction=1;
        sharedArray=0;
    }
    AStack(E* arr,int maxi,int dir)
    {
        maxsize=maxi;
        listarray=arr;
        direction=dir;
        if(dir==1)
            top=0;
        else
            top=maxi-1;
        sharedArray=1;
    }

    AStack& operator=(const AStack& obj)
    {
        delete[] listarray;
        maxsize=obj.maxsize;
        top=obj.top;
        direction=obj.direction;
        listarray=new E[maxsize];
        if(direction==1)
        {
            for(int i=0;i<maxsize;i++)
                listarray[i]=obj.listarray[i];
        }
        else
        {
             for(int i=maxsize-1;i>top;i--)
                listarray[i]=obj.listarray[i];
        }
    }
    AStack(const AStack& obj)
    {
        maxsize=obj.maxsize;
        top=obj.top;
        direction=obj.direction;
        listarray=new E[maxsize];
        if(direction==1)
        {
            for(int i=0;i<maxsize;i++)
                listarray[i]=obj.listarray[i];
        }
        else
        {
             for(int i=maxsize-1;i>top;i--)
                listarray[i]=obj.listarray[i];
        }
    }

    ~AStack() //Destructor
    {
        if(sharedArray==0){
        delete[] listarray;
        }
    }
    void clear()
    {
        if(direction==1)
            top=0;
        else
            top=maxsize-1;
    }
    void push(E& item)
    {
        if(top==maxsize)
        {
            reAllocate();
        }
        listarray[top]=item;
        top+=direction;
    }
    E pop()
    {
        try{
            if((top==0 && direction==1)||(top==maxsize-1 && direction==-1))
                throw "Stack is Empty";
            E item=listarray[top-direction];
            top=top-direction;
            return item;
        }catch(const char* a)
        {
            //cout<<a<<endl;
            //Here exception is not printed in accordance with the output format
            exit(1);
        }
    }
    E topValue()
    {
        try{
            if ((top==0 && direction==1)||(top==maxsize-1 && direction==-1))
                throw "Stack is Empty";
            return listarray[top-direction];
        }catch(const char* a)
        {
            //cout<<a<<endl;
            //Here exception is not printed in accordance with the output format
            exit(1);
        }
    }
    int length()
    {
        if(direction==1)
            return top;
        else
            return maxsize-1-top;
    }
    void setDirection(int a)
    {
        if(length()==0)
            {
                direction=a;
                if(direction==0)
                    top=0;
                else
                    top=maxsize-1;
            }
        else
            cout<<"Direction can't be changed as the stack is not now empty"<<endl;
    }
};
template<typename E>
void print(AStack<E>& stackObj)
{
    AStack<E>temp(stackObj.length());
    while(stackObj.length()!=0)
    {
        E item=stackObj.pop();
        temp.push(item);
    }
    cout<<"< ";
    while(temp.length()!=0)
    {
        E item=temp.pop();
        cout<<item<<" ";
        stackObj.push(item);
    }
    cout<<">"<<endl;
}
/*
int main()
{
    int k,x,i,item,key=-1,parameter;
    cin>>k>>x;
    Stack<int>*a;
    AStack<int>aStack(x);
    a=&aStack;

    for(i=0;i<k;i++)
    {
        cin>>item;
        a->push(item);
    }
    print(aStack);
    while(key!=0)
    {
        cin>>key>>parameter;
        if(key==1 || key==2)
            cout<<-1<<endl;

        switch(key){
        case 0:
            return 0;
        case 1:
            a->clear();
            break;
        case 2:
            a->push(parameter);
            break;
        case 3:
            cout<<a->pop()<<endl;
            break;
        case 4:
            cout<<a->length()<<endl;
            break;
        case 5:
            cout<<a->topValue()<<endl;
            break;
        case 6:
            if((parameter==1 || parameter==-1) && a->length()==0)
                a->setDirection(parameter);
            break;
      }
        print(aStack);
   }
   return 0;
}

*/
