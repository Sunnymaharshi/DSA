/*
lower bound points to first element that is >= key
upper bound points to first element that is > key
*/
#include<iostream>
using namespace std;

int lowerBound(int arr[], int n, int key){
    int low=0,high=n-1,ans=n;
    while(low<=high){
        int mid = low + (high -low)/2;
        if(arr[mid]>=key){
            ans=mid;        // store index
            high = mid-1;   // search on left half
        }
        else
            low  = mid+1;   // search on right half
    }
    return ans;
}
int upperBound(int arr[], int n, int key){
    int low=0,high=n-1,ans=n;
    while(low<=high){
        int mid = low + (high -low)/2;
        if(arr[mid]>key){
            ans=mid;        // store index
            high = mid-1;   // search on left half
        }
        else
            low  = mid+1;   // search on right half
    }
    return ans;
}
int main() {


    int n,key;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)  // enter sorted array
        cin>>arr[i];        
    
    cout<<"enter key:";
    cin>>key;
    cout<<"lower bound:"<<lowerBound(arr,n,key);
    cout<<"\nupper bound:"<<upperBound(arr,n,key);

    return 0;
}
/*
5
1 2 6 9 12
enter key:6
lower bound:2
upper bound:3
*/