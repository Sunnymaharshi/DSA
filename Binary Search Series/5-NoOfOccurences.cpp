#include<iostream>
#include<algorithm>
using namespace std;
/*
lower bound points to first element that is >= key
upper bound points to first element that is > key
these functions are implemented using binary search in other file.
*/
int main() {
    int n,key;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)  // enter sorted array
        cin>>arr[i];        
    
    cout<<"enter key:";
    cin>>key;
    // c++ inbuilt functions
    int count = upper_bound(arr, arr+n, key) - lower_bound(arr,arr+n,key);
    /*
    same output will come with 
    lastOccurence(key) - firstOccurence(key) +1
    */
    cout<<"no of occurences of "<<key<<":"<<count;
    return 0;
}
/*
Output:
5
1 2 3 3 3
enter key:3
no of occurences of 3:3
*/