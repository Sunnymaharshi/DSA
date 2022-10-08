// Problem Link: https://bit.ly/3rLHkqQ
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
// we can buy and sell atmost 2 times
// we can't sell without buy, we can't buy without selling bought stocks. 
// buying and selling must be in alternative sequence


int maxProfit_memo(int ind,int buy,int times,vector<int> &prices,int n,
                    vector<vector<vector<int>>> &dp){

    if(ind == n || times == 0)      // out of days or chances
        return 0;

    if(dp[ind][buy][times]!=-1)     
        return dp[ind][buy][times];
    
    if(buy == 1){                   // can buy
                                    // max of buy and not buy
        return dp[ind][buy][times] = max( 
            -prices[ind] + maxProfit_memo(ind+1,0,times,prices,n,dp),
            maxProfit_memo(ind+1,1,times,prices,n,dp)
            );
    }

    // can sell
    // max of sell and not sell
    return dp[ind][buy][times] = max(
            prices[ind] + maxProfit_memo(ind+1,1,times-1,prices,n,dp),
            maxProfit_memo(ind+1,0,times,prices,n,dp)
        );
    

}

int maxProfit_tabu(vector<int> &prices, int n){

    // NxBUYxTIMES variable parameters in memo
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2, vector<int>(3,0)));
    // Base case ind == n || times == 0 return 0
    // already initialized with 0s

    for(int ind=n-1;ind>=0;ind--){

        for(int buy=0; buy<=1; buy++){
            // ignored times for 0 as  every value is 0 only
            for(int times=1; times<=2;times++){
                
                // can buy
                // max of buy and not buy
                if(buy == 1){                                     
                
                    dp[ind][buy][times] = max( 
                        -prices[ind] + dp[ind+1][0][times],
                        dp[ind+1][1][times]
                        );
                }

                // can sell
                // max of sell and not sell
                else {
                    dp[ind][buy][times] = max(
                            prices[ind] + dp[ind+1][1][times-1],
                            dp[ind+1][0][times]
                        );
                }

            }
        }
    } 

    return dp[0][1][2];
}
int maxProfit_tabu_op(vector<int> &prices, int n){

    // we're only using ind+1 values
    vector<vector<int>> next(2,vector<int>(3,0));
    vector<vector<int>> current(2,vector<int>(3,0));
    // Base case ind == n || times == 0 return 0
    // already initialized with 0s

    for(int ind=n-1;ind>=0;ind--){

        for(int buy=0; buy<=1; buy++){
            // ignored times for 0 as  every value is 0 only
            for(int times=1; times<=2;times++){
                
                // can buy
                // max of buy and not buy
                if(buy == 1){                                     
                
                    current[buy][times] = max( 
                        -prices[ind] + next[0][times],
                        next[1][times]
                        );
                }

                // can sell
                // max of sell and not sell
                else {
                    current[buy][times] = max(
                            prices[ind] + next[1][times-1],
                            next[0][times]
                        );
                }

            }
        }
        next = current;
    } 

    return current[1][2];
}

int main() {
    fastio();

    int n;
    cin>>n;
    vector<int> prices(n,0);
    for(int i=0;i<n;i++)
        cin>>prices[i];
    
    // vector<vector<vector<int>>> dp(n,vector<vector<int>> (2, vector<int>(3,-1)));
    // cout<<maxProfit_memo(0,1,2,prices,n,dp);
    // cout<<maxProfit_tabu(prices,n);
    cout<<maxProfit_tabu_op(prices,n);

}

/*
Output:
7
3 3 5 0 3 1 4
6
*/