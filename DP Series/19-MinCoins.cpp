// Problem Link: https://bit.ly/3HJTeIl
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int minCoins_memo(int i,int target,vector<int> &coins,vector<vector<int>> &dp){

    if(i==0){                   // final coin

        if(target%coins[i]==0)          // if target is multiple of this coin
            // since it is final coin we can take multiple coins at once
            return target/coins[i];    
        else
            return (int)1e9;    // large value to ignore this choice
    }

    if(dp[i][target]!=-1)       // already computed
        return dp[i][target];
        
    int notTake = minCoins_memo(i-1,target,coins,dp);
    int take = INT_MAX;

    if(coins[i]<=target){        // we cannot take coin whose value > target

        /*
            1 for coin count and reduce the target
            we stay at same index since we can take coins any no of times.
            here target is reducing every time we take a coin,
            this cannot be called when coin > target
            take and notTake choices checks every possible combinations of coins
        */
        take = 1 + minCoins_memo(i,target-coins[i],coins,dp);
    }    

    return dp[i][target] = min(take,notTake);
}

int minCoins_tabu(int n,int target,vector<int> &coins){

    vector<vector<int>> dp(n,vector<int>(target+1,0));

    //  base cases as in memoization
    // for all possible values of target for final coin
    for(int t=0;t<=target;t++){         

        if(t%coins[0]==0)
            dp[0][t] = t/coins[0];
        else
            dp[0][t] = (int)1e9;
    }

    for(int i = 1;i<n;i++){

        for(int t=0;t<=target;t++){

            int notTake = dp[i-1][t];
            int take = INT_MAX;

            if(coins[i]<=t){        // we cannot take coin whose value > t
                // we stay at same index since we can take coins any no of times.
                take = 1 + dp[i][t-coins[i]];
            }

            dp[i][t] = min(take,notTake);

        }
    }
    
    // min coins whose sum is target considering 0 to n-1th index coins
    return dp[n-1][target];
}
int minCoins_space_op(int n,int target,vector<int> &coins){

    // In tabulation, we're just using previous coin values to find current coin values
    vector<int> prev(target+1,0),cur(target+1,0);


    //  base cases as in memoization
    // for all possible values of target for final coin
    for(int t=0;t<=target;t++){         

        if(t%coins[0]==0)
            prev[t] = t/coins[0];
        else
            prev[t] = (int)1e9;
    }

    for(int i = 1;i<n;i++){

        for(int t=0;t<=target;t++){

            int notTake = prev[t];
            int take = INT_MAX;

            if(coins[i]<=t){        // we cannot take coin whose value > t
                // we stay at same index since we can take coins any no of times.
                take = 1 + cur[t-coins[i]];
            }

            cur[t] = min(take,notTake);

        }

        prev = cur;                 // make current coin as previous coin
    }
    
    // min coins whose sum is target considering 0 to n-1th index coins
    return prev[target];
}
int32_t main() {
    fastio();

    int n,target,ans;
    cin>>n>>target;
    vector<int> coins(n);
    for(int i=0;i<n;i++)
        cin>>coins[i];

    // vector<vector<int>> dp(n,vector<int>(target+1,-1));
    // ans = minCoins_memo(n-1,target,coins,dp);
    // ans  = minCoins_tabu(n,target,coins);
    ans = minCoins_space_op(n,target,coins);
    if(ans>=1e9)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}
/*
Output:
3 7
1 2 3
3
*/