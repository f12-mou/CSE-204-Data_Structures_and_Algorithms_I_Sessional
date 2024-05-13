#include<iostream>
#include "ArrayQueue.cpp"
using namespace std;

template<typename E>class booth
{
public:
    AQueue<E>a;
    booth()
    {
        //Default Constructor
    }
};
class customer
{
public:
    int boothNumber;
    int pushTime;
    int cost;
    int leaveTime;
    int replaced;
    customer(int p, int c, int r=0)
    {
        pushTime=p;
        cost=c;
        replaced=r;
    }
    customer()
    {

    }
};

int main()
{
    int n,k,c,t,ava[3]={0,0,0};
    cin>>n;
    booth<customer> b[3];
    for(k=0;k<n;k++)
    {
        cin>>t>>c;
        customer obj(t,c);
        int flag=1;
        for(int i=1;i<=2;i++)
        {
            if(b[i].a.length()==0)
            {
                ava[i]=max(ava[i],obj.pushTime);
                obj.leaveTime=ava[i]+obj.cost-1;
                obj.boothNumber=i;
                b[i].a.enqueue(obj);
                ava[i]=ava[i]+obj.cost;
                //cout<<"Now the free time of booth number "<<i<<" is "<<ava[i]<<endl;
                flag=0;
                break;
            }
        }
        if(flag==0)
            continue;
        if(t<ava[1] && t<ava[2])
        {
            int min_idx;
            if(b[1].a.length()<=b[2].a.length())
                min_idx=1;
            else
                min_idx=2;
            obj.boothNumber=min_idx;
            b[min_idx].a.enqueue(obj);
            //cout<<"The customer number "<<k<<" is sent to booth "<<min_idx<<endl;
            continue;
        }
        int idx1,idx2,minidx,maxidx,flag2=0;
        while(t>=ava[1] || t>=ava[2])
        {
            if(t>=ava[1])
            {
                if(ava[1]<ava[2])
                {idx1=1;idx2=2;}
                else
                {
                    idx1=2;idx2=1;
                }
            }
            else
            {
                idx1=2;idx2=1;
            }
            b[idx1].a.dequeue();
            if(b[idx1].a.length()!=0)
            {
                customer temp=b[idx1].a.frontValue();
                ava[idx1]=max(ava[idx1],temp.pushTime);
                ava[idx1]=ava[idx1]+temp.cost;
                //cout<<"Now the free time of booth number "<<idx1<<" is "<<ava[idx1]<<endl;
            }
            while((b[idx1].a.length()+1)<b[idx2].a.length())
            {
                customer temp=b[idx2].a.leaveQueue();
                temp.replaced=ava[idx1];
                b[idx1].a.enqueue(temp);
                flag2=1;
            }
            if(b[idx1].a.length()==0 || b[idx2].a.length()==0)
                break;
            }
            if(flag2==1){
            if(b[idx1].a.length()>b[idx2].a.length())
                maxidx=idx1;
            else if(b[idx2].a.length()>b[idx1].a.length())
                maxidx=idx2;
            if(b[maxidx].a.rearValue().replaced == t)
            {
                customer temp=b[maxidx].a.leaveQueue();
                if(maxidx==1)
                    {
                        b[2].a.enqueue(temp);
                        idx1=1;
                        //cout<<"The customer number "<<k<<" is sent to booth 2 "<<endl;
                    }
                else{
                    b[1].a.enqueue(temp);
                    idx1=2;
                    //cout<<"The customer number "<<k<<" is sent to booth 1"<<endl;
                }
            }
            }
            b[idx1].a.enqueue(obj);
            if(b[idx1].a.length()==1)
                ava[idx1]=max(ava[idx1],obj.pushTime)+obj.cost;
           // cout<<"The customer number "<<k<<" is sent to booth "<<idx1<<endl;
        }
    b[1].a.dequeue();
    b[2].a.dequeue();
    while(b[1].a.length()!=0)
    {
        customer temp=b[1].a.dequeue();
        ava[1]+=temp.cost;
    }
     while(b[2].a.length()!=0)
    {
        customer temp=b[2].a.dequeue();
        ava[2]+=temp.cost;
    }
    cout<<"Booth 1 finishes service at t = "<<ava[1]<<endl;
    cout<<"Booth 2 finishes service at t = "<<ava[2]<<endl;
    return 0;
}


