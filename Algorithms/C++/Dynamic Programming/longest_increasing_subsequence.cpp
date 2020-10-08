
/*
Author: Shrey

Problem: Given an array of integers, find the length of longest increasing subsequence of the array
Expected Time Complexity: O(n^2)
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,i,j;
    cout<<"Enter length of array\n";
    cin>>n;
    ll a[n];
    ll dp[n];
    cout<<"Enter array elements\n";
    for(i=0;i<n;i++)
    {
        cout<<"Enter the "<<(i+1)<<"th element: ";
        cin>>a[i];
        dp[i]=1;
    }
    cout<<"\n";

    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]<a[i] && dp[j]+1>dp[i])
            {
                dp[i]=dp[j]+1;
            }
        }
    }
    ll f=0;
    for(i=0;i<n;i++)
        f=max(f,dp[i]);

    cout<<"Length of longest increasing subsequence is: "<<f<<"\n";

    return 0;
}

