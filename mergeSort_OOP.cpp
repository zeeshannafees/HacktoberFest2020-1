//  Desc.:  Program for merge-sort algorithm (OOP concepts included).
//  Author: Dishant Vyas
//  Date:   07/10/2020



#include <iostream>
using namespace std;


template <typename dt>                                              // Template applied.
class mergeSort {
private:                                                            // Variables initialised.
    dt arr[10000];
    dt ans[10000];
    int size = 0;

public:    
    void sort() {                                                   // Function to initialise quick-sort.
        merge_sort(1,size);
    }

    void fillArray(int i, dt value) {                               // Function to get array from input.
        arr[i] = value;
        size++;
    }

    void merge(int p, int r, int q) {                               // Function for merging sorted sub-arrays.
        int ptr = p;
        int ptr1 = p;
        int ptr2 = r+1;
        
        while(ptr1<=r && ptr2<=q) {                                 // Least element selected from the sub-arrays and added to resultant array.
            if(arr[ptr2]<arr[ptr1]) {
                ans[ptr] = arr[ptr2];
                ptr2++;
            }
            else {
                ans[ptr] = arr[ptr1];
                ptr1++;
            }
            ptr++;
        }
        
        while(ptr<=q) {                                             // Elements copied from non-empty sub-array to the resultant array.
            if(ptr1<=r) {
                ans[ptr] = arr[ptr1];
                ptr1++;
            }
            else {
                ans[ptr] = arr[ptr2];
                ptr2++;
            }
            ptr++;
        }
        for (int i=p; i<ptr; i++)                                   // Original array updated.
            arr[i] = ans[i];
    }

    void merge_sort(int p, int q) {                                 // Recursive function to apply merge-sort algorithm.
        if(q<=p) 
            return;
        int r = (p+q)/2;
        merge_sort(p, r);
        merge_sort(r+1, q);
        merge(p, r, q);
    }

    void dispArray() {                                              // Function to display array.
        for(int i=1 ; i<=size ; i++)
            cout << ans[i] << " ";
    }
};


int main() {
    mergeSort<double> obj;
    int n;
    double temp;
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        cin >> temp;
        obj.fillArray(i, temp);
    }
    obj.sort();
    obj.dispArray();
    return 0;
}