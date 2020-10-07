//to display array elements in reverse
#include <iostream>
using namespace std;
int main()
{
    int n,i,j;
    int arr[1000];
    cout<<"Enter array size"<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>arr[i];
    cout<<"Reversed array is: "<<endl;
    for(j=n-1;j>=0;j--)
    cout<<arr[j]<<" ";
    return 0;
}