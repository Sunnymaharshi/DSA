#include<iostream>
using namespace std;
int recursiveBinarySearch(int low, int high, int arr[], int key){

    if(high < low)
        return -1;
    int mid = low + (high - low)/2 ;    // to avoid overflow
    if(arr[mid]==key)
        return mid;
    if(arr[mid]<key)
        return recursiveBinarySearch(mid+1, high, arr, key); // search on right half

    return recursiveBinarySearch(low, mid-1, arr, key);      // search on left half

}
int main() {

    int n,key;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)  // enter sorted array
        cin>>arr[i];           
    cout<<"enter key:";
    cin>>key;
    cout<<"index:"<<recursiveBinarySearch(0, n-1, arr, key);
    return 0;
}
/*
Output:
5
1 2 3 40 60
enter key:60
index:4
*/