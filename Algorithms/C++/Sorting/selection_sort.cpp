#include<iostream>
using namespace std;

void selectionSort(int a[],int n){
    for (int i = 0; i < n-1; i++) //-this for loop is for 'passes'
    { 
        int min = i; //- considering the first element in array as minimum 

        for (int j = i+1; j < n; j++) //-this will compare that element with others to find minimum element(searching!)
        {
            if(a[j] < a[min]){
                min = j;  //-updating min element
            }
        }
        if(min!=i){
            //-swapping
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }        
    }

    //-printing the sorted array
    cout<<"Sorted array: \n";
    for (int i = 0; i < n; i++)
    {
        cout<<"["<<a[i]<<"]"<<" ";
    }    
}

int main()
{
    int arr[] = {4,5,7,98,23,723,88};
    int size = sizeof(arr)/sizeof(int);
    selectionSort(arr,size);
    return 0;
}

//  Best case : O(n^2)
//  Worst case : O(n^2)
