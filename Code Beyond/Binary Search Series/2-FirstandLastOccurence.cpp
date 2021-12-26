#include<iostream>
using namespace std;
int firstOccurence(int arr[], int n, int key){
    int index=-1, low=0,high=n-1;
    while(low <= high){

        int mid = low + (high - low)/2; // to avoid overflow
        if(arr[mid]==key){
            index = mid;    // store the index
            high = mid-1;   // search on left half
        }
        else if(arr[mid] < key)
            low = mid+1;         // search on right half
        else
            high = mid-1;        // search on left half
    }
    return index;
}
int lastOccurence(int arr[], int n, int key){
    int index=-1, low=0,high=n-1;
    while(low <= high){

        int mid = low + (high - low)/2; // to avoid overflow
        if(arr[mid]==key){
            index = mid;     // store the index
            low = mid + 1;   // search on right half
        }
        else if(arr[mid] < key)
            low = mid+1;     // search on right half
        else
            high = mid-1;    // search on left half
    }
    return index;
}
int main() {

    int n,key;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)  // enter sorted array
        cin>>arr[i];        
    
    cout<<"enter key:";
    cin>>key;
    cout<<"index of first occurence of "<<key<<": "<<firstOccurence(arr,n,key);
    cout<<"\nindex of last occurence of "<<key<<": "<<lastOccurence(arr,n,key);

    return 0;
}
/*
Output:
5
1 3 3 3 5
enter key:3
index of first occurence of 3: 1
index of last occurence of 3: 3
*/