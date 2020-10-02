//This program generates n-digit random number

#include<bits/stdc++.h>
using namespace std;
int main(){
    int d;
    cout<<"Enter number of digits : ";
    cin>>d;
    int n=0;
    for(int i=0;i<d;i++){
        int x=rand()%10;
        if(i==0&&x==0)x=1;
        n=(n*10)+x;
       
    }
    cout<<n<<endl;
}
