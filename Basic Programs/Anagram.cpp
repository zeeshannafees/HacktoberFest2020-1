#include <bits/stdc++.h>
using namespace std;
 
#define NO_OF_CHARS 256 

bool isAnagram(string s1,string s2){
    if(s1.length()!=s2.length())
        return false;
        
    int count[NO_OF_CHARS]={0};
    int i=0;
    for(i=0;s1[i]&&s2[i];i++){
        count[s1[i]]++;
        count[s2[i]]--;
    }
  
    
    for (i = 0; i < NO_OF_CHARS; i++) 
        if (count[i]) 
            return false; 
    return true;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    string c, d;
        cin >> c >> d;
	    if(isAnagram(c,d)){
	        cout<<"YES";
	    }
	    else{
	        cout<<"NO";
	    }
	    cout<<endl;
	}
	return 0;
}
