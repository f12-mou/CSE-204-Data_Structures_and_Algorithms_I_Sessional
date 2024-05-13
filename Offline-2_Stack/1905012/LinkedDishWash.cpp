
#include<iostream>
#include "LinkedStack.cpp"
using namespace std;

int global;
class Friend
{
private:
    LStack<int>aStack;
public:
    Friend()
    {
        for(int i=global;i>0;i--)
            aStack.push(i);
    }
    void popItem()
    {
        aStack.pop();
    }
    bool isEmpty()
    {
        if(aStack.length()==0)
            return 1;
        else
            return 0;
    }
    int TopValue()
    {
        return aStack.topValue();
    }
};
class dish
{
private:
    int cost;
    int index;
    int timeOfPush;
    int idxOfFriend;
    int endTime;
public:
    dish()
    {

    }
    int getCost(){return cost;}
    int getTimeOfPush()
    {
        return timeOfPush;
    }
    dish(int cost,int index,int timeOfPush,int idxOfFriend)
    {
        this->cost=cost;
        this->index=index;
        this->timeOfPush=timeOfPush;
        this->idxOfFriend=idxOfFriend;
    }
    void setEndTime(int a)
    {
        endTime=a;
    }
    int getEndTime()
    {
        return endTime;
    }
};
int main()
{
    int numOfFriends,numOfMeals;
    cin>>numOfFriends>>numOfMeals;
    Friend* f;
    int* a;
    int unit_cost,k=-1,t,s,available=0,idx,flag=1,total,fullMeal[numOfFriends],sumFullMeal=0;
    global=numOfMeals;
    f=new Friend[numOfFriends];
    a=new int[numOfMeals+1];
    LStack<dish>dirty(numOfFriends*numOfMeals);
    LStack<dish>clean(numOfFriends*numOfMeals);
    LStack<dish>temp(numOfFriends*numOfMeals);
    for(int i=1;i<=numOfMeals;i++)
    {
        cin>>unit_cost;
        a[i]=unit_cost;
    }
    dish processing;
    while(k!=0)
    {
        cin>>k>>s>>idx;
        if(k==0)
            break;
        dish d(a[idx],idx,s,k);
        if(idx!=(f[k-1].TopValue()))
            continue;
        f[k-1].popItem();
        if(s==0)
        {
            processing=d;
            if(available<processing.getTimeOfPush())
                available=processing.getTimeOfPush();
            processing.setEndTime(available+a[idx]-1);
            available+=a[idx];
            continue;
        }
        else if(processing.getEndTime()==s)
        {
            clean.push(processing);
            dirty.push(d);
            processing=dirty.pop();
            if(available<processing.getTimeOfPush())
                available=processing.getTimeOfPush();
            processing.setEndTime(available+processing.getCost()-1);
            available+=processing.getCost();
        }
        else if(processing.getEndTime()<s)
        {
            clean.push(processing);
            while(dirty.length()!=0)
            {
                processing=dirty.pop();
                if((processing.getCost()+available-1)<s)
                {
                    processing.setEndTime(available+processing.getCost()-1);
                    available+=processing.getCost();
                    clean.push(processing);
                }
                else
                {
                    dirty.push(processing);
                }
            }
            dirty.push(d);
             processing=dirty.pop();
            if(available<processing.getTimeOfPush())
                available=processing.getTimeOfPush();
            processing.setEndTime(available+processing.getCost()-1);
            available+=processing.getCost();
        }
        else if(processing.getEndTime()>s)
        {
            dirty.push(d);
        }

    }
    clean.push(processing);
    while(dirty.length()!=0)
    {
        dish temp=dirty.pop();
        if(available<temp.getTimeOfPush())
            available=temp.getTimeOfPush();
        temp.setEndTime(available+temp.getCost()-1);
        available=available+temp.getCost();
        clean.push(temp);
    }
    total=clean.topValue().getEndTime();
    cout<<total<<endl;
    while(clean.length()!=0)
    {

        dish item=clean.pop();
        temp.push(item);
    }
    while(temp.length()!=0)
    {
        dish item=temp.pop();
        cout<<item.getEndTime();
         if(temp.length()!=0)
            cout<<", ";
    }
    cout<<endl;
    for(int i=0;i<numOfFriends;i++)
    {
        if(f[i].isEmpty()==1)
           {
               fullMeal[sumFullMeal++]=i+1;
           }
        else
            flag=0;

    }
    if(flag==0)
        cout<<"N"<<endl;
    else
        cout<<"Y"<<endl;
     for(int i=0;i<sumFullMeal;i++){
        cout<<fullMeal[i];
        if(i!=(sumFullMeal-1))
            cout<<", ";
    }
    cout<<endl;
    delete f;
    delete a;
    return 0;
}

