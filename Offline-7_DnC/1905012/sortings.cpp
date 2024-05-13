#include<iostream>
#include<fstream>
#include<ctime>
#include<algorithm>
#include<cstring>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


/* This function takes last element as pivot, all the smaller elements are kept in left side and bigger ones are in right side*/
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot element
    int i = (low - 1); // Smaller element's index which indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;  // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
int partition_r(int arr[], int low, int high)
{
    // Generating a random number in between lox and high
    srand(time(NULL));
    int random = low + rand() % (high - low);

    // Swapping A[random] with A[high]
    swap(arr[random], arr[high]);

    return partition(arr, low, high);
}
void quickSort(int arr[], int low, int high,int flag)
{
    if (low < high)
    {
        int middle; // middle is the index of partition.
        if(flag==0)
             middle = partition(arr, low, high);
        else
           middle=partition_r(arr,low,high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, middle - 1,flag);
        quickSort(arr, middle + 1, high,flag);
    }
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    //  temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
void mergeSort(int arr[], int const begin, int const end)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

int main(void)
{
    srand(time(0));     // This program will create same sequence of random numbers on every program run
    int fre[6]={5,10,100,1000,10000,100000};
    double time[6][7];
    string filename("SortReport.txt");       // Output File
    ofstream output_file(filename);
    if (!output_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }
    int*b;
    for(int i=0;i<6;i++) // iterating for different lengths of arrays.
    {
        int n=fre[i];
        for(int z=0;z<7;z++){   // 7 different sorting algorithms  including STL function
            int key=z;
            clock_t time_of_start_sort = clock(); // Storing the initial time from clock function.
            for(int j=1;j<=20;j++)                // Running 20 times and then the average time is taken.
            {
                if(!(key==4 || key==5)){        // cause our input will be a sorted array.
                    delete[] b;
                    b=new int[n];
                    for(int i=0;i<n;i++)
                        b[i]=rand();    // Generating random numbers
                }

                switch(key){
                case 0:
                    mergeSort(b,0,n-1);
                    break;
                case 1:
                    quickSort(b,0,n-1,0);
                    break;
                case 2:
                    quickSort(b,0,n-1,1);
                    break;
                case 3:
                    insertionSort(b,n);
                    break;
                case 4:
                    quickSort(b,0,n-1,0);
                    break;
                case 5:
                    quickSort(b,0,n-1,1);
                    break;
                case 6:
                    sort(b,b+n);
                    break;
                }

            }
            cout<<"total time is "<<((float(clock() - time_of_start_sort) / CLOCKS_PER_SEC)/20)<<" seconds "<<z<<" "<<n<<endl;
            time[i][z]=((float(clock() - time_of_start_sort) / CLOCKS_PER_SEC)/20)*1000;
        }
    }
    output_file<<",Time required in ms,,,,,,"<<endl;
    string header="n,Merge Sort,Quick Sort,Randomized QuickSort,Insertion Sort,QuickSort with Sorted Input,Randomized QuickSort with Sorted Input,STL()";
    output_file<<header<<endl;
    for(int i=0;i<6;i++)
    {
        string s=to_string(fre[i]);
        for(int j=0;j<7;j++)
        {
            s=s+",";
            s=s+to_string(time[i][j]);
        }
        output_file<<s<<endl;
    }
    output_file.close();
    return 0;
}
