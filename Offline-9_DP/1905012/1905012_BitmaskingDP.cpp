#include <iostream>
#include<cstring>
#define check(n, pos) (n & (1<<pos))
#define set(n, pos) (n | (1<<pos))
using namespace std;

int n;
long long a[15][15];
int dp[15][1<<18]; // row represents the flag = n-th visit to the column's city.

long long getCost(int i, long long vis)
{
    long long sum;
	sum = INT_MAX;

	if(i == n)
		return 0;

    if(dp[i][vis] == -1)
    {
        for (int j = 0; j < n; j++) { // Iterating over the mask to check which city is unvisited
			if(check(vis, j) == 0) {
                    long long temp=a[j][j]; // This diagonal value of the a array is the cost to visit the j city.
                    for(int k=0;k<10;k++)
                    {
                        if(vis&(1<<k))
                            temp+=a[j][k]; // We are going to visit j city, and hence adding the values which occurred before this city.
                    }
                    sum = min(sum, temp + getCost(i+1, set(vis, j)));// After visiting the j city, we move forward increasing the order of visiting city
                                                                        // marking the j city visited.
            }
        }
        dp[i][vis] = sum;  // Updating the value in the table.
        return sum;
    }
    else {
		return dp[i][vis];
	}
}

int main()
{
	int x;
	long long sum;
	long long vis;
	vis = 0;
    cin>>n;
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
            cin>>a[j][k];
    }
    memset(dp, -1 , sizeof(dp));
    vis = 0;
    sum = getCost(0, vis);
    cout<<sum<<endl;
    return 0;
}

