// Problem Link: https://bit.ly/3q5rlUY
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int maxSumNonAdjs_memo(int ind,vector<int> &nums,vector<int> &dp){

    if(ind==0){          
        // if we come to ind=0 when we didn't took nums[1],
        // we can definitely pick nums[0] to maximize the sum
        return nums[ind];
    }
    if(ind<0){          
        // if previous ind is 1 we go to 1-2=>-1
        // number at index -1 doesn't exist, we don't pick any number
        return 0;
    }
    if(dp[ind]!=-1){        // already computed 
        return dp[ind];
    }

    // if we pick number at ind we can't take it's adjacent number
    // move to ind-2
    int pick = nums[ind] + maxSumNonAdjs_memo(ind-2,nums,dp); 
    // since we're not picking nums[ind], we can pick it's adjacent number
    // move to ind-1
    int notPick = maxSumNonAdjs_memo(ind-1,nums,dp);

    return dp[ind] = max(pick,notPick);      

}
int maxSumNonAdjs_tabu(vector<int> &nums){

    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];            // base case in memoization
    
    for(int i=1;i<n;i++){

        int pick = nums[i];
        if(i>1){                // if i=1, i-2=>-1 which doesn't exist
            
            pick += dp[i-2];    // pick the number before it's adjaent
        }
        int notPick = dp[i-1];  // pick it's adjacent

        dp[i] = max(pick,notPick);
    }


    return dp[n-1];
}

int maxSumNonAdjs_space_op(vector<int> &nums){

    /*
    In tabulation, we are only using dp[i-2] and dp[i-1]
    */
    int n = nums.size();
    int prev1,prev2,pick,notPick,cur;
    prev1 = nums[0];         // dp[0], base case in memoization
    prev2 = 0;               // dp[-1] edge case for negative index if i=1

    for(int i=1;i<n;i++){

        pick = nums[i] + prev2; // take number before it's adjacent
              
        notPick = prev1;        // take it's adjacent number, dp[i-1]

        cur = max(pick,notPick);
        
        // move variable forward
        prev2 = prev1;
        prev1 = cur;
    }

    /*
    at i=n-1 prev1 have max sum of the subsequence considering nums from 0 to n-1
    that no two elements are adjacent 

    even prev1 and cur store same value after an iteration
    there's no guarantee that for loop always executes
    it nums have only one number, control never goes inside loop
    then we can't return cur which is never initialized
    hence with prev1 we can cover this edge case 
    */
    return prev1;      
}
int32_t main() {
    fastio();
    int n;
    cin>>n;
    vector<int> nums(n,0),dp(n,-1);
    for(int i=0;i<n;i++) cin>>nums[i];

    // cout<<maxSumNonAdjs_memo(n-1,nums,dp)<<nl;
    // cout<<maxSumNonAdjs_tabu(nums)<<nl;
    cout<<maxSumNonAdjs_space_op(nums);
    return 0;
}
/*
Output:
4
2 1 4 9
11
*/