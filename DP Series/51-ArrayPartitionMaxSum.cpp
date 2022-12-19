// https://www.codingninjas.com/codestudio/problems/maximum-subarray_3755255?leftPanelTab=0
#include<iostream>
#include<vector>
#include<limits.h>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

// make partitions of length atmost k
// In each partition, find max element and replace remaining elements with max element, add them
// add all partitions sum values, find max value of this sum

int maxSumPartitions(int ind, vector<int> &arr,int k, int n, vector<int> &dp){
    
    // no partitions
    if(ind==n) return 0;


    // if already calculated
    if(dp[ind]!=-1) return dp[ind];

    int maxSum = INT_MIN;

    // len of left partition
    int leftPartlen = 0;
    // max element in left partition
    int maxLeft = INT_MIN;

    // we can make partition of length upto length k
    for(int i=ind; i<min(ind + k, n); i++){

        leftPartlen++;
        maxLeft = max(maxLeft, arr[i]);

        int rightPartSum = maxSumPartitions(i+1, arr, k, n, dp);

        int totalSum = maxLeft * leftPartlen + rightPartSum;
        maxSum = max(maxSum, totalSum);
    }

    return dp[ind] = maxSum;
}


int maxSumPartitions_tabu(vector<int> &arr, int k, int n){

    vector<int> dp(n+1,0);

    dp[n] = 0;

    // go from right to left
    for(int i=n-1;i>=0;i--){

        int maxSum = INT_MIN;

        int leftPartlen = 0;
        int maxLeft = INT_MIN;

        for(int j=i;j<min(i+k,n);j++){

            leftPartlen++;
            maxLeft = max(maxLeft, arr[j]);

            int rightPartSum = dp[j+1];

            int totalSum = maxLeft * leftPartlen + rightPartSum;
            maxSum = max(maxSum, totalSum);
        }

        dp[i] = maxSum;
    }

    return dp[0];
}
int main() {
    fastio();

    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    // vector<int> dp(n,-1);
    // cout<<maxSumPartitions(0,arr,k,n,dp);
    cout<<maxSumPartitions_tabu(arr,k,n);

    return 0;    
}

/*
Output:
6 3
1 20 13 4 4 1 
80
*/