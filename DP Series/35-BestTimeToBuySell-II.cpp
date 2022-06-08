// Problem Link: https://bit.ly/3nYO17H
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
// we can buy and sell any no of times
// we can't sell without buy, we can't buy without selling bought stocks. 
// buying and selling must be in alternative sequence.
long maxProfit_memo(int i,int buy,long *prices,int n,vector<vector<long>> &dp){

    if(i==n)             // all days are over, can't buy or sell
        return 0;
    
    if(dp[i][buy]!=-1)
        return dp[i][buy];

    long profit  = 0L;

    if(buy){                // either we buy on this day or don't buy

        // 1.buy on current day, buying price must be subtracted from profit
        // make buy false, to sell in next day.

        // 2.do not buy on current day, keey buy as true to buy in next day.
        profit = max(-prices[i] + maxProfit_memo(i+1,0,prices,n,dp),
                        maxProfit_memo(i+1,1,prices,n,dp));       
        
    }
    else{                   // either we sell on this day or don't sell

        // 1.sell on current day, selling price must be added to profit
        // make buy as true, to buy in next day.

        // 2.do not sell on current day, keey buy as false to sell in next day.
        profit = max(prices[i] + maxProfit_memo(i+1,1,prices,n,dp),
                        maxProfit_memo(i+1,0,prices,n,dp));
    }
    
    return dp[i][buy] = profit;
}
long maxProfit_tabu(int n,long *prices){

    vector<vector<long>> dp(n+1,vector<long>(2,0L));

    // Base case in memoization
    dp[n][0] = dp[n][1] = 0L;

    for(int ind=n-1;ind>=0;ind--){

        for(int buy=0;buy<=1;buy++){

            long profit  = 0L;

            if(buy){                // either we buy on this day or don't buy
               
                profit = max(-prices[ind] + dp[ind+1][0],dp[ind+1][1]);
            }
            else{                   // either we sell on this day or don't sell
      
                profit = max(prices[ind] + dp[ind+1][1],dp[ind+1][0]);
            }

            dp[ind][buy] = profit;
        }
    }

    return dp[0][1];
}
long maxProfit_space_op1(int n,long *prices){

    // In tabulation, we're just using just next index values to 
    // find values of current index
    vector<long> ahead(2,0L), cur(2,0L);

    // Base case in memoization
    ahead[0] = ahead[1] = 0L;

    for(int ind=n-1;ind>=0;ind--){

        for(int buy=0;buy<=1;buy++){

            long profit  = 0L;

            if(buy){                // either we buy on this day or don't buy
               
                profit = max(-prices[ind] + ahead[0],ahead[1]); 
            }
            else{                   // either we sell on this day or don't sell
      
                profit = max(prices[ind] + ahead[1],ahead[0]);     
            }

            cur[buy] = profit;
        }

        // make ahead as cur, as we're going from last to first index
        ahead = cur;        
    }

    return ahead[1];
}
long maxProfit_space_op2(int n,long *prices){

    // Instead of using 2 2d arrays, we use four variables
    // and omit inner loop
    long curBuy,curNotBuy, aheadBuy, aheadNotBuy;


    // Base case in memoization
    aheadBuy = aheadNotBuy = 0L;

    for(int ind=n-1;ind>=0;ind--){

        // max of sell and not sell
        curNotBuy = max(prices[ind] + aheadBuy,aheadNotBuy);         
        
        // max of buy and not buy
        curBuy = max(-prices[ind] + aheadNotBuy,aheadBuy);

        aheadBuy = curBuy;
        aheadNotBuy = curNotBuy;
    }

    return aheadBuy;
}
int32_t main() {
    fastio();

    int n;
    cin>>n;
    long prices[n];
    for(int i=0;i<n;i++)
        cin>>prices[i];
    // vector<vector<long>> dp(n,vector<long>(2,-1));
    // cout<<maxProfit_memo(0,1,prices,n,dp);
    // cout<<maxProfit_tabu(n,prices);
    // cout<<maxProfit_space_op1(n,prices);
    cout<<maxProfit_space_op2(n,prices);
    return 0;
}
/*
Output:
7
1 2 3 4 5 6 7
6
*/