#include <iostream>
#include <algorithm>
using namespace std;
//program to search an element in a sorted array using binary search
int bin(int arr[], int start, int end, int k)
{
while (start<=end)
{
int mid = start + (end - start) / 2;

if (arr[mid] == k)
return mid;

if (arr[mid] < k)
start = mid + 1;

else
end = mid - 1;
}

return -1;

}

int main()
{
int n;
cin>>n;
int arr[n];
for(int i=0;i<=n;i++)
{
cin>>arr[i];
}
int k ;
cin>>k;
int ans = bin(arr, 0, n - 1, k);
(ans == -1) ? cout<< "-1": cout<<ans;
return 0;
}
//Time Complexity:O(logn)