#include<iostream>
using namespace std;

void printSubArray(int arr[], int start,int end){
	cout<<"{ ";
	for(int i=start; i<=end; i++)
		cout<<arr[i]<<" ";
	cout<<"}";
}

void solve(int arr[], int n ){
	for(int s=0; s<n; s++){
		for(int e=s; e<n; e++){
			printSubArray(arr,s,e);
			cout<<endl;
		}
	}
}

int main()
{
	int arr[8] = {1,2,3,4,5,6,7,8}; //reference array 
	//our task to print all subarray here
	int n = sizeof(arr)/sizeof(arr[0]);
	// cout<<n;

	solve(arr,n);

	return 0;
}