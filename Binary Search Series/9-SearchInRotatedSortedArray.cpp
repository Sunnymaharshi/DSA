// atleast 1 side of mid will be definitely sorted
#include<iostream>
using namespace std;
int findkey(int arr[], int n, int key){
    int low=0,high=n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==key)
            return mid;
        
        if(arr[low] <= arr[mid]){     // left part is sorted

            if(key >= arr[low] && key <= arr[mid])      // key lies inside left part
                high = mid-1;                           // search left part
            else
                low = mid+1;                            // search right part

        }
        else{                        // right part is sorted

            if(key >= arr[mid] && key <= arr[high])     // key lies in right part
                low = mid+1;                            // search in right part
            else
                high = mid-1;                           // search in left part

        }
    }
    return -1;
}

int main() {

    int n,key;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)  // enter rotated sorted array
        cin>>arr[i];        
    cout<<"enter a key:";
    cin>>key;
    cout<<"index of "<<key<<" is:";
    cout<<findkey(arr,n,key);
    return 0;


return 0;
}
/*
Output:
6
10 13 20 5 6 9
enter a key:9
index of 9 is:5
*/