#include<vector>
using namespace std;

class Heap          //Implementing Heap Class
{
private:
    int cnt;        // The count of array elements currently stored in the heap.
    int maxsize;    // The maximum size the array can hold.
    int* arr;
    void reAllocate()
    {
        int* temp;
        temp=new int[maxsize+1];
        for(int i=1;i<=cnt;i++)
            temp[i]=arr[i];
        delete[] arr;
        maxsize=maxsize*2;
        arr=new int[maxsize];
        for(int i=1;i<=cnt;i++)
            arr[i]=temp[i];
        delete temp;
     }
     void build_Max_Heap()
     {
         int i=cnt/2; // After this index, all the nodes are leaves and thus one elem max-heap.
         for(;i>=1;i--)
         {
             max_Heapify(i);
         }
     }
     int left(int i){return i<<1;}
     int right(int i){return ((i<<1)|1);}
     int parent(int i){return i>>1;}
     void max_Heapify(int i)
     {
         int l=left(i);
         int r=right(i);
         int largest;
         if(l<=cnt && arr[l]>arr[i])
            largest=l;
         else
            largest=i;
         if(r<=cnt && arr[r]>arr[largest])
            largest=r;
         if(largest!=i)
         {
             int temp=arr[largest];
             arr[largest]=arr[i];
             arr[i]=temp;           // Swapping the elements.
             max_Heapify(largest); // Recursive calls to maintain heap property.
         }
     }
     void heapify(int i)
    {
        int p=parent(i);
        if(p>0){
            if(arr[i]>arr[p])
            {
                int temp=arr[i];
                arr[i]=arr[p];
                arr[p]=temp;
                heapify(p);
            }
        }
    }

public:
    Heap(int sz=1000)
    {
        maxsize=sz;
        arr=new int[maxsize+1];
        cnt=0;
    }
    Heap(vector<int>& v)
    {
        maxsize=v.size();
        arr=new int[maxsize+1]; // We will not keep anything at 0th index of the array.
        cnt=v.size();
        for(int i=1;i<=cnt;i++)
        {
            arr[i]=v[i-1];
        }
        build_Max_Heap();
    }
    ~Heap()
    {
        delete[] arr;
    }
    void insert(int num)
    {
        if(cnt==maxsize)
            reAllocate();
        cnt++;
        arr[cnt]=num;
        heapify(cnt);
    }
    int getMax()
    {
       try{
            if(cnt==0)
                throw "The Heap is Empty and thus can't return any valid element.";
            return arr[1];
       }catch(const char* a)
       {
           cout<<a<<endl;
           return -1;
       }
    }
    void deleteKey()
    {
        try{
            if(cnt==0)
                throw "The Heap is Empty and thus can't delete any element.";
            arr[1]=arr[cnt];
            cnt--;
            max_Heapify(1);
        }catch(const char* a)
       {
           cout<<a<<endl;
       }

    }
    int size(){return cnt;}
    Heap& operator=(Heap& obj)     // Protecting Assignment
     {
         delete arr;
         maxsize=obj.maxsize;
         cnt=obj.cnt;
         arr=new int[maxsize];
         for(int i=0;i<cnt;i++)
         {
             arr[i]=obj.arr[i];
         }
         return *this;
    }
    Heap(Heap& obj)                 // Protecting copy constructor
    {
         maxsize=obj.maxsize;
         cnt=obj.cnt;
         arr=new int[maxsize];
         for(int i=0;i<cnt;i++)
         {
             arr[i]=obj.arr[i];
         }
    }
};
void heapsort(vector<int>& v)
{
    Heap h(v);
    int len=v.size();
    v.clear();
    for(int i=0;i<len;i++)
    {
        int a=h.getMax();
        v[i]=a;
        h.deleteKey();
    }
}
