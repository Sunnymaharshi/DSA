// Problem Link: https://bit.ly/3nYO17H
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
// we can buy and sell any no of times and fee for 1 transaction 
// we can reduce fee amout either at buy or sell
// we can't sell without buy, we can't buy without selling bought stocks. 
// buying and selling must be in alternative sequence.
int maxProfit_memo(int i,int buy,vector<int> &prices,int n,int fee, vector<vector<int>> &dp){

    if(i==n)             // all days are over, can't buy or sell
        return 0;
    
    if(dp[i][buy]!=-1)
        return dp[i][buy];

    
    // can Buy
    if(buy){                // either we buy on this day or don't buy

        // 1.buy on current day, buying price must be subtracted from profit
        // make buy false, to sell in next day.

        // 2.do not buy on current day, keey buy as true to buy in next day.
        return dp[i][buy] = max(-prices[i] + maxProfit_memo(i+1,0,prices,n,fee,dp),
                        maxProfit_memo(i+1,1,prices,n,fee,dp));       
        
    }

    // can Sell
    // 1.sell on current day, selling price must be added to profit 
    // and reduce fee amout
    // make buy as true, to buy in next day

    // 2.do not sell on current day, keey buy as false to sell in next day.
    return dp[i][buy] = max(
            -fee + prices[i] + maxProfit_memo(i+1,1,prices,n,fee,dp),
            maxProfit_memo(i+1,0,prices,n,fee,dp)
            );
}


int maxProfit_tabu(int n,vector<int> &prices, int fee){

    vector<vector<int>> dp(n+1,vector<int>(2,0));

    // Base case in memoization
    dp[n][0] = dp[n][1] = 0;

    for(int ind=n-1;ind>=0;ind--){

        for(int buy=0;buy<=1;buy++){


            if(buy){                // either we buy on this day or don't buy
               
                dp[ind][buy] = max(-prices[ind] + dp[ind+1][0],dp[ind+1][1]);
            }
            else{                   // either we sell on this day or don't sell
      
                dp[ind][buy] = max(-fee + prices[ind] + dp[ind+1][1],dp[ind+1][0]);
            }            
        }
    }

    return dp[0][1];
}
int maxProfit_space_op1(int n,vector<int> &prices, int fee){

    // In tabulation, we're just using just next index values to 
    // find values of current index
    vector<int> ahead(2,0), cur(2,0);

    // Base case in memoization
    ahead[0] = ahead[1] = 0;

    for(int ind=n-1;ind>=0;ind--){

        for(int buy=0;buy<=1;buy++){

            int profit  = 0;

            if(buy){                // either we buy on this day or don't buy
               
                profit = max(-prices[ind] + ahead[0],ahead[1]); 
            }
            else{                   // either we sell on this day or don't sell
      
                profit = max(-fee + prices[ind] + ahead[1],ahead[0]);     
            }

            cur[buy] = profit;
        }

        // make ahead as cur, as we're going from last to first index
        ahead = cur;        
    }

    return ahead[1];
}

int maxProfit_space_op2(int n,vector<int> &prices, int fee){

    // Instead of using 2 2d arrays, we use four variables
    // and omit inner loop
    int curBuy,curNotBuy, aheadBuy, aheadNotBuy;


    // Base case in memoization
    aheadBuy = aheadNotBuy = 0;

    for(int ind=n-1;ind>=0;ind--){

        // max of sell and not sell
        curNotBuy = max(-fee + prices[ind] + aheadBuy,aheadNotBuy);         
        
        // max of buy and not buy
        curBuy = max(-prices[ind] + aheadNotBuy,aheadBuy);

        aheadBuy = curBuy;
        aheadNotBuy = curNotBuy;
    }

    return aheadBuy;
}
int32_t main() {
    fastio();

    int n,fee;
    cin>>n>>fee;
    vector<int> prices(n,0);
    for(int i=0;i<n;i++)
        cin>>prices[i];
    // vector<vector<int>> dp(n,vector<int>(2,-1));
    // cout<<maxProfit_memo(0,1,prices,n,fee,dp);
    // cout<<maxProfit_tabu(n,prices,fee);
    // cout<<maxProfit_space_op1(n,prices,fee);
    cout<<maxProfit_space_op2(n,prices,fee);
    return 0;
}
/*
Output:
4 2
1 3 5 6
3
*/