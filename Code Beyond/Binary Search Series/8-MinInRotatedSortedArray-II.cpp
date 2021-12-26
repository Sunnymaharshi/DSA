// array contains duplicates
#include<iostream>
using namespace std;
int findMin2(int arr[], int n){
    int low=0,high=n-1;
    while(low<high){
        int mid = low + (high-low)/2;
        if(arr[mid] < arr[high])    // mid element is smaller
            high = mid;             // mid might be the answer, search on left
        else if(arr[mid] > arr[high])
            low = mid+1;            // mid is not smallest, search on right
        else                        
            high--;                 // high is definitely not min
    }
    return arr[low];
}

int main() {

    int n,key;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)  // enter rotated sorted array
        cin>>arr[i];        
    
    cout<<"min element is:";
    cout<<findMin2(arr,n);
    return 0;


return 0;
}
/*
Output:
5
1 1 0 0 1
min element is:0
*/