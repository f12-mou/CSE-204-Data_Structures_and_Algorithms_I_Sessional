#include<iostream>
#include<cstring>
#define SIZE 55
using namespace std;
int L[SIZE][SIZE], D[SIZE][SIZE];

int DPLCS(char x[],char y[],int m,int n)
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])  // If a match is found, then considering the diagonal value
            {
                L[i][j]=L[i-1][j-1]+1;
                D[i][j]=1;
            }
            else
            {
                if(L[i-1][j]>L[i][j-1])
                {
                    L[i][j]=L[i-1][j];
                    D[i][j]=2;          // To trace the max from upper cell, storing 2 in corresponding D table
                }
                else
                {
                    L[i][j]=L[i][j-1];
                    D[i][j]=3;          // To trace the max from left cell, storing 3 in corresponding D table
                }
            }
        }
    }
    return L[m][n]; // The final Value of L[m][n] stores the Length of Longest Common Subsequence.

}
void ConstructLCS(char x[],char y[],int m,int n,char ans[])
{
    int len,len2;
    len=len2=L[m][n];
    while(m!=0 && n!=0)
    {
        if(D[m][n]==1)
        {
            ans[len-1]=x[m-1];
            len--;
            m--;
            n--;
        }
        else if(D[m][n]==2)
            m--;
        else
            n--;
    }
}
int main()
{
    char x[SIZE],y[SIZE],ans[SIZE];
    int m,n,lcs;
    cin>>x>>y;
    m=strlen(x);
    n=strlen(y);
    lcs=DPLCS(x,y,m,n);
    cout<<lcs<<endl;
    ConstructLCS(x,y,m,n,ans); // To get the Longest Common Subsequence in the ans array.
    for(int j=0;j<lcs;j++)
        cout<<ans[j];
    cout<<endl;
    return 0;
}

