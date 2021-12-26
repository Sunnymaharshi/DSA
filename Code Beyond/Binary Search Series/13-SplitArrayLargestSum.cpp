/*
minimum max sum is max(arr) when we split array to n(size) arrays
maximum max sum is sum(arr) when we split array to 1 subarray
range max(arr) to sum(arr)
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool SubArraysWithLimit(int arr[], int n, int limit, int m){
    int count=1,sum=0;
    for(int i=0; i<n; i++){
        
        if(arr[i]>limit)    return false;   // cannot include arr[i], limit is not possible

        if(sum + arr[i]<=limit)             // add to subarray
            sum += arr[i];
        else{           
            count++;                        // increase subarray count
            sum = arr[i];                   // track new subarray sum
        }
    }
    return count<=m;

}
int minMaxSumSubArray(int arr[], int n, int m){
    int low=*max_element(arr,arr+n), high=0;
    for(int i=0;i<n;i++){
        high += arr[i];
    }
    int ans = high;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(SubArraysWithLimit(arr,n,mid,m)){
            ans = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return ans;

}
int main() {

    int n,m;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>m;
    cout<<"min of max sum:"<<minMaxSumSubArray(arr,n,m);

    return 0;
}
/*
Output:
5
7 2 5 10 8
2
min of max sum:18
*/