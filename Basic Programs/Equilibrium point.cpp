#include <bits/stdc++.h>
using namespace std;
int equi(int arr[],int n){
    if(n==1)
        return 1;
    if(n==2)
        return -1;
    int sum[n];
    int total=0;
    for(int i=0;i<n;i++){
        sum[i]=arr[i]+total;
        total=sum[i];
    }
    
    for(int i=1;i<n-1;i++){
        int left=sum[i]-arr[i];
        int right=total-sum[i];
        if(right==left)
            return i+1;
    }
    return -1;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<equi(arr,n)<<"\n";
    }
	return 0;
}
