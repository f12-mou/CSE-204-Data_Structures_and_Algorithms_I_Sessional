#include<iostream>
//#include "Arr.cpp"
#include "LL.cpp"
using namespace std;

template<typename E>
void print(LList<E>& listObj)
{
    int currPos=listObj.currPos();
    listObj.moveToStart();
    cout<<"< ";
    for(int i=0;i<listObj.length();i++)
    {
        if(i==currPos)
            cout<<"| ";
        cout<<listObj.getValue()<<" ";
        listObj.next();
    }
    listObj.moveToPos(currPos);
    cout<<">"<<endl;
}

int main()
{
    int k,x,i,item,key=-1,parameter;
    cin>>k>>x;
    List<int>*a;
    LList<int>llist(x);
    a=&llist;

    for(i=0;i<k;i++)
    {
        cin>>item;
        a->append(item);
    }
    print(llist);
    while(key!=0)
    {
        cin>>key>>parameter;
        if(key==1 || key==2 || key==3 || key==5 || key==6 || key==7 || key==8 || key==11)
            cout<<-1<<endl;

        switch(key){
        case 0:
            return 0;
        case 1:
            a->clear();
            break;
        case 2:
            a->insert(parameter);
            break;
        case 3:
            a->append(parameter);
            break;
        case 4:
            cout<<a->remove()<<endl;
            break;
        case 5:
            a->moveToStart();
            break;
        case 6:
            a->moveToEnd();
            break;
        case 7:
            a->prev();
            break;
        case 8:
            a->next();
            break;
        case 9:
            cout<<a->length()<<endl;
            break;
        case 10:
            cout<<a->currPos()<<endl;
            break;
        case 11:
            a->moveToPos(parameter);
            break;
        case 12:
            cout<<a->getValue()<<endl;
            break;
        case 13:
            cout<<a->Search(parameter)<<endl;
            break;
      }
        print(llist);
   }
   return 0;
}
