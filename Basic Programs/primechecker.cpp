//This program checks whether given number is prime or not.
//Prints Yes if given number is prime otherwise prints No.
//Time complexity O(n). This can be improved using sieve for multiple queries

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number : ";
    cin>>n;
    int c=0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)c+=1;
    }
    if(c==0)
        cout<<"Yes";
    else cout<<"No";
}
