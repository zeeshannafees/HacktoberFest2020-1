Minimum operations
question link - https://practice.geeksforgeeks.org/problems/find-optimum-operation/0

Solutions-

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        int count=0;
        while(n!=0){
            if(n%2==0){
                n/=2;
                count++;
            }else{
                n-=1;
                count++;
            }
        }
        cout << count<<endl;
    }
	return 0;
}
