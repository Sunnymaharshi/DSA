// Problem Link: https://bit.ly/3JPcoOx
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

// memoization
int reachBottom_memo(int ind, vector<int> &heights, vector<int> &dp){

    if(ind==0){             // reached bottom
        return 0;
    }
    if(dp[ind]!=-1){            // already computed for this stair
        return dp[ind];
    }

    // compute cost and move to the stair.
    int oneJump = reachBottom_memo(ind-1,heights,dp) + abs(heights[ind] - heights[ind-1]);
    int twoJumps = INT_MAX;                 // if ind=1 we can't jump 2 stairs down
    if(ind>1){
        twoJumps = reachBottom_memo(ind-2,heights,dp) + abs(heights[ind] - heights[ind-2]);
    }

    return dp[ind] = min(oneJump,twoJumps);     // store before returning the answer
}

// tabulation
int reachTop_tab(vector<int> &heights){

    int n = heights.size();
    vector<int> dp(n,INT_MAX);
    dp[0] = 0;                  // base case in memoization

    for(int i=1; i<n; i++){

        // same as in memoization but we go bottom to up
        // min cost for previous stairs already stored in dp array
        // at each stair we calculate cost if we jump 1 step down and 2 jumps down
        int oneJump = dp[i-1] + abs(heights[i]-heights[i-1]);     
        int twoJumps = INT_MAX;             // if i=1 we can't jump 2 stairs down
        if(i>1){
            twoJumps = dp[i-2] + abs(heights[i] - heights[i-2]);
        }

        dp[i] = min(oneJump,twoJumps);      // store min cost for ith stair
    }

    return dp[n-1];       // nth stair min cost stored in (n-1)th index in dp
}
int reachTop_space_op(vector<int> &heights){

    int n = heights.size();
    
    // in tabulation for loop we're using only dp[i-1] and dp[i-2]
    int prev1=0,prev2=0,cur;

    for(int i=1; i<n; i++){

        // at each stair we calculate cost if we jump 1 stair down and 2 stairs down
        int oneJump = prev1 + abs(heights[i]-heights[i-1]);     
        int twoJumps = INT_MAX;             // if i=1 we can't jump 2 stairs down
        if(i>1){
            twoJumps = prev2 + abs(heights[i] - heights[i-2]);
        }

        cur = min(oneJump,twoJumps);
        
        // move variables forward
        prev2 = prev1;
        prev1 = cur;
    }

    /* 
    even if prev1 and cur store same value after an iteration
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
    vector<int> heights(n,0),dp(n,-1);
    for(int i=0;i<n;i++)    cin>>heights[i];

    // cout<<reachBottom_memo(n-1,heights,dp);
    // cout<<reachTop_tab(heights);
    cout<<reachTop_space_op(heights);

    return 0;
}
/*
Output:
4
10 20 30 10
20
*/