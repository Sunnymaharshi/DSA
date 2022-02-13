// Problem Link: https://bit.ly/3B5JBkU
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int countSubsetsSumK_memo(int i,int target,vector<int> &arr,vector<vector<int>> &dp){

    if(target==0)           // found subset whose sum is target
        return 1;
    
    if(i==0)                // final element must be our target to get sum as target
        return arr[i]==target;
    
    if(dp[i][target]!=-1)       // already computed
        return dp[i][target];

    int notTake = countSubsetsSumK_memo(i-1,target,arr,dp);
    int take = 0;
    if(arr[i]<=target)                  // check if element is valid
        take = countSubsetsSumK_memo(i-1,target-arr[i],arr,dp);       // reduce the target
        
    return dp[i][target] = take+notTake;        
}

int countSubsetsSumK_tabu(int n,int target,vector<int> &arr){

    vector<vector<int>> dp(n,vector<int>(target+1,0));

    for(int i=0;i<n;i++)            // at any index if target is 0
        dp[i][0] = 1;   

    if(arr[0]<=target)              // final element must be our target to consider it
        dp[0][arr[0]] = 1;
    
    // use base cases to find all values of dp
    for(int i=1;i<n;i++){

        for(int s=1;s<=target;s++){
            
            int notTake = dp[i-1][s];
            int take = 0;
            if(arr[i]<=s)                      // check if element is valid
                take = dp[i-1][s-arr[i]];      // reduce the target
                
            // sub problem : subsets with target s in elements from 0 to ith index
            dp[i][s] = take+notTake;           
        }
    }

    return dp[n-1][target];
}
int countSubsetsSumK_space_op(int n,int target,vector<int> &arr){

    // we're just using previous index values to find current index values
    vector<int> prev(target+1,0),cur(target+1,0);

    prev[0] = 1;                    // for target as 0  

    if(arr[0]<=target)              // final element must be our target to consider it
        prev[arr[0]] = 1;
      
    for(int i=1;i<n;i++){

        cur[0] = 1;                 // for target as 0
        for(int s=1;s<=target;s++){
            
            int notTake = prev[s];
            int take = 0;
            if(arr[i]<=s)                      // check if element is valid
                take = prev[s-arr[i]];      // reduce the target
                
            // sub problem : subsets with target s in elements from 0 to ith index
            cur[s] = take+notTake;           
        }
        prev = cur;                 // make current index as previous index
    }

    return prev[target];
}
int32_t main() {
    fastio();

    int n,k;
    cin>>n>>k;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    // for each index in arr, target value ranges from 0 to k
    // k+1 since it is zero based indexing, we need have index with k also
    // vector<vector<int>> dp(n,vector<int>(k+1,-1));
    // cout<<countSubsetsSumK_memo(n-1,k,arr,dp);
    // cout<<countSubsetsSumK_tabu(n,k,arr);
    cout<<countSubsetsSumK_space_op(n,k,arr);

    return 0;
}
/*
Output:
4 3
1 2 2 3
3
*/