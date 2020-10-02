//program to find the sum of digits

#include <iostream>  
using namespace std;  
int main()  
{  
    int number,sum=0,remainder;    
    cout<<"Enter a number: ";    
    cin>>number;    
    while(number>0)    
    {   
        //getting digits from right to left
        remainder = number % 10; 

        // adding the above remainder 
        sum = sum + remainder; 

        //here we're reducing the number    
        number = number / 10;    
    }    
    cout<<"Sum is= "<<sum<<endl;    
return 0;  
}  
