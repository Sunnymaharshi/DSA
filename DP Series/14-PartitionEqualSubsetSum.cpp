// Problem Link: https://bit.ly/34iIIsH
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

bool subsetSumK_memo(int i,int target,vector<int> &arr,vector<vector<int>> &dp){

    if(target==0)                   // reached the target sum 
        return true;
    
    if(i==0)                        // final element must be our target to get sum as target
        return arr[0]==target;
    
    if(dp[i][target]!=-1)
        return dp[i][target];
    bool notTake = subsetSumK_memo(i-1,target,arr,dp);
    bool take = false;
    if(arr[i]<=target){
        // if element is less or equal to target, we can take it into our subset
        take = subsetSumK_memo(i-1,target-arr[i],arr,dp);        // reduce the target
    }

    // either of these true, we found subset with target as sum
    return dp[i][target] = notTake || take;    
}

bool subsetSumK_tabu(int n,int k,vector<int> &arr){

    // for each index in arr, target value ranges from 0 to k
    // k+1 since it is zero based indexing, we need have index with k also
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    // base cases in memoization
    for(int i=0;i<n;i++)            // for any index if target is 0
        dp[i][0] = true;
    
    if(arr[0]<=k)           // final element must be less than target to consider it
        dp[0][arr[0]] = true;           

    for(int i=1;i<n;i++){

        for(int target=1;target<=k;target++){

            bool notTake = dp[i-1][target];
            bool take = false;
            if(arr[i]<=target){
                take = dp[i-1][target-arr[i]];     // reduce the target
            }

            // either of these true, we found subset with target as sum
            dp[i][target] = notTake || take;   

        }
    }

    return dp[n-1][k];          // subsets from n-1 to 0 index with sum k

}
bool subsetSumK_space_op(int n,int k,vector<int> &arr){

    // we're just using values of previous index to compute values of current index
    vector<bool> prev(k+1,0),cur(k+1,0);

    // base cases in memoization
    prev[0] = true;                     // for target as 0
     
    if(arr[0]<=k)           // final element must be less than target to consider it
        prev[arr[0]] = true;           

    for(int i=1;i<n;i++){

        cur[0] = true;                          // for target as 0
        for(int target=1;target<=k;target++){

            bool notTake = prev[target];
            bool take = false;
            if(arr[i]<=target){
                take = prev[target-arr[i]];     // reduce the target
            }

            // either of these true, we found subset with target as sum
            cur[target] = notTake || take;   
        }
        prev = cur;                 // make current values as previous
    }

    return prev[k];          // subsets from n-1 to 0 index with sum k

}

int32_t main() {
    fastio();

    int n,s=0;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        s += arr[i];
    }

    if(s%2!=0)                  // can't divide into two equal subsets
        cout<<false;
    else{

        int k =  s/2;
        /*
        if we found a subset with sum as totalsum/2 then other elements sum also
        have same totalsum/2
        */
        // // for each index in arr, target value ranges from 0 to k
        // // k+1 since it is zero based indexing, we need have index with k also
        // vector<vector<int>> dp(n,vector<int>(k+1,-1));
        // cout<<subsetSumK_memo(n-1,k,arr,dp);
        // cout<<subsetSumK_tabu(n,k,arr);
        cout<<subsetSumK_space_op(n,k,arr);

    }
    

    
    return 0;
}
/*
Output:
6
3 1 1 2 2 1
1
*/