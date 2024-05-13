#include<iostream>
#include<ctime>
using namespace std;
#define ll long long
void quickSort(ll arr[], int low, int high,int flag);

ll getCost(ll a[],ll n, ll k)
{
    ll sum, i, j, flag=0, cost=0, b=0;
    for(i=n-1;i>=0;)
    {
        sum=0;
        for(j=0;j<k;j++)
        {
            if(i-j<0)
            {
                flag=1; // end of array so break
                break;
            }
            else
            {
                sum=sum+a[i-j]; // sum of cost in one cycle
            }
        }
        cost=cost+sum*(b+1);    // multiplied by the weight (previously bought trees)
        b++;
        i=i-k;
        if(flag==1 || i<0)
            break;
    }
    return cost;
}
int main()
{
    ll n,k;
    ll* a;
    cin>>n>>k;
    a= new ll[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    quickSort(a,0,n-1,1);   // randomized quick sort
    cout<<"The minimum cost is "<<getCost(a,n,k)<<endl;
    delete[] a;
    return 0;
}
void swap(ll* a, ll* b)
{
    ll t = *a;
    *a = *b;
    *b = t;
}
int partition (ll arr[], int low, int high)
{
    ll pivot = arr[high]; // pivot element
    int i = (low - 1); // Smaller element's index which indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
int partition_random(ll arr[], int low, int high)
{
    srand(time(NULL));      // Generating a random number in between lox and high
    int random = low + rand() % (high - low);

    // Swapping arr[random] with arr[high]
    swap(arr[random], arr[high]);

    return partition(arr, low, high);
}
void quickSort(ll arr[], int low, int high,int flag)
{
    if (low < high)
    {
        int middle;         // here middle is the index of partition.
        if(flag==0)
             middle = partition(arr, low, high);
        else
           middle=partition_random(arr,low,high);

        // Separately sorting elements before partition and after partition
        quickSort(arr, low, middle - 1,flag);
        quickSort(arr, middle + 1, high,flag);
    }
}
