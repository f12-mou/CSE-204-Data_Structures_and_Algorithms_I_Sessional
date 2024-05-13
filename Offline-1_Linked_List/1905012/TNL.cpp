#include<iostream>
#include "Arr.cpp"
using namespace std;
template<typename E>
void printStationList(AList<E>& objList,int totalStations)
{
    for(int i=0;i<totalStations;i++)
       {
           if(objList.Search(i)!=-1)
                i==totalStations-1?cout<<i:cout<<i<<", ";
           else
                cout<<" , ";
       }
    cout<<endl;
}
int main()
{
       int numOfBS,numOfRS,numOfTS,input,task;
       List<int>*a,*b,*c;
       cin>>numOfRS;
       AList<int>RS(numOfRS);
       a=&RS;
       for(int i=0;i<numOfRS;i++)
           a->append(i);
       cin>>numOfBS;
       AList<int>BS(numOfBS);
       b=&BS;
       for(int i=0;i<numOfBS;i++){
            cin>>input;
            b->append(input);
       }
       cin>>numOfTS;
       AList<int>TS(numOfTS);
       c=&TS;
       for(int i=0;i<numOfTS;i++){
            cin>>input;
            c->append(input);
       }
       while(1)
           {
               cin>>task;
               switch(task){
                   case 0:
                       return 0;
                   case 1:
                       printStationList(RS,numOfRS);
                       printStationList(BS,numOfRS);
                       printStationList(TS,numOfRS);
                       break;
               }
           }
       return 0;
}

