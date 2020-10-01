//Given numbers 0 to n where one number in the range is missing find the missing number
#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int>& nums) {
    int n=nums.size(),sum=0;
    int i,x=n*(n+1)/2;
    for(i=0;i<n;i++)
        sum+=nums[i];
    if(sum==x)
        return 0;
    else
        return x-sum;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    cout<<missingNumber(nums);
    return 0;
}
