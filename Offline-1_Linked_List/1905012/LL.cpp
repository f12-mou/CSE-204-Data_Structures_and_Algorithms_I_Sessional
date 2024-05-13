#include<iostream>
#include<cstdlib>
#include "List.cpp"
using namespace std;

template<typename E>class Node
{
public:
    E data;
    Node* next;
    Node* prev;
    Node(Node* ago=NULL,Node* further=NULL)
    {
        prev=ago;
        next=further;
    }
    Node(E item,Node* ago=NULL,Node* further=NULL)
    {
        data=item;
        prev=ago;
        next=further;
    }
    ~Node()
    {
        //Destructor
    }
};

template<typename E> class LList:public List<E>
{
private:
    Node<E>* head;
    Node<E>* tail;
    Node<E>* curr;
    int cnt;
    void init()
    {
        head=new Node<E>;
        tail=new Node<E>;
        head->next=tail;
        tail->prev=head;
        curr=tail;
        cnt=0;
    }
    void removeAll()
    {
        while(head!=NULL)
        {
            curr=head;
            head=head->next;
            delete curr;

        }
        cnt=0;
    }
public:
    //Constructor for an empty list
    LList(int size=100)
    {
        init();
    }
    LList(E* arr, int Y)
    {
        init();
        for(int i=0;i<Y;i++)
        {
           append(*arr);
           arr++;
        }
        cnt=Y;
        curr=head->next;
    }
     ~LList(){removeAll();}//Destructor

    LList(const LList& obj)
     {
         init();
         Node<E>*temp=(obj.head)->next;
         int pos=0;
          int a=0;
         while(temp->next!=NULL)
         {
             if(temp==obj.curr)
                pos=a;
             E item=temp->data;
             append(item);
             temp=temp->next;
             a++;
         }
          moveToPos(pos);

     }

       LList& operator=(const LList& obj)
     {
          clear();
          Node<E>*temp=(obj.head)->next;
          int pos=0;
          int a=0;
          while(temp->next!=NULL)
          {
             if(temp==obj.curr)
                pos=a;
             E item=temp->data;
             append(item);
             temp=temp->next;
             a++;
          }
          moveToPos(pos);

     }
    //Clearing and reInitializing the list
    void clear()
    {
        removeAll();
        init();
    }

    //Inserting an element after the Current Position
    void insert(const E& item)
    {
        Node<E>* temp=new Node<E>(item,curr->prev,curr);
        curr->prev=temp;
        temp->prev->next=temp;
        curr=curr->prev;
        cnt++;
    }

    void append(const E& item)
    {
        Node<E>* temp=new Node<E>(item,tail->prev,tail);
        tail->prev=temp;
        temp->prev->next=temp;
        cnt++;
        if(cnt==1)
            curr=curr->prev;
    }
    void moveToStart()
    {
        try{
        if(head->next==tail)
            throw "The List is Empty and So current position can't be at Start";
        curr=head->next;
        } catch(const char* a)
        {
           //cout<<a<<endl;
           //Exception is not printed here in accordance to the Output Format.
        }
    }
    void moveToEnd()
    {
        try{
        if(head->next==tail)
            throw "The List is Empty and So current position can't be at the End";
        curr = tail->prev;
        }catch(const char* a)
        {
           //cout<<a<<endl;
           //Exception is not printed here in accordance to the Output Format.
        }
    }
    void prev()
    {
        try{
        if(curr->prev==head)
            throw "The List is Empty and Current Position can't go backward.";
            curr=curr->prev;
        }catch(const char* a)
        {
           //cout<<a<<endl;
           //Exception is not printed here in accordance to the Output Format.
        }
    }
    void next()
    {
        try{
        if(curr->next==tail)
             throw "Already at the Last Position";
        else if(curr==tail)
            throw "The list is empty and can't go to Next";
        curr=curr->next;
        }catch(const char* a)
        {
            //cout<<a<<endl;
            //Exception is not printed here in accordance to the Output Format.
        }
    }
    int length()
    {
        return cnt;
    }
    int currPos()
    {
        if(head->next==tail)
            return -1;
        int index=0;
        Node<E>* temp=head->next;
        while(temp!=curr)
        {
            temp=temp->next;
            index++;
        }
        return index;
    }
    void moveToPos(int pos)
    {
        try{
        if(pos<0 || pos>=cnt)
           throw "Index Out Of Bound Exception.";
        Node<E>* temp=head->next;
        for(int i=0;i<pos;i++)
        {
            temp=temp->next;
        }
        curr=temp;
        }catch(const char* a)
        {
            //cout<<a<<endl;
            //Exception is not printed here in accordance to the Output Format.
        }
    }
    const E& getValue()
    {
        try{
        if(curr==tail)
            throw "The List is Empty.";
        return curr->data;
        }catch(const char* a)
        {
            //cout<<a<<endl;
            //Exception is not printed here in accordance to the Output Format.
        }
    }
    E remove()
    {
         try{
        if(curr==tail)
            throw "The List is Empty.";
        Node<E>*temp=curr;
        E it=temp->data;
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
        curr=curr->next;
        if(curr->next==NULL){
            curr=curr->prev;
            if(curr==head)
                curr=tail;
        }
        delete temp;
        cnt--;
        return it;
         }catch(const char* a)
        {
            //cout<<a<<endl;
            //Exception is not printed here in accordance to the Output Format.
            exit(1);
        }
    }
    int Search(E& item)
    {
        int index=-1;
        Node<E>*temp=head->next;
        for(int i=0;i<cnt;i++)
        {
            if(item==temp->data)
            {
                index=i;
                break;
            }
            temp=temp->next;
        }
        return index;
    }
};
