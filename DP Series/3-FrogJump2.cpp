// Problem Link: https://atcoder.jp/contests/dp/tasks/dp_b
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int reachBottom_memo(int ind,int k,vector<int> &heights,vector<int> &dp){

    if(ind==0){                 // reached bottom
        return 0;
    }
    if(dp[ind]!=-1){            // already computed for ind stone
        return dp[ind];
    }
    int minCost = INT_MAX;
    for(int i=1;i<=k;i++){

        if(ind-i>=0){           // check if we can jump i stones down
            
            int cost = reachBottom_memo(ind-i,k,heights,dp) + abs(heights[ind]-heights[ind-i]);
            minCost = min(minCost,cost);
        }
        else                    // we cannot jump further
            break;
    }
    return dp[ind]=minCost;    
}

int reachTop_tab(int k, vector<int> &heights){

    int n=heights.size();
    vector<int> dp(n);
    dp[0] = 0;                      // base case in recursion

    for(int i=1;i<n;i++){

        int minCost = INT_MAX;
        for(int j=1;j<=k;j++){
            
            if(i-j>=0){             // can we jump j stones down from i

                // cost for jumping j stones down from ith stone
                int cost = dp[i-j]+abs(heights[i]-heights[i-j]);
                minCost = min(minCost,cost);
            }
            else
                break;
        }
        dp[i] = minCost;
    }

    return dp[n-1];
}
/*
In tabulation, we are only using last k stones cost, for space optimization,
we can use linked list to store and move forward costs of last k stones.
but at worst case k can be n hence, there's less use optimizing dp array
from O(n) to O(k) 
*/
int32_t main() {
    fastio();
    int n,k;
    cin>>n>>k;
    vector<int> heights(n,0),dp(n,-1);
    for(int i=0;i<n;i++)    cin>>heights[i];

    // cout<<reachBottom_memo(n-1,k,heights,dp);
    cout<<reachTop_tab(k,heights);
    return 0;
}
/*
Output:
10 4
40 10 20 70 80 10 20 70 80 60
40
*/