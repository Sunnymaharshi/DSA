// Problem Link: https://bit.ly/3tZsYWA
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
// we can buy and sell any no of times, can't buy next day of sell
// we can't sell without buy, we can't buy without selling bought stocks. 
// buying and selling must be in alternative sequence.

int maxProfit_memo(int ind,int buy,vector<int> &prices,int n,vector<vector<int>> &dp){

    // >= as we've ind+2
    if(ind >=n )             // all days are over, can't buy or sell
        return 0;
    
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];

    // can Buy
    if(buy){                

        // 1.buy on current day, buying price must be subtracted from profit
        // make buy false, to sell in next day.

        // 2.do not buy on current day, keey buy as true to buy in next day.
        return dp[ind][buy]  = max(
            -prices[ind] + maxProfit_memo(ind+1,0,prices,n,dp),
            maxProfit_memo(ind+1,1,prices,n,dp)
            );       
        
    }
    // can Sell

    // 1.sell on current day, selling price must be added to profit
    // make buy as true, to buy in next day.
    // ind+2 as we can't buy next day of sell

    // 2.do not sell on current day, keey buy as false to sell in next day.
    return dp[ind][buy] = max(
        prices[ind] + maxProfit_memo(ind+2,1,prices,n,dp),
        maxProfit_memo(ind+1,0,prices,n,dp)
        );    
    
    
}
int maxProfit_tabu(int n,vector<int> &prices){

    // n+2 as we've ind+2
    vector<vector<int>> dp(n+2,vector<int>(2,0));

    // Base case in memoization
    dp[n][0] = dp[n][1] = 0;

    for(int ind=n-1;ind>=0;ind--){

        // either we buy on this day or don't buy
               
        dp[ind][1] = max(-prices[ind] + dp[ind+1][0],dp[ind+1][1]);
            
        // either we sell on this day or don't sell
        // ind+2 as we can't buy next day of sell

        dp[ind][0] = max(prices[ind] + dp[ind+2][1],dp[ind+1][0]);
          
    }

    return dp[0][1];
}

int maxProfit_space_op(int n,vector<int> &prices){

    // as we're only using last 2 indexes
    vector<int> front2(2,0);
    vector<int> front1(2,0);
    vector<int> current(2,0);

    for(int ind=n-1;ind>=0;ind--){

        // either we buy on this day or don't buy
               
        current[1] = max(-prices[ind] + front1[0],front1[1]);
            
        // either we sell on this day or don't sell
        // ind+2 as we can't buy next day of sell

        current[0] = max(prices[ind] + front2[1],front1[0]);
        
        front2 = front1;
        front1 = current;
    }

    return current[1];
}
int32_t main() {
    fastio();

    int n;
    cin>>n;
    vector<int> prices(n,0);
    for(int i=0;i<n;i++)
        cin>>prices[i];
    // vector<vector<int>> dp(n,vector<int>(2,-1));
    // cout<<maxProfit_memo(0,1,prices,n,dp);
    // cout<<maxProfit_tabu(n,prices);
    cout<<maxProfit_space_op(n,prices);
    return 0;
}
/*
Output:
5
1 2 3 0 2
3
*/