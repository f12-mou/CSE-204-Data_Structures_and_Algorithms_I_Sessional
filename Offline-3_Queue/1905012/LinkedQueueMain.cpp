#include<iostream>
#include<cstdlib>
#include "LinkedListQueue.cpp"
using namespace std;

template<typename E>
void print(LQueue<E>& Obj)
{
    int len=Obj.length();
    int flag=1;
    LQueue<E>temp(Obj.length());
    cout<<"< ";
    while(len>0)
    {
        if(flag==1)
        {
            cout<<"| ";flag=0;
        }
        E item=Obj.dequeue();
        cout<<item<<" ";
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
    cout<<">"<<endl;
}
int main()
{
    int k,x,i,item,key=-1,parameter;
    cin>>k;
    Queue<int>*a;
    LQueue<int>aQueue(k);
    a=&aQueue;

    for(i=0;i<k;i++)
    {
        cin>>item;
        a->enqueue(item);
    }
    print(aQueue);
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
            a->enqueue(parameter);
            break;
        case 3:
            if(a->length()!=0)
            cout<<a->dequeue()<<endl;
            break;
        case 4:
            cout<<a->length()<<endl;
            break;
        case 5:
            if(a->length()!=0)
            cout<<a->frontValue()<<endl;
            break;
        case 6:
            if(a->length()!=0)
            cout<<a->rearValue()<<endl;
            break;
        case 7:
            if(a->length()!=0)
            cout<<a->leaveQueue()<<endl;
            break;
      }
        print(aQueue);
   }
    return 0;
}



