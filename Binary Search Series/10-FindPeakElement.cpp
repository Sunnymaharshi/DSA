/*
if arr[mid]>arr[mid+1] there will always a peak in left part
vice versa
*/
#include<iostream>
using namespace std;

int findPeak(int arr[], int n){

    int low =0, high=n-1;
    while(low<high){
        int mid = low + (high - low)/2;
        if(arr[mid] > arr[mid+1])           // mid element might be the peak
            high = mid;             // search in left part including mid
        else
            low = mid+1;            // search in right part excluding mid

    }
    return arr[low];
}
int main() {

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"peak element:"<<findPeak(arr,n);

    return 0;
}
/*
5
1 2 3 5 6
peak element:6
*/






