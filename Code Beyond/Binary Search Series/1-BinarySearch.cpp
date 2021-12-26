#include<iostream>
using namespace std;
int binarySearch(int arr[],int n, int key){
    int low=0,high=n-1,mid;
    while(low <= high){
        
        mid = low + (high-low)/2; // to avoid overflow
        if(arr[mid]==key)
            return mid;           // return index
        else if(arr[mid] < key)
            low = mid+1;          // search on right half
        else
            high = mid-1;         // search on left half
    }
    return -1;                    // if key not found

}
int main() {

    int n,key;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)  // enter sorted array
        cin>>arr[i];        
    
    cout<<"enter key:";
    cin>>key;
    cout<<binarySearch(arr,n,key);
    return 0;
}
/*
Output:
6
3 12 23 53 60 63
enter key:63
5
*/