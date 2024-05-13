#include<iostream>
#include<cstdlib>
#include "StackADT.cpp"
using namespace std;
template<typename E>class Node
{
public:
     E data;
     Node* next;
     Node(E elem,Node* further)
     {
         data=elem;
         next=further;
     }
     ~Node()
     {

     }
 };
//Linked Stack Implementation
template<typename E>class LStack:public Stack <E>
{
private:
    Node<E>* top;
    int cnt;
public:
    LStack(int sz=100)
    {
        top=NULL;
        cnt=0;
    }
    LStack& operator=(LStack& obj)
    {
        clear();
        top=NULL;
        LStack temp;
        while(obj.length()!=0)
        {
            E item=obj.pop();
            temp.push(item);
        }
        while(temp.length()!=0)
        {
            E item=temp.pop();
            push(item);
            obj.push(item);
        }
        return *this;
    }
    ~LStack()
    {
        clear();
        top=NULL;
    }
    void clear()
    {
        while(top!=NULL)
        {
            Node<E>* temp=top;
            top=top->next;
            delete temp;
        }
        cnt=0;
    }
    void push(E& it)
    {
        top=new Node<E>(it,top);
        cnt++;
    }
    E pop()
    {
        try{
            if(cnt==0)
                throw "The Stack is Empty";
            E item=top->data;
            Node<E>* temp=top;
            top=top->next;
            delete temp;
            cnt--;
            return item;
        }catch(const char* a)
        {
            //cout<<a<<endl;
            //Here exception is not printed in accordance with the output format
            exit(1);
        }
    }

    E topValue(){ // Return top value
        try{
            if(cnt==0)
                throw "The Stack is Empty";
        return top->data;
        }catch(const char* a)
        {
            //cout<<a<<endl;
            //Here exception is not printed in accordance with the output format
            exit(1);
        }
    }
    int length()
    {
        return cnt;
    } // Return length
    void setDirection(int a)
    {
        //nothing to do
    }
};
template<typename E>
void print(LStack<E>& stackObj)
{
    LStack<E>temp(stackObj.length());
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
    LStack<int>lStack(x);
     LStack<int>lStack2(x);
    a=&lStack;

    for(i=0;i<k;i++)
    {
        cin>>item;
        a->push(item);
    }
    lStack2=lStack;
    print(lStack2);
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
        print(lStack);
   }
   return 0;
}
*/
