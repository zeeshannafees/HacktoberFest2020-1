//This program generates a string of given length.


#include<bits/stdc++.h>
using namespace std;
int main(){
    int len;
    cout<<"Enter the length of string to be generated : ";
    cin>>len;
    string s="""";
    for(int i=0;i<len;i++){
        int x=rand()%26;
        char c='a'+x;
        s+=c;
    }
    cout<<s;
}
