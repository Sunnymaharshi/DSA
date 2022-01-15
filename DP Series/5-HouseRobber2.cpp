// Problem Link: https://bit.ly/3F6q83P
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

// function of 4th problem
int maxSumNonAdjs_space_op(vector<int> &nums){

    
    int n = nums.size();
    long long prev1,prev2,pick,notPick,cur;
    prev1 = nums[0];         // dp[0], base case in memoization
    prev2 = 0LL;               // dp[-1] edge case for negative index if i=1

    for(int i=1;i<n;i++){

        pick = nums[i] + prev2;
               
        notPick = prev1;        // take it's adjacent number, dp[i-1]

        cur = max(pick,notPick);
        
        // move variable forward
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;      
}
int32_t main() {
    fastio();

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)        cin>>arr[i];

    if(n==1)	
        cout<<arr[0];
    else{
        /*
        since all houses along this street are arranged in a circle
        first house is the neighbor of the last one.
        we can not target both first and last house 
        we take either first or last house, then find max subsequence sum
        using previous problem logic
        */

        vector<int> arr1,arr2;
        for(int i=0;i<n;i++){
            if(i!=0){
                arr2.push_back(arr[i]);
            }
            if(i!=n-1){
                arr1.push_back(arr[i]);
            }
        }
        // arr1 without last house and arr2 without first house
        int maxCost1,maxCost2;
        maxCost1 = maxSumNonAdjs_space_op(arr1);
        maxCost2 = maxSumNonAdjs_space_op(arr2);
        cout<<max(maxCost1,maxCost2);    
    }
    return 0;
}
/*
Output:
5
1 5 1 2 6
11
*/