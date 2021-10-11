//1. finding all subarrays and find max sum -->TC-O(n^2)
//2. modified kadane's algorithms -handles the case when all elements are negative
#include<iostream>
using namespace std;
int main(){
    int n,cur_max,max_so_far;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cur_max=max_so_far=arr[0];
    for(int i=1;i<n;i++){
        cur_max=max(arr[i],cur_max+arr[i]);
        //intuition is simple -- we check adding previous sum to current element
        //gives max value or not 
        max_so_far=max(max_so_far,cur_max); // update maximum sum
    }
    cout<<"Max subarray sum:"<<max_so_far;
    return 0;
}

/*
Output:
5
-1 -5 -6 -90 -100
Max subarray sum:-1
*/