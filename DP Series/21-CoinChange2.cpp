// Problem Link: https://bit.ly/33Kd8o2
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

long countWays_memo(int i, int target, int *coins,vector<vector<long>> &dp){

    if(i==0){                       // reached final coin
        // as it is the final coin we can take multiple coins at once
        // target is multiple of coin, we can reach target.
        return target%coins[i]==0;    
    }


    if(dp[i][target]!=-1)                               // already computed
        return dp[i][target];

    long notTake = countWays_memo(i-1,target,coins,dp);       // move to next coins
    long take = 0L;
    if(coins[i]<=target){

        // reduce target and stay on same coin as you can take any no of coins
        take = countWays_memo(i,target-coins[i],coins,dp);     
    }

    return dp[i][target] = take + notTake;  
}

long countWays_tabu(int n,int target,int *coins){

    vector<vector<long>> dp(n,vector<long>(target+1,0));
    // base case in memoization
    for(int t=0;t<=target;t++){

        if(t%coins[0]==0)               // if target is multiple of final coin
            dp[0][t] = 1L;
    }

    for(int i=1;i<n;i++){

        for(int t=0;t<=target;t++){

            long notTake = dp[i-1][t]; 
            long take = 0L;
            if(coins[i]<=t){

                // reduce target and stay on same coin as you can take any no of coins
                take = dp[i][t-coins[i]];     
            }

            dp[i][t] = take + notTake; 
        }
    }

    // no of ways to get target by considering coins from 0th to (n-1)th index of coins
    return dp[n-1][target];  
}

long countWays_space_op(int n,int target,int *coins){

    // In tabulation, we're just using prev coin values to find values for current coin
    vector<long> cur(target+1,0L),prev(target+1,0L);
    // base case in memoization
    for(int t=0;t<=target;t++){

        if(t%coins[0]==0)               // if target is multiple of final coin
            prev[t] = 1L;
    }

    for(int i=1;i<n;i++){

        for(int t=0;t<=target;t++){

            long notTake = prev[t]; 
            long take = 0L;
            if(coins[i]<=t){

                // reduce target and stay on same coin as you can take any no of coins
                take = cur[t-coins[i]];     
            }

            cur[t] = take + notTake; 
        }

        prev = cur;             // make current coin as previous coin
    }

    // no of ways to get target by considering coins from 0th to (n-1)th index of coins
    return prev[target];
}
int32_t main() {
    fastio();
    int n,target;
    cin>>n;
    int coins[n];
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    cin>>target;

    // vector<vector<long>> dp(n,vector<long>(target+1,-1));
    // cout<<countWays_memo(n-1,target,coins,dp);
    // cout<<countWays_tabu(n,target,coins);
    cout<<countWays_space_op(n,target,coins);
    return 0;
}
/*
Output:
3
1 2 3
4
4
*/