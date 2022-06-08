// Problem Link: https://bit.ly/3rN7GIL
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
// buy once and sell once and get max profit
// you can't sell without buying

int maxProfit(vector<int> &prices){

    int min_price = prices[0];    // keep track of min price to buy

    int max_profit = 0;           // don't buy or buy and sell on same day

    for(int i=1;i<prices.size();i++){

        // sell on current day with min price upto previous day
        int profit = prices[i] - min_price;

        max_profit = max(max_profit,profit);      // store the max profit

        min_price = min(min_price,prices[i]);   // update min price to buy
    }

    return max_profit;
}
int32_t main() {
    fastio();
    
    int n;
    cin>>n;
    vector<int> prices(n,0);
    for(int i=0;i<n;i++)
        cin>>prices[i];
    
    cout<<maxProfit(prices);
    return 0;
}
/*
Output:
4
1 2 3 4
3
*/