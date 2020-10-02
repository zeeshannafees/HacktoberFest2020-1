//implementing binary search and checking if an element is present in a 1-D array or not, the array has to be sorted while inputting, here, array is in ascending order.
#include <iostream>
using namespace std;
int main()
{
  int n,i,j,arr[1000],mid,lower=0,upper=0,flag=0,element;
  cout<<"enter array size"<<endl;
  cin>>n;
  lower=0;
  upper=n;
  for(i=0;i<n;i++)
  cin>>arr[i];
  cout<<"Enter the element to be found"<<endl;
  cin>>element;
  mid=(lower+(upper-1))/2;
  for(i=0;i<n;i++)
  {
      if(element>arr[mid])
      {
          lower=mid+1;      //if array was sorted in descended order, upper=mid-1 was to be done for this condition
      }
      if(element<arr[mid])
      {
          upper=mid-1;      //if array was sorted in descended order, lower=mid+1 was to be done for this condition
      }
      else
      {flag=1; break;}
  }
    if(flag==1)
    cout<<"Element is present in the array"<<endl;
    else
    cout<<"Element is not present in the array"<<endl;
return 0;
}